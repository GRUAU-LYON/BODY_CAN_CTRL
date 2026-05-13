#ifndef _USER_CODE_H_
#define _USER_CODE_H_
//--------------------------------------------------------------------------
/// \file     user_code.c
/// \brief    user code header
/// \author   user
/// \date     17.02.2010
/// \version  1.00
/// \comment  file to write user specific code
//--------------------------------------------------------------------------

#include "bios_can.h"
#include "os_can.h"

void usercode(void);
void user_can_message_receive(bios_can_msg_typ* msg);
void user_int_rx_sci(uint8_t module, uint8_t data);
void user_int_timer_1ms(void);
void user_int_timer_channels(uint8_t channel);
void user_int_port(uint8_t k);
void user_int_adc(void);
void user_int_stat_sci(void);


// ================================================================================
// ================================================================================
// ================================================================================

// The following module selection is only intended for a Codewarrior project of
// userlib files, e.g. MRS_HCS08_Lib_Usercode_V23_20140827.zip
// If you're programming in c in a regular MRS Developers Studio and compile / link
// with it, you already selected the product on creation of the project.

#define HW_CAN_IO_V2        0
#define HW_USPS_CAN_V2      1
#define HW_PROP_CAN_V2      2
#define HW_PROP_CAN_60A_B   3
#define HW_FULLBRIDGE_A2    4
#define HW_PROP_CAN_6FACH_B 5
#define HW_CAN_IO_PRO_WP_C2 6
#define HW_USPS_CAN_4IO_A   7

//--------------------------------------------------------------------------------
#define HW_TYPE HW_USPS_CAN_4IO_A
//--------------------------------------------------------------------------------

// ================================================================================
// ================================================================================
// ================================================================================


//--------------------------------------------------------------------------------
// To disable code of graphical programming remove the comment in the line below:
// Remember to use os_pin_write() instead of os_digout() and os_pin_read() instead of os_digin()
//#define GRAPH_DISABLE
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// For RS232/485 communication on CAN I/O, CAN I/O PRO WP set the following #defines:

// Enable or disable RS232/485 serial communication interface (THIS IS NEEDED):
//#define SCI_USER_ACTIVE

// Activate if needed RS485(for switching driver output enable "DE" - pin)
//#define SCI_USER_RS485

// Set receive buffer size (16bit value):
#define USER_BUFFER_SIZE 100

// Set baudrate (typical baudrates are 4800, 9600, 19200, 28800, 38400, 57600)
#define SCI_USER_BAUDRATE 9600

// Or calculate user-defined baud rate and set register value:
// Calculation: SBR = BUSCLK / (16 x Baudrate); BUSCLK=20000000 (20MHz)
//#define SCI_USER_DEFINED_BAUDRATE 0x0041    // =19200 baud

// Parity: 0=disabled, 1=even parity, 2=odd parity
#define SCI_USER_PARITY   0

// Data bits: 0=8 data bits, 1=9 data bits
#define SCI_USER_DATA_BITS_9  0

// Activate full duplex mode (e.g. for RS232)
//#define SCI_USER_FULL_DUPLEX

// DO NOT WAIT after sending a specific delay time for reswitching tx-rx mode (for RS232 it must not wait)
//#define SCI_NO_DELAY_AFTER_SEND

//CAN I/O, CAN I/O WP, CAN I/O PRO WP use SCI2
#define SCI_NR  TAKE_SCI2
//--------------------------------------------------------------------------------



//--------------------------------------------------------------------------------
// Read PWM duty cycle:

// Activate PWM duty cycle read
//#define PWM_DUTYCYCLE_READ_ACTIVE

// Specify expected PWM frequency in Hz
#define PWM_DUTYCYCLE_READ_FREQ   1000

// Specify desired duty cycle resolution in digits, measured value will be between 0 and res
#define PWM_DUTYCYCLE_READ_RES    100

// Specify Timer channel (see os_io_tables.c, os_pwm_pin[])
// CAN I/O: 0=OUT_HSD7, 1=OUT_HSD6, 2=OUT_HSD5, 3=OUT_HSD4, 4=OUT_HSD3, 5=OUT_HSD2
#define PWM_DUTYCYCLE_READ_CH     0
//--------------------------------------------------------------------------------



//--------------------------------------------------------------------------------
// To disable automatic ADC-Routines and read the ADC-Channels on your own
// remove the comment in the line below:
//#define ADC_AUTO_DISABLE
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// Enable calibration values for analog inputs if available:
//#define ADC_CAL_ENABLE
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// Set the size of uint16 eeprom_userdaten[]
#define USERDATENSATZ_SIZE 56

// Set the size of uint32 user_variable[]
#define USER_VARIABLE_SIZE 10

// - optional if values above have no effect -

// Set the size of uint16 eeprom_hsddaten[]
//#define HSDDATENSATZ_SIZE_MASTER 48

// Set the size of uint16 user_variable[]
//#define USER_VARIABLE_SIZE_MASTER 20
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// Set the size of CAN receive buffer A and B (one entry needs 15b in RAM)
#define OS_CAN_MSG_QUEUE_A_SIZE 10
#define OS_CAN_MSG_QUEUE_B_SIZE 10
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// Set the size of CAN send buffer (one entry needs 15b in RAM)
#define OS_CAN_MSG_TX_BUFFER_SIZE 5
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// Set modbus slave address if needed. Also activate MODBUS_AKTIV in graph_defines.h to use modbus functions
#define SLAVE_MODBUS_ADRESSE 0x50
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// Disable CAN on init. Call later can_db_init(0); to init CAN bus.
// Optionally you could set uint8 dyn_CAN_BAUDRATE to a value like BIOS_CAN_125KBIT (see bios_can.h).
// Call (void)Set_Baudrate_EEPROM() to synchronize Baudrate with Bootloader (return value != ERR_OK on error)
//#define CAN_INIT_DISABLE
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// On startup initialize CAN in Listen-Only-Mode. Switch to Normal-Mode with can_db_set_listen_only_mode(FALSE);
//#define INIT_CAN_LISTEN_ONLY
//--------------------------------------------------------------------------------


#include "bios.h"
#include "os_timer.h"
#include "os_io.h"
#include "SYSTEM_CAN_EEprom.h"
#include "can_db.h"
#include "os_io_tables.h"
#include "MODBUS.H"
#include "graph_includes.h"
#include "lin_stack.h"
#include "modulhardwarecode.h"

#endif
