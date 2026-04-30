#ifndef _BIOS_IO_H_
#define _BIOS_IO_H_

#include "bios_base.h"


#define BIOS_NR_OF_PORTS 6

#define PORT_A 	0
#define PORT_B 	1
#define PORT_C 	2
#define PORT_D  3
#define PORT_E 	4
#define PORT_F 	5

typedef uint8* const reg_p ;



#define PD_IN   0
#define PD_OUT  1

#define PU_UP    0
#define PU_DOWN  1

#define PE_ON    1
#define PE_OFF   0

#define PI_RISE  1
#define PI_FALL  0

#define PI_ON    1
#define PI_OFF   0


#define DONT_CARE    23
#define ERR_OFF      0x0
#define ERR_MIN      0x1
#define ERR_MAX  	   0x2
#define ERR_MIN_MAX  0x3

#define HIGH_TRUE   0
#define LOW_TRUE    1

#define PWM_READ_RISING     0   
#define PWM_READ_FALLING    1
#define PWM_READ_RISING_FALLING 2



extern const uint8 bios_bitmask[8];



void bios_init_adc(void);



void bios_enable_adc_channel(uint8 channel);



void bios_analog_select_channel(uint8 channel);



uint16 bios_analog_get_channel(void);



uint16 bios_analog_get_channel_single(void);



uint16 bios_analog_get_channel_value(uint8 channel);


#endif
