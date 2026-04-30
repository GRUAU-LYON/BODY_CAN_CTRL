#ifndef _OS_CAN_H_
#define _OS_CAN_H_

#include "bios_can.h"

#include <string.h>
#include <stdio.h>  


#define OS_CAN_ENABLE_MSG_QUEUE_A_B 1


extern uint8 os_can_msg_queue_A_overflow, os_can_msg_queue_B_overflow;

typedef enum
{
	CAN_BAUD_USER_1000  =  1,
	CAN_BAUD_USER_800      	,
	CAN_BAUD_USER_500       ,
	CAN_BAUD_USER_250       ,
	CAN_BAUD_USER_125       ,
	CAN_BAUD_USER_50        ,
	CAN_BAUD_USER_20        ,
	CAN_BAUD_USER_10      	,
	CAN_BAUD_USER_100       ,
	CAN_BAUD_USER_83_3      ,
	CAN_BAUD_USER_33_3      ,
	CAN_BAUD_USER_MAX_LEN   ,
} enum_USER_CAN_BAUDRADE;




#if OS_CAN_ENABLE_MSG_QUEUE_A_B


uint8 os_can_get_msg_A(bios_can_msg_typ* msg);


uint8 os_can_get_msg_B(bios_can_msg_typ* msg);


void os_can_rx(void);


#endif


uint8 os_can_send_message(uint32 id, uint8 id_type,  uint8 dlc, uint8 byte0 , uint8 byte1 , uint8 byte2 , uint8 byte3 , uint8 byte4 , uint8 byte5 , uint8 byte6 , uint8 byte7);


uint8 os_can_check_error(void);


void os_can_set_baudrate(uint8_t bus_id, uint8_t baudrate);

#endif

