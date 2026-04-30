#ifndef _OS_IO_H_
#define _OS_IO_H_


#include "bios_io.h"
#include "os_io_tables.h"


#define CURRENT_30    30
#define CURRENT_100   100
#define CURRENT_2000  2000

#define PORT_INT_FREQ_COUNTER 1
#define PORT_INT_INCR_ENCODER 2
#define PORT_INT_USER_DEF     3
#define PORT_INT_HALL_ENCODER 4

#define EDGE_FALLING  0
#define EDGE_RISING   1

#define PORT_INT_OFF    0
#define PORT_INT_INCR   1
#define PORT_INT_DECR   2

#define MAGIC_NUMBER_WDI        222  
#define MAGIC_NUMBER_IO         223  
#define MAGIC_NUMBER_TEMP       224  
#define MAGIC_NUMBER_INIT       225  
#define MAGIC_NUMBER_RS485_DE   226  


#define NR_MAX_INT16        32767
#define NR_MIN_INT16       -32768

#define LUT_MODE_EXTRAPOLATION      0
#define LUT_MODE_LIMIT              1
#define LUT_MODE_KALIBRATION        2
#define LUT_MODE_EXTRAPOLATION_POS  3

#define BIOS_NULL_P (reg_p)0xFFFF

typedef struct {
  uint8  channel_active;
  uint16 counter;
  uint16 counter_strike;
  uint16 calc_time;
  uint32 time;
  uint16 freq_calc;
  uint16 min;
  uint16 max;
  uint8  overflow;  
  uint8  channel_a;
  uint8  channel_b;
  uint8  state;
  uint8  modi; 
}os_port_int_def;

typedef struct {
  uint8 cnt;
  uint8 busy;
  uint8 multiplex_active;
  uint8 multiplex;
  uint8 multiplex_max;
  uint8 cnt_adc;    
  uint8 temp_ch;
  uint8 adc_simple_flag; 
  uint8 adc_simple_cnt;
  uint8 adc_simple_pwm_io_tick;
}os_adc_vals_def;

typedef struct {
  uint32 number;
  uint8  dot_position;
  uint8  disabled;
}os_seven_segment_vals_def;


extern uint8 os_pin_entprell_cnt[];

extern uint16 os_analog_io_vals[];

extern os_adc_vals_def os_adc_vals;

extern os_seven_segment_vals_def os_seven_segment_vals;

extern uint8 os_pwm_analog_cal_deactivate;

extern os_port_int_def os_port_int_val[];


void os_init_adc(void);



uint16 os_algin(uint8 i);



uint16 os_algin_mv(uint8 i);



uint8 os_algin_err(uint8 i);



void os_analog_io_tick(void);



void os_analog_int(void);



void os_analog_int_start(void);



void os_pin_set_direction(uint16 i,uint8 val);



void os_pin_set_pull_direction(uint16 i, uint8 val);



void os_pin_set_pull_enable(uint16 i,uint8 val);



void os_pin_set_interrupt_edge(uint16 i,uint8 val);



void os_pin_set_interrupt_enable(uint16 i,uint8 val);



void os_pin_write(uint16 i,uint8 val);



uint8 os_pin_read(uint16 i);



void os_port_write(uint16 i,uint8 val);



void os_port_set_direction(uint16 i,uint8 val);



void os_port_set_pull_direction(uint16 i,uint8 val);



void os_port_set_pull_enable(uint16 i,uint8 val);



void os_port_set_interrupt_edge(uint16 i,uint8 val);



void os_port_set_interrupt_enable(uint16 i,uint8 val);



uint8 os_digin(uint16 i);



void os_digout(uint16 i, uint8 value);


#pragma CODE_SEG DEFAULT_ROM2



void os_update_digin(void);



void os_update_digout(void);



void os_init_ports(void);


#pragma CODE_SEG DEFAULT



void os_port_int_increment(void);



uint16 os_frequency_calc(uint8 channel_def);



uint16 os_frequency_calc_get(uint8 channel_def);



uint16 os_frequency_val(uint8 channel_def);



void os_init_frequency_read(uint8_t channel_def);



void os_frequency_read(uint8_t channel_def, uint32_t* measure_period_timestamp, uint16_t* measured_frequency);



uint16 os_incremental_encoder(uint8 mode_type, uint8 channel_def1, uint8 channel_def2, uint16 min, uint16 max);



void os_incremental_encoder_start_value(uint8 mode_type, uint8 channel_def1, uint16 value, uint8 dir);



void os_pwm_analog_io_average(void);






int8_t os_temperature_read(void);


void user_int_port_init( uint8_t channel_def);



#endif

