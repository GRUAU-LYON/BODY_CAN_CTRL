#ifndef _BIOS_TIMER_H_
#define _BIOS_TIMER_H_

#include "bios_base.h"
#include "os_io.h"

#define PWM_TYPE_PROP_CAN       0
#define PWM_TYPE_PROP_CAN_60A   1
#define PWM_TYPE_CAN_IO         2
#define PWM_TYPE_CAN_FULLBRIDGE 3

#define MAX_PWM_CHANNELS  6

#define BUS_CLOCK 20000000UL
#define NR_16BIT  65535UL
#define NR_15BIT  32767UL
#define NR_12BIT  4096UL   


#define TIMER_CHANNEL_MAX 5

#define PRESC_NEXT_HIGHER 0
#define PRESC_NEXT_LOWER  1

#define TPM1_CHANNEL_OFF        0
#define TPM1_CHANNEL_PWM_OUT    1
#define TPM1_CHANNEL_PWM_READ   2

typedef struct {
  uint8  active;
  uint8  edge;  
  uint16 resolution;
  uint8  presc;
  uint16 falling_roh;
  uint16 falling;  
  uint16 rising_roh;
  uint16 rising;
  uint16 duty;  
  uint16 frequency;
  uint32 ti_stamp;  
}bios_tpm1_pwm_read_def;

extern bios_tpm1_pwm_read_def bios_pwm1_read[];


void bios_init_timer(void);



void bios_timer1_channels_init(uint8 channel, uint8 pulse_type, uint8_t active);



void bios_timer1_set_frequency(uint16 frequency);



uint8 power_of_two_8(uint8 val);



void bios_timer1_set_duty_cycle(uint8 channel, uint16 pwm_promille);



void bios_timer1_write_registers(void);



void bios_timer1_interrupt_ack(void);



void bios_timer1_chn_interrupt_ack(uint8 channel);



void bios_timer2_interrupt_ack(void);



void bios_timer1_pwm_read_init(uint8 ch, uint16 pwm_freq, uint16 resolution);



uint8 bios_get_prescaler_value(uint8 presc_val, uint8 mode);


void bios_timer1_pwm_read_calc(uint8 channel);


void bios_pwm_get_values(uint8 ch, uint16 *duty, uint16 *frequency);



#endif
