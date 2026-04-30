//--------------------------------------------------------------------------
/// \file     user_code.c
/// \brief    Boitier BB CAN Renault Trucks
///
///           DO_87  : frein a main (SPN70 = 01 -> serre)
///           DO_X   : vitesse >= seuil (5 km/h ou 10 km/h selon DI_87A)
///           DI_87A : selecteur de seuil (GND = 10 km/h, repos = 5 km/h)
///           DO_87A : non utilise (broche en entree via DI_87A)
///           DO_C   : indicateur d'etat 4 niveaux
///             - Bus silencieux / perdu : 1 flash (500ms ON / 2500ms OFF)
///             - Reception OK           : clignotement 400ms/400ms
///             - SPN en erreur          : allume continu
///             - Bus-Off HW             : eteint
///
/// \platform HCS08DZ / HW_USPS_CAN_4IO_A rev C
/// \note     Mode mixte : config CAN via Eagle (CAN_DB),
///           logique metier en C pur
//--------------------------------------------------------------------------

#include "user_code.h"

//--- Etats DO_C (indicateur) ---------------------------------------------
#define DOC_STATE_BUSOFF    0    // Bus-Off HW          -> eteint
#define DOC_STATE_SILENT    1    // Bus silencieux/perdu -> 1 flash / 3s
#define DOC_STATE_OK        2    // Reception CAN OK     -> 400ms/400ms
#define DOC_STATE_ERROR     3    // SPN erreur/indispo   -> continu

//--- Seuils vitesse (en 1/256 km/h, format interne SPN84) ---------------
//   5 km/h = 5  * 256 = 1280  |  hysteresis bas = 4  km/h = 1024
//  10 km/h = 10 * 256 = 2560  |  hysteresis bas = 9  km/h = 2304
#define SPEED_THR_5KMH_ON    1280
#define SPEED_THR_5KMH_OFF   1024
#define SPEED_THR_10KMH_ON   2560
#define SPEED_THR_10KMH_OFF  2304

//--- Timeout reception CCVS ----------------------------------------------
// BBM emet CCVS toutes les 100ms -> 500ms = 5 trames manquees
#define CCVS_TIMEOUT_MS     500

//--- Etat global ---------------------------------------------------------
static uint8   can_alive      = 0;
static uint8   spn70_raw      = 3;
static uint8   spn84_valid    = 0;
static uint8   parking_brake  = 0;
static uint8   do_x_state     = 0;   // etat courant sortie vitesse

static uint32  hb_timestamp   = 0;
static uint8   hb_state       = 0;
static uint8   hb_phase       = 0;

static uint32  ccvs_last_seen = 0;   // timestamp derniere trame CCVS recue


//-------------------------------------------------------------------------
void usercode_init(void)
{
    os_digout(DO_87,   0);
    os_digout(DO_87A,  0);    // force a 0 : broche utilisee comme entree DI_87A
    os_digout(DO_C,    0);
    os_digout(DO_X,    0);

    os_timestamp(&hb_timestamp,   OS_1ms);
    os_timestamp(&ccvs_last_seen, OS_1ms);
}


//-------------------------------------------------------------------------
// Gestion DO_C (indicateur d'etat 4 niveaux)
//-------------------------------------------------------------------------
static void update_doc(uint8 state)
{
    switch (state)
    {
        // Bus-Off hardware : eteint
        case DOC_STATE_BUSOFF:
            os_digout(DO_C, 0);
            break;

        // SPN erreur / non disponible : allume continu
        case DOC_STATE_ERROR:
            os_digout(DO_C, 1);
            break;

        // Bus silencieux ou perdu : 1 flash 500ms toutes les 3s
        case DOC_STATE_SILENT:
            if (hb_phase == 0)
            {
                if (os_time_past(hb_timestamp, 500, OS_1ms))
                {
                    os_timestamp(&hb_timestamp, OS_1ms);
                    os_digout(DO_C, 0);
                    hb_phase = 1;
                }
                else
                {
                    os_digout(DO_C, 1);
                }
            }
            else
            {
                if (os_time_past(hb_timestamp, 2500, OS_1ms))
                {
                    os_timestamp(&hb_timestamp, OS_1ms);
                    os_digout(DO_C, 1);
                    hb_phase = 0;
                }
            }
            break;

        // Reception OK : 400ms/400ms
        case DOC_STATE_OK:
        default:
            if (os_time_past(hb_timestamp, 400, OS_1ms))
            {
                os_timestamp(&hb_timestamp, OS_1ms);
                hb_state = (uint8)(!hb_state);
                os_digout(DO_C, hb_state);
            }
            break;
    }
}


//-------------------------------------------------------------------------
void usercode(void)
{
    uint8   doc_state;
    uint8   di87a;
    uint16  spn84_raw;
    uint16  thr_on;
    uint16  thr_off;

    // --- Timeout CCVS : si plus de 500ms sans trame -> bus perdu ---
    if (can_alive && os_time_past(ccvs_last_seen, CCVS_TIMEOUT_MS, OS_1ms))
    {
        can_alive   = 0;
        spn70_raw   = 3;     // reset a non disponible
        spn84_valid = 0;
        do_x_state  = 0;     // DO_X a 0 par securite si bus perdu
        os_digout(DO_X, 0);
    }

    // --- Lecture datapoints CAN ---
    spn70_raw = (uint8)(can_db_get_value(CAN_BUS_1, SPN70)  & 0x03);
    spn84_raw = (uint16)(can_db_get_value(CAN_BUS_1, SPN84) & 0xFFFF);

    // SPN84 valide si < 0xFE00 (0xFE00=erreur, 0xFF00=non disponible)
    spn84_valid = (spn84_raw < 0xFE00) ? 1 : 0;

    // --- Pilotage DO_87 : frein a main ---
    parking_brake = (spn70_raw == 1) ? 1 : 0;
    os_digout(DO_87, parking_brake);

    // --- Lecture DI_87A : selecteur de seuil vitesse ---
    // GND (= 0) -> seuil 10 km/h
    // Repos (= 1) -> seuil 5 km/h
    di87a = os_digin(DI_87A);

    if (di87a == 0)
    {
        thr_on  = SPEED_THR_10KMH_ON;
        thr_off = SPEED_THR_10KMH_OFF;
    }
    else
    {
        thr_on  = SPEED_THR_5KMH_ON;
        thr_off = SPEED_THR_5KMH_OFF;
    }

    // --- Pilotage DO_X : vitesse avec hysteresis ---
    if (!spn84_valid || !can_alive)
    {
        // Vitesse invalide ou bus perdu -> DO_X a 0 par securite
        do_x_state = 0;
    }
    else if (do_x_state == 0)
    {
        // Actuellement bas : passage a 1 si >= seuil haut
        if (spn84_raw >= thr_on)
            do_x_state = 1;
    }
    else
    {
        // Actuellement haut : retour a 0 si < seuil bas (hysteresis)
        if (spn84_raw < thr_off)
            do_x_state = 0;
    }

    os_digout(DO_X, do_x_state);

    // --- Determination etat DO_C (indicateur) ---
    if (os_can_check_error() == BIOS_CAN_ERR_BUS_OFF)
    {
        // Priorite absolue : erreur hardware
        doc_state = DOC_STATE_BUSOFF;
    }
    else if (!can_alive)
    {
        // Bus silencieux au demarrage OU perdu en cours de run
        doc_state = DOC_STATE_SILENT;
    }
    else if (spn70_raw >= 2 || !spn84_valid)
    {
        // SPN70 erreur/indispo OU vitesse invalide
        doc_state = DOC_STATE_ERROR;
    }
    else
    {
        doc_state = DOC_STATE_OK;
    }

    update_doc(doc_state);
}


//-------------------------------------------------------------------------
void user_can_message_receive(bios_can_msg_typ* msg)
{
    // Mise a jour du timestamp a chaque trame CCVS recue
    if (msg->id_ext == 1 && msg->id == 0x18FEF1E6UL)
    {
        os_timestamp(&ccvs_last_seen, OS_1ms);
    }

    can_alive = 1;
}


//-------------------------------------------------------------------------
// Hooks non utilises mais obligatoires
//-------------------------------------------------------------------------
void user_int_rx_sci(uint8 module, uint8 data)  { (void)module; (void)data; }
void user_int_timer_1ms(void)                    { }
void user_int_port(uint8 k)                      { (void)k; }
void user_int_adc(void)                          { (void)bios_analog_get_channel_single(); }
void user_int_stat_sci(void)                     { }