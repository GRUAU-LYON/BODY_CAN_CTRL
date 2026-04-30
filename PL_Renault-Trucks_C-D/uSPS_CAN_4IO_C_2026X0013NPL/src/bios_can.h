#ifndef _BIOS_CAN_H_
#define _BIOS_CAN_H_


#include "bios_base.h"

#define BIOS_CAN_EXT_BAUDRATE  0   

#define BIOS_CAN_1MBIT       1 
#define BIOS_CAN_800KBIT     2 
#define BIOS_CAN_500KBIT     3
#define BIOS_CAN_250KBIT     4
#define BIOS_CAN_125KBIT     5
#define BIOS_CAN_100KBIT     9
#define BIOS_CAN_83_33KBIT  10
#define BIOS_CAN_50KBIT      6
#define BIOS_CAN_33_33KBIT  11
#define BIOS_CAN_20KBIT      7
#define BIOS_CAN_10KBIT      8 




#define BIOS_CAN_ERR_RX_OK     0
#define BIOS_CAN_ERR_RX_WARN   1
#define BIOS_CAN_ERR_RX_ERROR  2
#define BIOS_CAN_ERR_BUS_OFF   3






#define BIOS_CAN_ID_NORM_A_AND_B  0 
#define BIOS_CAN_ID_NORM_A_EXT_B  1 
#define BIOS_CAN_ID_EXT_A_AND_B   2 
#define BIOS_CAN_ID_ALL_CLOSED    3 
#define BIOS_CAN_ID_ALL_OPEN      4 





typedef struct
{
    uint32 id;
    uint16 id_ext    :1;
    uint16 remote_tx :1;
    uint8 data[8];
    uint8 len;
    uint8 prty;
} bios_can_msg_typ;

typedef struct
{
	uint32 IdType;
	uint32 Id;
	uint8  Dlc;
	uint8  Data[8];
} canmsg_typ  ;

typedef struct 
{
  uint8 p;
  uint8 t_seg1;
  uint8 t_seg2;
  uint8 sj;
  uint8 clk_src;
} bios_baudraten_def;



uint8 bios_test_baudrate(uint8 bitrate);



uint8 bios_can_filter_A_hit(void);



void bios_can_disable(void);



void bios_can_enter_reset(void);



void bios_can_enter_operation(void);



void bios_init_can(uint8 bitrate, uint32 *mask, uint32 *filter, uint8 *id_usage);



void bios_can_set_transmit_mode(uint8_t p_state);



uint8 bios_can_send_msg(bios_can_msg_typ* msg);



uint8 bios_can_get_msg(bios_can_msg_typ *msg);



uint32 bios_can_get_msg_id(void);



uint8 bios_can_msg_received(void);



uint8 bios_can_check_error(void);



uint8 bios_can_parameter_to_number(uint8 p, uint8 t_seg1, uint8 t_seg2, uint8 sj, uint8 clk_src);


#endif
