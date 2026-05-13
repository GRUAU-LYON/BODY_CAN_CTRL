//#ifndef _USER_LIN_CALLBACK_H_
//#define _USER_LIN_CALLBACK_H_
/*----------------------------------------------------------------------------*/
/** 
* \file         USER_LIN_CALLBACK.h
* \brief
* \date         20181210
* \author       Geissler
*
*/
/*----------------------------------------------------------------------------*/
/**
 * \defgroup user_lin User LIN with User callback functions
 * \brief    Declaration of all user functions for specific LIN callbacks
 * \details
 */
/*----------------------------------------------------------------------------*/

// ---------------------------------------------------------------------------------------------------
// includes
// ---------------------------------------------------------------------------------------------------
#include "user_code.h"


// ---------------------------------------------------------------------------------------------------
// defines
// ---------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------
// typedefs
// ---------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------
// function prototypes
// ---------------------------------------------------------------------------------------------------

/*----------------------------------------------------------------------------*/
/** 
* \ingroup  user_lin
* \brief    user-callback c-code LIN header received, each header!
* \details           
* - Only in Slave Mode, each header reception create a call
* \pre      
*           
* \param    lin_module                    [in] uint8_t  LIN Bus module --> lin_db_tables.h
* \param    rx_header_id                  [in] uint8_t  Received LIN Header ID
* \param    frame_index                   [in] uint8_t  frame_index depends on enum_lin_frame_id from file lin_db_tables.h
* \return   enum_header_received_callback      
*/

enum_header_received_callback user_lin_header_received_callback(const uint8_t lin_module, const uint8_t rx_header_id, const uint8_t frame_index);

/*----------------------------------------------------------------------------*/
/** 
* \ingroup  user_lin
* \brief    user-callback c-code LIN frame received, whole frame header and data on request frame
* \details           
* - in Master Mode only the response frame create a call
* - in Slave Mode, only the request frame create a call
* \pre      
*           
* \param    lin_module [in] uint8_t                 LIN Bus module --> lin_db_tables.h
* \param    lin_msg    [in] struct_lin_rx_msg_type
* \param    frame_index  [in] uint8_t   frame_index depends on enum_lin_frame_id from file lin_db_tables.h
* \return   void      
*/
void user_lin_frame_received_callback(const uint8_t lin_module, const struct_lin_rx_msg_type lin_msg, const uint8_t frame_index);

/*----------------------------------------------------------------------------*/
/** 
* \ingroup  user_lin
* \brief    user-callback c-code LIN schedule table complete
* \details           
*
* \pre      
*           
* \param    lin_module               [in] uint8_t   LIN Bus module --> lin_db_tables.h
* \param    lin_schedule_table_index [in] uint8_t
* \return   void      
*/
void user_lin_schedule_complete_callback(const uint8_t lin_module, const uint8_t lin_schedule_table_index);

/*----------------------------------------------------------------------------*/
/** 
* \ingroup  user_lin
* \brief    user-callback c-code LIN frame transmission complete
* \details           
*
* \pre      
*           
* \param    lin_module   [in] uint8_t   LIN Bus module --> lin_db_tables.h
* \param    tx_header_id [in] uint8_t   transmitted LIN Header ID
* \param    frame_index  [in] uint8_t   frame_index depends on enum_lin_frame_id from file lin_db_tables.h
* \return   void      
*/
void user_lin_frame_transmission_complete_callback(const uint8_t lin_module, const uint8_t tx_header_id, const uint8_t frame_index);


//#endif // End _USER_LIN_CALLBACK H_
