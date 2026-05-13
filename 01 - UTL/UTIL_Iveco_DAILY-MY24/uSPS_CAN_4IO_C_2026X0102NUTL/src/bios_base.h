#ifndef _BIOS_BASE_H_
#define _BIOS_BASE_H_
#include "bios_migration.h"
#include <hidef.h>
#include "derivative.h"
#include "bios_PE_Types.h"



typedef unsigned char  uint8;
typedef signed char     int8;
typedef unsigned int  uint16;
typedef signed int     int16;
typedef unsigned long uint32;
typedef signed long    int32;

#define bios_disable_interrupts() DisableInterrupts
#define bios_enable_interrupts() EnableInterrupts


#define BIOS_MRS_USE_FAR 1  

#ifdef BIOS_MRS_USE_FAR
    #define MRS_FAR __far
#endif

#define CAN_BLOCK_DB_RAM_EXT 1

#ifdef CAN_BLOCK_DB_RAM_EXT
    #define DB_RAM_FAR MRS_FAR
#else
    #define DB_RAM_FAR
#endif


#endif                                               
