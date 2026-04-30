/*--------------------------------------------------------------------------*/
/** \file     can_db_tables.c
*   \brief    CAN bus database
*
*   \date     30/04/2026    \author   DS/
*
*   \platform HCS08DZ / HCS12XE / HCS12XD / HCS12P
* --------------------------------------------------------------------------*/


#include "can_db_tables.h" 
#include "can_db.h"



/** \ingroup can_tables
*   \brief           Table of all CAN datapoints
* --------------------------------------------------------------------------*
*                    Every line defines a datapoint within a CAN block.
*                    Every datapoint is assigned to a CAN block ID
*                    #can_block_id, the order of the IDs has to be the same as
*                    the CAN block table #can_block_db_const.
*                    The table contains bit position, bit length and datatype.
*                    The datapoints are used with #can_db_set_value() or #can_db_get_value().
*                    As parameter use the name from the list #can_dp_id verwendet,
*                    the order has to be the same as in this table.
* --------------------------------------------------------------------------*/
 volatile const can_datenpunkt_db_const_typ can1_datenpunkt_db_const[CAN_DP_MAX+1] = { // Array can1_....  with the dp of one CAN interface
 //CAN block index        Pos bit0             Length,     Data type   Data format           LineNr: datapoint-ID  
 //-----------------------------------------------------------------------------------------------------------------
 //(16 Bit)              (0-63)                (1-32)                  (0=Intel, 1=Motorola)
 //-----------------------------------------------------------------------------------------------------------------
{  MuxInfo_L             ,6                    ,1          ,UBYTE      ,0          },  //High_Beam_Lights      
{  MuxInfo_L             ,7                    ,1          ,UBYTE      ,0          },  //Low_Beam_Lights       
{  MuxInfo_L             ,28                   ,1          ,UBYTE      ,0          },  //Hatch_Rear            
{  MuxInfo_L             ,29                   ,1          ,UBYTE      ,0          },  //Door_Left_Rear        
{  MuxInfo_L             ,30                   ,1          ,UBYTE      ,0          },  //Door_Right_Rear       
{  MuxInfo_L             ,40                   ,4          ,UBYTE      ,0          },  //Key_Status            
{  MuxInfo_L             ,56                   ,1          ,UBYTE      ,0          },  //Hand_Brake            
{  PB_NmM                ,4                    ,2          ,UBYTE      ,0          },  //Ignition_On           
};

//--------------------------------------------------------------------------------------------------------
// Pointer array to datapoint_db arrays per CAN interface
//--------------------------------------------------------------------------------------------------------
volatile const can_datenpunkt_db_const_typ *can_datenpunkt_db_const[CAN_BUS_MAX+1] =
{
                     can1_datenpunkt_db_const ,  // can1_....  CAN interface 1
};


/** \ingroup can_tables
*   \brief           Table of all CAN blocks
* --------------------------------------------------------------------------*
*                    Every line defines a CAN block and sets the CAN-ID,
*                    the minimal and maximal time between to messages for sending,
*                    the length of a message and the direction (0=Rx, 1=Tx).
*                    The CAN-IDs must be defined in can_db.h.
*                    Every CAN block is assigned to a ID, the order has to be
*                    the same as in this table.
* --------------------------------------------------------------------------*/
 volatile const can_block_db_const_typ can1_block_db_const[CAN_BLOCK_MAX+1] = { // Array can1_....  with the CAN blocks of one CAN interface
 //CAN-ID                EXT-ID                Max,                  Min                   Msg-Len DLC           TX Flag               CAN-ID-Mask           
 //----------------------------------------------------------------------------------------------------------------------------------------------------------
 //(32 Bit)              (0,1)                 (32 Bit)              (32 Bit)              (0-8)                 (0,1)                 (29bit)               
 //----------------------------------------------------------------------------------------------------------------------------------------------------------
{  0x18FFC321            ,1                    ,500                  ,0                    ,8                    ,0                    ,0                    } ,  //MuxInfo_L             
{  0x0CFFD221            ,1                    ,1000                 ,0                    ,8                    ,0                    ,0                    } ,  //PB_NmM                
};


//--------------------------------------------------------------------------------------------
// Pointer array to datapoint_db arrays per CAN interface
//--------------------------------------------------------------------------------------------
volatile const can_block_db_const_typ *can_block_db_const[CAN_BUS_MAX+1] =
{
                                 can1_block_db_const,      // Array can1_....  CAN interface 1
};




