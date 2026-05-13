#ifndef _OS_I2C_H_
#define _OS_I2C_H_
#include "bios_base.h"


typedef struct
{
  uint8  weekday;
  uint8  day;
  uint8  month;
  uint8  year;
  uint8  hour;
  uint8  minutes;
  uint8  seconds;
}os_i2c_rtc_date_time_typ;





void os_i2c1_eeprom_write_byte(uint8  device, uint16  address, uint8  value);



uint8  os_i2c1_eeprom_read_byte(uint8  device, uint16  address);


void os_i2c2_eeprom_write_byte(uint8  device, uint16  address, uint8  value);




uint8  os_i2c2_eeprom_read_byte(uint8  device, uint16  address);

void os_i2c1_io_write(uint8 slave_adr, uint8  register_adr, uint8 data_count, uint8* data);

void os_i2c1_io_read(uint8 slave_adr, uint8  register_adr, uint8 data_count, uint8* data);

uint8  os_i2c_get_error(void);




#endif
