#ifndef _CAN_DB_H_
#define _CAN_DB_H_




#include "can_db_tables.h"
#include "os.h"



#define FLOAT   0x24
#define ULONG   0x04
#define SLONG   0x14
#define UINT    0x02
#define SINT    0x12
#define UBYTE   0x01
#define SBYTE   0x11

#define CAN_NO_EEPROM_INIT 255
#define CAN_INIT_EEPROM_SIZE 20


#define ADDR_NORM 0
#define ADDR_EXT  1

#define DF_INTEL    0
#define DF_MOTOROLA 1


typedef struct {
  uint32 can_id;                  
  uint8  can_id_ext;              
  uint32 zykluszeit_ms_max;       
  uint32 zykluszeit_ms_min;       
  uint8  msg_len_dlc;             
  uint8  tx;		                  
  uint32 can_id_mask;             
} can_block_db_const_typ;

extern volatile const can_block_db_const_typ *can_block_db_const[];



typedef struct {
  can_block_id nr_can_block;        
  uint8  pos_bit_0;                            
  uint8  bit_laenge;                          
  uint8  datentyp;                             
  uint8  data_format;               
} can_datenpunkt_db_const_typ;



extern volatile const can_datenpunkt_db_const_typ *can_datenpunkt_db_const[];





typedef struct {
  uint8  last_data[8];          
  uint32 time_stamp_read;
  uint32 time_stamp_write;
  uint8  received;
  uint32 time_stamp_transmit;
  uint8  transmit;               
  uint8  transmit_stop;          
  bios_can_msg_typ msg;
} can_block_db_ram_typ;
extern can_block_db_ram_typ *can_block_db_ram[];




void can_db_init(uint8 bus_nr);



void can_db_set_value(uint8 bus_nr, uint32 name_signal, uint32 wert_int);



uint32 can_db_get_value(uint8 bus_nr, uint32 name_signal);



uint8 can_db_test_dp_value(uint8 bus_nr, uint32 id);



uint32 can_db_get_value_on_change(uint8 bus_nr, uint32 id, uint8* changed);



uint8* can_db_get_block_ptr(uint8 bus_nr, uint32 id);



uint8 can_db_block_received(uint8 bus_nr, uint32 id, uint8 reset);



uint8 can_db_input_from_bus(uint8 bus_nr);

#pragma CODE_SEG DEFAULT_ROM2

void can_input_block_to_db(uint8 bus_nr, bios_can_msg_typ* msg);



uint8 can_db_output_to_bus(void);

#pragma CODE_SEG DEFAULT

void can_db_set_transmit_flag(uint8 bus_nr, uint32 id );



void can_db_transmit_deactivate(uint8 status);



uint32 get_value_from_can_block(uint8* data_can_block, uint8 startbit, uint8 laenge, uint8 data_format, uint8 data_type);



void can_create_mask_simple(uint32* mask, uint32* filter, uint8 *mask_division);



void can_create_mask(uint8 bus_nr, uint32* mask, uint32* filter, uint8 *mask_division) ;



void dyn_can_create_mask(uint8 bus_nr, uint32* mask, uint32* filter, uint8 *mask_division, uint32 *addr_id,  uint32 *addr_mask, uint8 block_max);



void bubblesort(uint32 *array1, uint32 *array2, uint16 length);



void can_db_set_listen_only_mode(uint8_t p_listen_only_active);

#endif

