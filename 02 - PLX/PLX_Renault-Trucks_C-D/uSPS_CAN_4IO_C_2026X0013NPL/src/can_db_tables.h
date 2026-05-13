#ifndef _CAN_DB_TABLES_H_
#define _CAN_DB_TABLES_H_


/*--------------------------------------------------------------------------*/
/** \file     can_db_tables.h
*   \brief    CAN bus database
*
*   \date     30/04/2026    \author   DS/
*
*   \platform HCS08DZ / HCS12XE / HCS12XD / HCS12P
* --------------------------------------------------------------------------
*   \defgroup Name      can_tables
* --------------------------------------------------------------------------*/



// Change the Baudrate either to extended mode or a fix rate from the list below:
#define CAN_BAUDRATE BIOS_CAN_EXT_BAUDRATE
// einstellbare BAUDRATEN
// BIOS_CAN_EXT_BAUDRATE
// BIOS_CAN_1MBIT
// BIOS_CAN_800KBIT
// BIOS_CAN_500KBIT
// BIOS_CAN_250KBIT
// BIOS_CAN_125KBIT
// BIOS_CAN_100KBIT
// BIOS_CAN_83_33KBIT
// BIOS_CAN_50KBIT
// BIOS_CAN_33_33KBIT
// BIOS_CAN_20KBIT
// BIOS_CAN_10KBIT


//SETTING FOR BIOS_CAN_EXT_BAUDRATE 
#define  CAN_BAUDRATE_def_BEZEICHNUNG  250 kBit
#define  CAN_BAUDRATE_def_sj           2
#define  CAN_BAUDRATE_def_pre          2
#define  CAN_BAUDRATE_def_t_seg1       13
#define  CAN_BAUDRATE_def_t_seg2       2
#define  CAN_BAUDRATE_def_source       0



// Activate the user-defined filter settings:
#define CAN_USER_SETTINGS_ACTIVE

#ifdef CAN_USER_SETTINGS_ACTIVE

    // Settings of CAN filters and masks:
    #define CAN_FILTER_SETTING BIOS_CAN_ID_EXT_A_AND_B
    // Possibilities:
    // BIOS_CAN_ID_NORM_A_AND_B  // Both masks 11bit
    // BIOS_CAN_ID_NORM_A_EXT_B  // One mask 11bit, the other 29bit
    // BIOS_CAN_ID_EXT_A_AND_B   // Both masks 29bit
    // BIOS_CAN_ID_ALL_CLOSED    // All filters closed
    // BIOS_CAN_ID_ALL_OPEN      // All filters open


    // Filter A
    #define CAN_FILTER_A   0x1CFEC3E6
    #define CAN_MASK_A     0x04003200

    // Filter B
    #define CAN_FILTER_B   0x0CF004E6
    #define CAN_MASK_B     0x00000000

    //#define CAN_4_FILTERS_ACTIVE    // Not possible!
    #ifdef CAN_4_FILTERS_ACTIVE

        // Filter A_4
        #define CAN_FILTER_A_4   0x000
        #define CAN_MASK_A_4     0x000
        // Filter B_4
        #define CAN_FILTER_B_4   0x000
        #define CAN_MASK_B_4     0x000
        // Filter C_4
        #define CAN_FILTER_C_4   0x000
        #define CAN_MASK_C_4     0x000
        // Filter D_4
        #define CAN_FILTER_D_4   0x000
        #define CAN_MASK_D_4     0x000
    #endif

#endif

/// Define CAN busses: All the possible CAN busses. Only use these busses in table #can_block_db_const
typedef enum
{
    CAN_BUS_1 = 0,
    CAN_BUS_MAX
} can_bus_id;



/// Define datapoints: Order must be the same as in table#can_datenpunkt_db_const
typedef enum
{
    SPN70                   = 0,
    SPN84                      ,
    SPN597                     ,
    SPN190                     ,
    SPN767                     ,
    SPN604                     ,
    CAN_DP_MAX            
}can_dp_id;




/// Define CAN blocks: Order must be the same as in table #can_block_db_const
typedef enum
{
    CCVS                    = 0,
    EEC1                    = 1,
    ETC5                    = 2,
    CAN_BLOCK_MAX           = 3
} can_block_id;




#endif


