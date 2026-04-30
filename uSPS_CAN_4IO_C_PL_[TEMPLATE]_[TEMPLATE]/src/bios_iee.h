
#ifndef __IEE1
#define __IEE1


#include "bios_PE_Types.h"
#include "bios_PE_Error.h"
#include "bios_PE_Const.h"

#ifdef HCS08DZ128_ACTIVE
    #include <MC9S08DZ128.H>
    #define EEPROM                0x3C00U     
#elif defined HCS08DZ48_ACTIVE
    #include <MC9S08DZ48.H>
    #define EEPROM                0x1500U     
#else
    #include <MC9S08DZ60.H>
    #define EEPROM                0x1400U     
#endif

#include "bios_Cpu.h"



#ifdef HCS08DZ48_ACTIVE
    #define IEE1_EEPROMPageSize   0x0300U     
    #define IEE1_EEPROMSize       0x0600U     
#else
    #define IEE1_EEPROMPageSize   0x0400U     
    #define IEE1_EEPROMSize       0x0800U     
#endif

#define IEE1_EEPROMPageFlip   EEPROM+IEE1_EEPROMPageSize




#ifndef __BWUserType_IEE1_TAddress
#define __BWUserType_IEE1_TAddress
  typedef word IEE1_TAddress;          
#endif


byte WriteBlock(IEE1_TAddress src, IEE1_TAddress dst, word size);

byte IEE1_SetByte(IEE1_TAddress Addr,byte Data);
byte IEE1_SetData(IEE1_TAddress Addr,byte *Data,word len_data);

byte IEE1_GetByte(IEE1_TAddress Addr,byte *Data);
byte IEE1_GetData(IEE1_TAddress Addr,byte *Data, word len_data );

void IEE1_Init(void);

extern uint32 Start_wait(uint32 y);


#endif

