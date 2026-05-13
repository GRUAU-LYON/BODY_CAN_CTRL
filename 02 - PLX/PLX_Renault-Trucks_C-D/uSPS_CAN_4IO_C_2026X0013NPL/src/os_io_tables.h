#ifndef _OS_IO_TABLES_H_
#define _OS_IO_TABLES_H_


/*--------------------------------------------------------------------------*/
/** \file     os_io_tables.h
*   \brief    Tables for definitions of I/O ports and their properties
*
*   \date     30/04/2026    \author   DS/
*
*   \platform HCS08DZ / HCS12XE / HCS12XD / HCS12P
* --------------------------------------------------------------------------
*   \defgroup Name      io
* --------------------------------------------------------------------------*/


#include "bios_base.h"
#include "os_io.h"

#define OSC_CLK_4MHZ 0
#define OSC_CLK_8MHZ 1


/** \ingroup io
*   \brief           List of used pin names
* --------------------------------------------------------------------------*
*                    All the used pin names are inserted in this table.
*                    IMPORTANT: The order of the pins has to be the same as
*                    in #os_port_pin!
* --------------------------------------------------------------------------*/
enum {
DI_87                 =0,
DI_87A                ,
DI_C                  ,
DI_X                  ,
DI_15                 ,
DI_CAN_ERR_N          ,
OS_PORT_INPUT_PIN_MAX ,
DO_87                 ,
DO_87A                ,
DO_C                  ,
DO_X                  ,
DO_POWER              ,
DO_CAN_EN             ,
DO_CAN_STB_N          ,
DO_CAN_WAKE           ,
DO_CS_DIS             ,
OS_PORT_PIN_MAX       
};




typedef struct {
  uint16_t name;
  uint16_t port;
  uint8_t bit;
  uint8_t direction;
  uint8_t pullup;
  uint8_t pull_enable;
  uint8_t int_edge;
  uint8_t int_enable;
  uint8_t value;
  uint8_t hi_entprell_cnt;
  uint8_t lo_entprell_cnt;
  uint8_t multiplex;
  uint8_t inverted;
}os_port_pin_def;

extern const os_port_pin_def os_port_pin[];




/** \ingroup io
*   \brief           List of analog pins
* --------------------------------------------------------------------------*
*                    All the used analog pins are inserted in this table.
*                    IMPORTANT: The order of the pins has to be the same as
*                    in #os_analog_pin!
* --------------------------------------------------------------------------*/
enum {
AI_87                 =0,
AI_87A                ,
AI_C                  ,
AI_X                  ,
AI_15                 ,
AI_POTI               ,
AI_I_87               ,
AI_I_87A              ,
AI_I_C                ,
AI_I_X                ,
ANA_TEMP              ,
OS_ANALOG_PIN_MAX     
};




typedef struct {
  uint16_t name;
  uint8_t  adc_channel;
  uint8_t  direction;
  uint16_t value;
  uint16_t min;
  uint16_t max;
  uint8_t  error_filter;
  uint8_t  entprell_cnt;
  uint16_t adc_max;
  uint8_t  multiplex;
  uint8_t  multiplex_type;
  uint8_t  parameter1;   // e.g. HSD number to calculate calibration value of current flow
  uint8_t  samples;   
}os_analog_pin_def;

extern const os_analog_pin_def os_analog_pin[];


/** \ingroup io
*   \brief           List of PWM pins
* --------------------------------------------------------------------------*
*                    All the used PWM pins are inserted in this table.
*                    IMPORTANT: The order of the pins has to be the same as
*                    in #os_pwm_pin!
* --------------------------------------------------------------------------*/
enum {
PWM_87                =0,
PWM_87A               ,
PWM_C                 ,
PWM_X                 ,
OS_PWM_PIN_MAX        
};



typedef struct {
  uint8_t  name;
  uint8_t  timer_channel;
  uint8_t  pulse_type;
  uint8_t  init_type;
  uint8_t  adc_active;
  uint8_t  adc_channel;
  uint16_t adc_max_volt;
  uint8_t  adc_filter;
  uint8_t  adc_startbed;
  uint8_t  digout_vorw;
  uint8_t  digout_rueckw;
  uint16_t current_max;
  uint8_t  digout_index;
}os_pwm_pin_def;

extern const os_pwm_pin_def os_pwm_pin[];



/** \ingroup io
*   \brief           List of EEPROM_INDEX
* --------------------------------------------------------------------------*
*                    Enum for EEPROM_INDEX instead of numbers
* --------------------------------------------------------------------------*/

// Nothing defined


/** \ingroup io
*   \brief           List of USERVAR_INDEX
* --------------------------------------------------------------------------*
*                    Enum for USERVAR_INDEX instead of numbers
* --------------------------------------------------------------------------*/

// Nothing defined


extern const uint8_t bios_osc_clk;

extern const uint8_t modul_geraetetyp_nr;

#define MACRO_MODUL_GERAETETYP_NR 0

#define HSDDATENSATZ_SIZE_DYNAMIC 33

//#define USER_VARIABLE_SIZE_DYNAMIC 10

#define IO_DEF_FILENAME "uSPS_CAN_4IO_A"

#endif

