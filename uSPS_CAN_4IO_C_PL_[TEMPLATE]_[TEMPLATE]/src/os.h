#ifndef _OS_H_
#define _OS_H_

#include "os_util.h"
#include "os_can.h"
#include "os_ee_flash.h"
#include "os_timer.h"
#include "os_io.h"
#include "os_io_tables.h"
#include "SYSTEM_CAN_EEprom.h"
#include "os_iee.h"
#include "os_i2c.h"
#include "user_code.h"

extern uint16 dyn_CAN_DP_MAX;
extern uint8  dyn_CAN_BUS_MAX;
extern uint16 dyn_CAN_BLOCK_MAX;
extern uint8  dyn_OS_PORT_INPUT_PIN_MAX;
extern uint8  dyn_OS_PORT_PIN_MAX;
extern uint8  dyn_OS_ANALOG_PIN_MAX;
extern uint8  dyn_CAN_BAUDRATE;
extern uint8  dyn_CAN_BAUDRATE_def_sj;
extern uint8  dyn_CAN_BAUDRATE_def_pre;
extern uint8  dyn_CAN_BAUDRATE_def_t_seg1;
extern uint8  dyn_CAN_BAUDRATE_def_t_seg2;
extern uint8  dyn_CAN_BAUDRATE_def_source;
extern uint8  dyn_CAN_BUS_1;
extern uint8  dyn_BIOS_NR_OF_PORTS;
extern uint16 dyn_I2C_BYTE_SIZE;
extern uint8  dyn_OS_PWM_PIN_MAX;
extern uint8  dyn_PWM_DUTY_READ_MAX;

extern uint8  dyn_CAN_FILTER_SETTING; 
extern uint32 dyn_CAN_FILTER[];
extern uint32 dyn_CAN_MASK[];

extern uint8 dyn_USERDATENSATZ_SIZE;   
extern uint8 dyn_USER_VARIABLE_SIZE;   
extern uint8 dyn_HSDDATENSATZ_SIZE;    








#endif
