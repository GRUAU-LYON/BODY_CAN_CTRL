//--------------------------------------------------------------------------
/// \file     user_code.c
/// \brief    Boitier BB CAN IVECO Daily
///
///           DO_87  : frein a main via relais inverseur (NF)
///                    DO_87=1 (bobine excitee)   = frein desserre
///                    DO_87=0 (bobine retombee)  = frein serre -> GND sur entree equipement
///           DO_X   : hayon arriere
///                    DO_X=1 = hayon ferme
///                    DO_X=0 = hayon ouvert
///           DO_C   : indicateur d'etat 4 niveaux
///                    - Bus silencieux/perdu : 1 flash (500ms ON / 2500ms OFF)
///                    - Reception OK         : clignotement 400ms/400ms
///                    - Signal invalide      : allume continu
///                    - Bus-Off HW           : eteint
///           DO_87A : non utilise
///
/// \platform HCS08DZ / HW_USPS_CAN_4IO_A rev C
/// \note     Mode mixte : config CAN via Eagle (CAN_DB),
///           logique metier en C pur
//--------------------------------------------------------------------------

#include "user_code.h"

//--- Etats DO_C (indicateur) ---------------------------------------------
#define DOC_STATE_BUSOFF    0    // Bus-Off HW          -> eteint
#define DOC_STATE_SILENT    1    // Bus silencieux/perdu -> 1 flash / 3s
#define DOC_STATE_OK        2    // Reception OK         -> 400ms/400ms
#define DOC_STATE_ERROR     3    // Signal invalide      -> continu

//--- Timeout reception MuxInfo_L -----------------------------------------
// Cycle min 50ms -> 500ms = 10 trames manquees
#define MUXINFO_TIMEOUT_MS  500

//--- Etat global ---------------------------------------------------------
static uint8   can_alive      = 0;
static uint8   hand_brake_raw = 0;   // derniere valeur brute Hand_Brake
static uint8   hatch_rear_raw = 0;   // derniere valeur brute Hatch_Rear

static uint32  hb_timestamp      = 0;
static uint8   hb_state          = 0;
static uint8   hb_phase          = 0;
static uint32  muxinfo_last_seen = 0;


//-------------------------------------------------------------------------
void usercode_init(void)
{
    // DO_87 : relais inverseur
    // Au boot on ne connait pas l'etat du frein
    // On excite la bobine (1) = position "desserre" par defaut
    // -> contact NF ouvert -> pas de GND sur entree equipement -> securite
    os_digout(DO_87,   1);
    os_digout(DO_87A,  0);
    os_digout(DO_C,    0);
    os_digout(DO_X,    0);

    os_timestamp(&hb_timestamp,       OS_1ms);
    os_timestamp(&muxinfo_last_seen,  OS_1ms);
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

        // Signal invalide : allume continu
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
    uint8 doc_state;

    // --- Timeout MuxInfo_L : si plus de 500ms sans trame -> bus perdu ---
    if (can_alive && os_time_past(muxinfo_last_seen, MUXINFO_TIMEOUT_MS, OS_1ms))
    {
        can_alive      = 0;
        hand_brake_raw = 0;
        hatch_rear_raw = 0;
        // Bus perdu : on excite le relais (1) -> position securite
        // contact NF ouvert -> pas de faux "frein serre" sur equipement
        os_digout(DO_87, 1);
        os_digout(DO_X,  0);
    }

    // --- Lecture datapoints CAN ---
    hand_brake_raw = (uint8)(can_db_get_value(CAN_BUS_1, Hand_Brake) & 0x01);
    hatch_rear_raw = (uint8)(can_db_get_value(CAN_BUS_1, Hatch_Rear) & 0x01);

    // --- Pilotage DO_87 : frein a main via relais inverseur ---
    //
    // Hand_Brake = 1 -> frein desserre -> DO_87 = 1 (bobine excitee, NF ouvert)
    // Hand_Brake = 0 -> frein serre    -> DO_87 = 0 (bobine retombee, NF ferme -> GND)
    //
    // En cas de bus perdu : DO_87 = 1 par securite (pas de faux frein serre)
    if (can_alive)
    {
        os_digout(DO_87, hand_brake_raw);
    }

    // --- Pilotage DO_X : hayon arriere ---
    //
    // Hatch_Rear = 1 -> hayon ferme -> DO_X = 1
    // Hatch_Rear = 0 -> hayon ouvert -> DO_X = 0
    if (can_alive)
    {
        os_digout(DO_X, hatch_rear_raw);
    }

    // --- Determination etat DO_C (indicateur) ---
    if (os_can_check_error() == BIOS_CAN_ERR_BUS_OFF)
    {
        doc_state = DOC_STATE_BUSOFF;
    }
    else if (!can_alive)
    {
        doc_state = DOC_STATE_SILENT;
    }
    else
    {
        // Sur ce protocole les valeurs sont des bits bruts (0 ou 1)
        // pas de notion d'erreur/non disponible comme en J1939
        // -> des qu'on recoit des trames c'est OK
        doc_state = DOC_STATE_OK;
    }

    update_doc(doc_state);
}


//-------------------------------------------------------------------------
void user_can_message_receive(bios_can_msg_typ* msg)
{
    // Mise a jour timestamp sur reception de MuxInfo_L uniquement
    // C'est ce bloc qui porte nos deux datapoints metier
    if (msg->id_ext == 1 && msg->id == 0x18FCC321UL)
    {
        os_timestamp(&muxinfo_last_seen, OS_1ms);
        can_alive = 1;
    }
}


//-------------------------------------------------------------------------
// Hooks non utilises mais obligatoires
//-------------------------------------------------------------------------
void user_int_rx_sci(uint8 module, uint8 data)  { (void)module; (void)data; }
void user_int_timer_1ms(void)                    { }
void user_int_port(uint8 k)                      { (void)k; }
void user_int_adc(void)                          { (void)bios_analog_get_channel_single(); }
void user_int_stat_sci(void)                     { }