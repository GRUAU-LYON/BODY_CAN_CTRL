#ifndef _OS_EE_FLASH_H_
#define _OS_EE_FLASH_H_


#include "bios_ee_flash.h"



#ifdef EE_FLASH_EMULATION_ACTIVE

void os_ee_refresh_ram(bios_ee_config_typ const* speicher);



uint8 os_ee_save_ram(bios_ee_config_typ const* speicher);
#endif

#endif
