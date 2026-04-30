//--------------------------------------------------------------------------
/// \file     user_code.c
/// \brief    Boitier debug BB CAN Renault Trucks
///
///           DO_87  : frein a main  (SPN70  = 01 -> serre)
///           DO_87A : pedale frein  (SPN597 = 01 -> appuyee)
///           DO_C   : inutilise
///
///           DO_X   : indicateur d'etat 4 niveaux
///             - Bus silencieux  : 1 flash (500ms ON / 2500ms OFF)
///             - Reception OK    : clignotement 400ms/400ms
///             - SPN en erreur   : allume continu
///             - Bus-Off HW      : eteint
///
/// \platform HCS08DZ / HW_USPS_CAN_4IO_A rev C
/// \note     Mode mixte : config CAN via Eagle, logique metier en C pur
//--------------------------------------------------------------------------

#include "user_code.h"

//--- Etats DO_X ----------------------------------------------------------
#define DOX_STATE_BUSOFF    0    // Bus-Off HW          -> eteint
#define DOX_STATE_SILENT    1    // Bus silencieux       -> 1 flash / 3s
#define DOX_STATE_OK        2    // Reception CAN OK     -> 400ms/400ms
#define DOX_STATE_ERROR     3    // SPN erreur/indispo   -> continu

//--- Etat global ---------------------------------------------------------
static uint8   can_alive      = 0;   // 1 des qu'une trame est recue
static uint8   spn70_raw      = 3;   // derniere valeur brute SPN70  (init=non disponible)
static uint8   spn597_raw     = 3;   // derniere valeur brute SPN597 (init=non disponible)
static uint8   parking_brake  = 0;
static uint8   brake_pedal    = 0;

static uint32  hb_timestamp   = 0;
static uint8   hb_state       = 0;
static uint8   hb_phase       = 0;   // phase du clignotement (pour le 1 flash / 3s)


//-------------------------------------------------------------------------
void usercode_init(void)
{
    os_digout(DO_87,   0);
    os_digout(DO_87A,  0);
    os_digout(DO_C,    0);
    os_digout(DO_X,    0);

    os_timestamp(&hb_timestamp, OS_1ms);
}


//-------------------------------------------------------------------------
// Gestion DO_X selon l'etat du systeme
//-------------------------------------------------------------------------
static void update_dox(uint8 state)
{
    switch (state)
    {
        // --- Bus-Off : eteint ---
        case DOX_STATE_BUSOFF:
            os_digout(DO_X, 0);
            break;

        // --- SPN erreur/indispo : allume continu ---
        case DOX_STATE_ERROR:
            os_digout(DO_X, 1);
            break;

        // --- Bus silencieux : 1 flash 500ms toutes les 3s ---
        case DOX_STATE_SILENT:
            if (hb_phase == 0)
            {
                // Phase ON : 500ms
                if (os_time_past(hb_timestamp, 500, OS_1ms))
                {
                    os_timestamp(&hb_timestamp, OS_1ms);
                    os_digout(DO_X, 0);
                    hb_phase = 1;
                }
                else
                {
                    os_digout(DO_X, 1);
                }
            }
            else
            {
                // Phase OFF : 2500ms
                if (os_time_past(hb_timestamp, 2500, OS_1ms))
                {
                    os_timestamp(&hb_timestamp, OS_1ms);
                    os_digout(DO_X, 1);
                    hb_phase = 0;
                }
            }
            break;

        // --- Reception OK : 400ms/400ms ---
        case DOX_STATE_OK:
        default:
            if (os_time_past(hb_timestamp, 400, OS_1ms))
            {
                os_timestamp(&hb_timestamp, OS_1ms);
                hb_state = (uint8)(!hb_state);
                os_digout(DO_X, hb_state);
            }
            break;
    }
}


//-------------------------------------------------------------------------
void usercode(void)
{
    uint8  dox_state;
    uint32 val70;
    uint32 val597;

    // --- Lecture des datapoints ---
    val70  = can_db_get_value(CAN_BUS_1, SPN70);
    val597 = can_db_get_value(CAN_BUS_1, SPN597);

    // Sauvegarde valeurs brutes pour diagnostic DO_X
    spn70_raw  = (uint8)(val70  & 0x03);
    spn597_raw = (uint8)(val597 & 0x03);

    // --- Pilotage sorties metier ---
    // Actif UNIQUEMENT sur valeur 1 (etat confirme)
    // Erreur (2) et non disponible (3) -> sortie a 0
    parking_brake = (spn70_raw  == 1) ? 1 : 0;
    brake_pedal   = (spn597_raw == 1) ? 1 : 0;

    os_digout(DO_87,  parking_brake);
    os_digout(DO_87A, brake_pedal);

    // --- Determination etat DO_X ---
    if (os_can_check_error() == BIOS_CAN_ERR_BUS_OFF)
    {
        // Priorite absolue : Bus-Off hardware
        dox_state = DOX_STATE_BUSOFF;
    }
    else if (!can_alive)
    {
        // Code tourne mais pas de trame recue
        dox_state = DOX_STATE_SILENT;
    }
    else if (spn70_raw >= 2 || spn597_raw >= 2)
    {
        // Trame recue mais SPN en erreur ou non disponible
        dox_state = DOX_STATE_ERROR;
    }
    else
    {
        // Tout va bien
        dox_state = DOX_STATE_OK;
    }

    update_dox(dox_state);
}


//-------------------------------------------------------------------------
void user_can_message_receive(bios_can_msg_typ* msg)
{
    (void)msg;
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