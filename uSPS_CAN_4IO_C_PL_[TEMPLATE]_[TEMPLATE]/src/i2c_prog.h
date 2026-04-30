#ifndef _I2C_PROG_H_
#define _I2C_PROG_H_

#include "bios_base.h"




extern unsigned int timer1ms;



#define I2C1_EEPROM_READ_DELAY_AKTIV
#define I2C1_EEPROM_READ_DELAY 50

#define I2C2_EEPROM_READ_DELAY_AKTIV
#define I2C2_EEPROM_READ_DELAY 50

void WAIT(void);

unsigned char write_eeprom_i2c1(uint16 Start_Adresse ,unsigned char  buffer[], unsigned char anzahl);

unsigned char read_eeprom_i2c1(uint16 Adresse ,unsigned char  buffer[], unsigned char anzahl);

unsigned char write_eeprom_i2c1(uint16 Start_Adresse ,unsigned char  buffer[], unsigned char anzahl);

unsigned char read_eeprom_i2c1(uint16 Adresse ,unsigned char  buffer[], unsigned char anzahl);

#endif


