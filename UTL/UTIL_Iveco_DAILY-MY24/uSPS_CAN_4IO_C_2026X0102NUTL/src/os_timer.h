#ifndef _OS_TIMER_H_
#define _OS_TIMER_H_

#include "bios_timer.h"
#include "bios.h"
#include "os_io_tables.h"
#include "os.h"




#define OS_1ms    1
#define OS_10ms   2
#define OS_100ms  3
#define OS_1s     4
#define OS_1000ms  4

typedef struct {
  uint16 dither_promille;
  uint16 dither_counts;
  uint16 dither_counts_old;
  uint16 dither_counter;
  uint8  dither_change_cnt;
  uint16 pwm_promille_backup;
  uint16 pwm_frequency_old;
  int8   dither_stat;    
  uint16 analog_average;    
  uint16 duty_cycle;
  uint8  channel_active;
  uint16 pwm_period;  
  uint8  os_analog_index;
  uint8  ready_to_write;
}os_pwm_vals_def;


typedef struct {
  uint32 y_avg_long;
  uint16 y_avg;
  uint32 kp_long;
  uint16 kp;
  uint16 y;
  uint16 w_rampe;  
  int16  error_timer;
  uint8  error_type;
  uint8  m2_checked;
  uint8  m2_timer;  
}os_pwm_control_vals_def;


#define PWM_DUTY_READ_MAX   6
typedef struct 
{
    uint8  active;
    uint16 init_freq;
    uint16 init_res;    
    uint16 duty;
    uint16 frequency;    
}os_pwm_duty_read_def;

extern os_pwm_duty_read_def os_pwm_duty_read[];



void os_timer_tick(uint8 tick);


#pragma CODE_SEG DEFAULT_ROM2


uint32 os_set_timestamp(uint8 precision);


void os_timestamp(uint32* time, uint8 precision);


uint32 os_get_time_past(uint32 time, uint8 precision);


uint8 os_time_past(uint32 time, uint32 value, uint8 precision);


#pragma CODE_SEG DEFAULT


void os_wait(uint32 value);



void os_init_pwm(void);



void os_init_pwm_duty_read(void);



void  os_init_timer_channel(uint8_t channel, uint8_t pulse_type);



void os_pwm_duty_cycle(uint8 i, uint16 pwm_promille, uint16 pwm_frequency, uint16 pwm_dither_promille, uint16 pwm_dither_frequency);



void os_timer1_dither_calculation(void);



void os_pwm_control(uint8 i, uint16 w, uint16 pwm_frequency, uint16 pwm_dither_promille, uint16 pwm_dither_frequency, uint16 rampe, uint16 kp_min, uint16 kp_max, uint16 time_diff, uint16 *kp_calc, uint8 *error);



void os_pwm_motor_control(uint8 i, uint16 w, uint8 w_dir, uint16 pwm_frequency, uint16 time_diff, uint8 m2_trigger, uint8* error_stat);



void os_pwm_all_channels(uint8 i, uint16 duty_cycle, uint16 pwm_frequency);



void os_pwm_TLE62826(uint8 duties_active);


void os_pwm_read_update(void);

uint8_t os_ramp_up_dwn(uint16_t get_in, uint16_t get_maxxi, uint16_t get_ms_pro_100_up, uint16_t get_ms_pro_100_down, uint16_t* get_counter, uint16_t* get_out);


uint8_t os_int_time_past(uint32_t time, uint32_t value, uint8_t precision);


uint32_t os_int_set_timestamp(uint8_t precision);


void os_int_timestamp(uint32_t* time, uint8_t precision);


#endif









