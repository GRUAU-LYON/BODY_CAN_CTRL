#ifndef _OS_UTIL_H_
#define _OS_UTIL_H_

#include "bios_base.h"
#include "bios_sci.h"
#include "user_code.h"



#define OS_UTIL_FILTER_LOWPASS_WIDTH  21
#define OS_UTIL_FILTER_MEDIAN_WIDTH  8

#define OS_ADD_VALUE     1
#define OS_FILTER_VALUE  2

#define LUT_MODE_EXTRAPOLATION  0
#define LUT_MODE_LIMIT          1
#define LUT_MODE_KALIBRATION    2
#define LUT_MODE_EXTRAPOLATION_POS  3

#define NR_MAX_INT16    32767
#define NR_MIN_INT16   -32768


uint8 os_util_filter_lowpass_8bit(uint8 mode, uint8 new_val);


uint8 os_util_filter_median_8bit(uint8 new_val);


void main_delay(uint16_t wait);


void *memcpy_far2near(void *dest, const void *__far source, size_t count);


void *__far memcpy_near2far(void *__far dest, const void *source, size_t count);


uint32_t change_intel_to_motorola_32_bit(uint32_t val_in);


void put_signal_value_to_data_block(uint32_t value, uint8_t* DB_RAM_FAR ptr_to_data_block, uint8_t startbit, uint8_t length, uint8_t data_format);


uint32_t get_signal_value_from_data_block(uint8_t* DB_RAM_FAR ptr_to_data_block, uint8_t startbit, uint8_t length, uint8_t data_format);


int16_t os_util_lookup1D(int16_t *table_x, int16_t *table_y, uint8_t count, int16_t val, uint8_t mode);

#define Lookup1D(table_x, table_y, count, val, mode) os_util_lookup1D(table_x, table_y, count, val, mode)



int16_t os_util_lookup2D(int16_t *table_x, int16_t *table_y, uint8_t count_x, uint8_t count_y, int16_t *table_z, int16_t val_x, int16_t val_y);

#define Lookup2D(table_x, table_y, count_x, count_y, table_z, val_x, val_y) os_util_lookup2D(table_x, table_y, count_x, count_y, table_z, val_x, val_y)


void os_util_init(void);



extern void int_rx_sci_first(uint8_t module, uint8_t data);
extern void int_stat_sci_first(uint8_t module);
extern void int_tx_sci_first(uint8_t module);


#endif





