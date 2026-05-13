#ifndef _BIOS_INTERRUPTS_H_
#define _BIOS_INTERRUPTS_H_

#include "bios_base.h"
#include "os_io.h"
#include "os_timer.h"

#define ON_OVERRUN  1

#define CAN_STANDARD_FRAME_MAX_ID    0x07FF 
#define CAN_EXTENDED_FRAME_MAX_ID    0x1FFFFFFFUL 
#define CAN_EXTENDED_FRAME_MASK      0x60000000UL 
#define CAN_MAX_DATA_LEN             0x08 
#define FULL_RX_BUF                  0x01 

#define MB_ID_IDE                    0x00080000UL
#define CAN_TX_MBUFFERS              0x03 
#define CAN_MAX_RX_FIFO              0x04 

#define CAN_STATUS_OVERRUN_MASK      0x02 
#define CAN_STATUS_TX_MASK           0x0C 
#define CAN_STATUS_RX_MASK           0x30 
#define CAN_STATUS_BOFF_MASK         0x0C 
#define CAN_STATUS_BOFF_EXT_MASK     0x40 
#define CAN_STATUS_TX_PASS_MASK      0x08 
#define CAN_STATUS_RX_PASS_MASK      0x20 
#define CAN_STATUS_TX_WARN_MASK      0x04 
#define CAN_STATUS_RX_WARN_MASK      0x10 
#define CAN_STATUS_WAKEUP_MASK       0x80 

extern void os_timer1_dither_calculation_first(void);
extern void os_port_int_increment_first(void);      
extern void bios_can_handle_tx_buffer(uint8 reg_cantflg);


#endif
