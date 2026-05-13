/*----------------------------------------------------------------------------*/
/**
 * \file         user_lin_callback.c
 * \brief        Example for User LIN callback's, f.e. especially for a LIN-LIN Gateway
 * \details
 * \date         20181210
 * \author       Geissler
 *
 */
/*----------------------------------------------------------------------------*/


// ---------------------------------------------------------------------------------------------------
// General example Description:
// ----------------------------
// In this example is LIN_BUS_1 a Slave Input and it will simulate a Master on LIN_BUS_0 if a communication on LIN_BUS_1 is present.
// ---------------------------------------------------------------------------------------------------
// Preparation for the example:
// ----------------------------
// user_code.c:
// - #include "user_lin_callback.h"
// - call in - "void usercode_init( void )" - lin_set_callback() to enable the LIN callback functions from this file
//    // Set LIN callback's
//    lin_set_callback(   user_lin_header_received_callback,
//                        user_lin_frame_received_callback,
//                        user_lin_schedule_complete_callback,
//                        user_lin_frame_transmission_complete_callback);
//
// - modify the example different from your imported LDF




// ---------------------------------------------------------------------------------------------------
// includes
// ---------------------------------------------------------------------------------------------------
#include "user_lin_callback.h"


// ---------------------------------------------------------------------------------------------------
// tables
// ---------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------
// module globals
// ---------------------------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/**
* \internal
* user-callback c-code LIN header received, each header!
* - Only in Slave Mode, each header reception create a call
*
* - frame_index depends on enum_lin_frame_id from file lin_db_tables.h
* 
* - Attention rx_header_pid is the protected identifier (pid)
* \endinternal
*
*
* \test STATUS: *** UNTESTED ***
* Date       | Type    | Person
* -----------|---------|-----------
* 20181210   | Author  | Markus Geissler
* 20181210   | Editor  | Markus Geissler
* 20181210   | Tester  | Markus Geissler
*/
enum_header_received_callback user_lin_header_received_callback(const uint8_t lin_module, const uint8_t rx_header_pid, const uint8_t frame_index)
{
    uint8_t ret_val = LIN_HEADER_NO_ACK;
    
    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)frame_index;
    (void)rx_header_pid;
    (void)lin_module;

    // ---------------------------------------------------------------------------------------------------
    // Example Code for a Simple LIN <--> LIN Gateway
    // ---------------------------------------------------------------------------------------------------
	// uint8_t extended = lin_module;
	// uint32_t temp_id = 0x100 | rx_header_pid;

	// // only is received on LIN_BUS_1, and isn't a Master Request frame
	// if( (lin_module == LIN_BUS_1) && ( (rx_header_pid == 0x22) || (rx_header_pid == 0x20) ) )
	// {
	//     // send a CAN message, respond to the header
    //     // Byte 0 = lin_module
    //     // Byte 1 = rx_header_id
    //     // Byte 2 = frame_index
    //     // os_can_send_msg( hw_id, id, id_type, dlc, byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7);
    //     (void)os_can_send_msg( CAN_BUS_4 , temp_id, extended, 8, lin_module, rx_header_id, frame_index, 0, 0, 0, 0, 0);

	//     ret_val = LIN_HEADER_ACK;

    //     // send LIN frame on other bus
	//     lin_stack_transmit_frame_raw( LIN_BUS_0, rx_header_pid, (uint8_t)1u, LIN_CRC_CLASSIC, LIN_RX,
    //                                   0x22, 0x22, 0x22, 0x22,
    //                                   0x22, 0x22, 0x22, 0x22 );
	// }

	return ret_val;
}

/*----------------------------------------------------------------------------*/
/**
* \internal
* user-callback c-code LIN frame received, whole frame header and data on request frame
* - in Master Mode only the response frame create a call
* - in Slave Mode, only the request frame create a call
*
* - if frame_index is LINx_FRM_MAX, the msg ID isn't in the List lin_msg.id = pid (protected identifier)
* \endinternal
*
*
* \test STATUS: *** UNTESTED ***
* Date       | Type    | Person
* -----------|---------|-----------
* 20181210   | Author  | Markus Geissler
* 20181210   | Editor  | Markus Geissler
* 20181210   | Tester  | Markus Geissler
*/
void user_lin_frame_received_callback(const uint8_t lin_module, const struct_lin_rx_msg_type  lin_msg, const uint8_t frame_index)
{
    
    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)frame_index;
    (void)lin_msg;
    (void)lin_module;
    
    // ---------------------------------------------------------------------------------------------------
    // Example Code for a Simple LIN <--> LIN Gateway
    // ---------------------------------------------------------------------------------------------------
// 	uint8_t extended = lin_module;
// 	uint32_t temp_id = 0x200 | lin_msg.id;

//     // Byte  0 = lin_module
//     // Byte 1-7 = lin_data 0-6
//     // os_can_send_msg( hw_id, id, id_type, dlc, byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7);
//     (void)os_can_send_msg( CAN_BUS_4 , temp_id, extended, 8, lin_module, lin_msg.data[0], lin_msg.data[1], lin_msg.data[2], lin_msg.data[3], lin_msg.data[4], lin_msg.data[5], lin_msg.data[6] );

//    if( lin_module == LIN_BUS_1 )
//    {
//        lin_stack_transmit_frame_raw(  LIN_BUS_0, lin_msg.id, lin_msg.length, LIN_CRC_CLASSIC, LIN_TX,
//                                       lin_msg.data[0], lin_msg.data[1], lin_msg.data[2], lin_msg.data[3],
//                                       lin_msg.data[4], lin_msg.data[5], lin_msg.data[6], lin_msg.data[7]);
//    }

}

/*----------------------------------------------------------------------------*/
/**
* \internal
* user-callback c-code LIN schedule table complete
* \endinternal
*
*
* \test STATUS: *** UNTESTED ***
* Date       | Type    | Person
* -----------|---------|-----------
* 20181210   | Author  | Markus Geissler
* 20181210   | Editor  | Markus Geissler
* 20181210   | Tester  | Markus Geissler
*/
void user_lin_schedule_complete_callback(const uint8_t lin_module, const uint8_t lin_schedule_table_index)
{

    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)lin_schedule_table_index;
    (void)lin_module;
    
    // ---------------------------------------------------------------------------------------------------
    // Example Code for a Simple LIN <--> LIN Gateway
    // ---------------------------------------------------------------------------------------------------
	// uint8_t extended = lin_module;
	// uint32_t temp_id = 0x300;

    // // os_can_send_msg( hw_id, id, id_type, dlc, byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7);
    // (void)os_can_send_msg( CAN_BUS_4 , temp_id, extended, 8, lin_module, lin_schedule_table_index, 0, 0, 0, 0, 0, 0);

}

/*----------------------------------------------------------------------------*/
/**
* \internal
* user-callback c-code LIN frame transmission complete
*
* - frame_index depends on enum_lin_frame_id from file lin_db_tables.h
* \endinternal
*
*
* \test STATUS: *** UNTESTED ***
* Date       | Type    | Person
* -----------|---------|-----------
* 20181210   | Author  | Markus Geissler
* 20181210   | Editor  | Markus Geissler
* 20181210   | Tester  | Markus Geissler
*/
void user_lin_frame_transmission_complete_callback(const uint8_t lin_module, const uint8_t tx_header_id, const uint8_t frame_index)
{

    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)frame_index;
    (void)tx_header_id;
    (void)lin_module;
    
    // ---------------------------------------------------------------------------------------------------
    // Example Code for a Simple LIN <--> LIN Gateway
    // ---------------------------------------------------------------------------------------------------
	// uint8_t extended = lin_module;
	// uint32_t temp_id = 0x400 | ext_lin_frame_db[frame_index].id;


    // //os_can_send_msg( hw_id, id, id_type, dlc, byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7);
    // (void)os_can_send_msg( CAN_BUS_4 , temp_id, extended, 8, lin_module, ext_lin_frame_db[frame_index].id,  tx_header_id, frame_index, 0, 0, 0, 0);


}




// ---------------------------------------------------------------------------------------------------
// check for plausibility and assertion
// ---------------------------------------------------------------------------------------------------
