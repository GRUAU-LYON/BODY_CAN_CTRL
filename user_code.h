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
#include "bios_io.h"

void usercode(void);
void user_can_message_receive(bios_can_msg_typ* msg);
void user_int_rx_sci(uint8_t module, uint8_t data); // ================>>>>>>>>>>>> Changed V79
void user_int_timer_1ms(void);
void user_int_port(uint8_t k);
void user_int_adc(void);
void user_int_stat_sci(void);
void usercode_init(void);

#define HW_CAN_IO_V2        0
#define HW_USPS_CAN_V2      1
#define HW_PROP_CAN_V2      2
#define HW_PROP_CAN_60A_B   3
#define HW_FULLBRIDGE_A2    4
#define HW_PROP_CAN_6FACH_B 5
#define HW_CAN_IO_PRO_WP_C2 6
#define HW_USPS_CAN_4IO_A   7


//--------------------------------------------------------------------------------
// Specify your hardware type below (take one of the #define 's above):
#define HW_TYPE HW_CAN_IO_V2
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// To disable code of graphical programming remove the comment in the line below:
// Remember to use os_pin_write() instead of os_digout() and os_pin_read() instead of os_digin()
//#define GRAPH_DISABLE
//--------------------------------------------------------------------------------


#if HW_TYPE == HW_CAN_IO_V2
  //--------------------------------------------------------------------------------
  // FOR RS485 communication uncomment set 3 #define:
  // Enable or disable RS485 Serial communication interface
  //#define SCI_USER_ACTIVE

//================>>>>>>>>>>>> Added V68
// Enable or disable RS232/485 serial communication interface (THIS IS NEEDED):
//#define SCI_USER_RS485

  // Set buffer size (16bit value):
  #define USER_BUFFER_SIZE 100

  // Choose Baudrate from the list:
  #define SCI_USER_BAUDRATE SCI_19200BAUD   
  // Possible baudrates: 
  // SCI_4800BAUD
  // SCI_9600BAUD
  // SCI_19200BAUD
  // SCI_28800BAUD
  // SCI_115200BAUD
  
  // Or set user-defined baud rate:
  // Calculation: SBR = BUSCLK / (16 x Baudrate); BUSCLK=20E6
  //#define SCI_USER_DEFINED_BAUDRATE 0x0041
  
  // Parity: 0=disabled, 1=even parity, 2=odd parity
  #define SCI_USER_PARITY   0
  
  // Data bits: 0=8 data bits, 1=9 data bits
  #define SCI_USER_DATA_BITS_9  0
  
  // Activate full duplex mode (e.g. for RS232)
  //#define SCI_USER_FULL_DUPLEX
  
  // Wait after sending specific delay time for reswitching tx-rx mode
  //#define SCI_NO_DELAY_AFTER_SEND
  
  //Don't change that line:
  #define SCI_NR  TAKE_SCI2   // If no RS485 Transceiver => Comment MODBUS_MODE in graph_defines.h          
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
#endif


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
#define SLAVE_MODBUS_ADRESSE 0x50 // ================>>>>>>>>>>>> Changed V112
//--------------------------------------------------------------------------------



//================>>>>>>>>>>>> Added V70
//--------------------------------------------------------------------------------
// Disable CAN on init. Call later can_db_init(0); to init CAN bus.
// Optionally you could set uint8 dyn_CAN_BAUDRATE to a value like BIOS_CAN_125KBIT (see bios_can.h).
// Call Set_Baudrate_EEPROM() to synchronize Baudrate with Bootloader
//#define CAN_INIT_DISABLE
//--------------------------------------------------------------------------------

#include "lin_stack.h"
#include "bios.h"
#include "os_timer.h"
#include "os_io.h"
#include "SYSTEM_CAN_EEprom.h"
#include "can_db.h"
#include "os_io_tables.h"
#include "MODBUS.H"
#include "graph_includes.h"


void user_int_timer_channels(uint8_t channel);
#endif
