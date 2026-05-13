#ifndef _BIOS_EE_FLASH_H_
#define _BIOS_EE_FLASH_H_

#include "bios_base.h"





#ifdef EE_FLASH_EMULATION_ACTIVE


#define BIOS_FLASH_SEG_EEPROM        0x1900
#define BIOS_FLASH_LAENGE_EEPROM     0x0300
#define BIOS_MAX_RAM_BLOCK_SIZE      0x0100 


#define BIOS_RAM_ADRESS_BEREICH_UEBERSCHRITTEN 1
#define BIOS_FLASH_SCHREIB_FEHLER 2



typedef struct
{
   const uint8* flash_ptr;
   const uint8* ram_ptr;
   uint16 flash_block_size;
   uint16 max_ram_block_size;
   uint16 ram_block_size;
}bios_ee_config_typ;


#endif

void bios_flash_wb(uint8* Data_ptr, uint8 data);



void bios_flash_clr(uint8* Data_ptr);


void bios_init_flash(void);


#endif
