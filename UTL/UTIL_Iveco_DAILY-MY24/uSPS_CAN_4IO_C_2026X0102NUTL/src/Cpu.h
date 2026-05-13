
#ifndef __Cpu
#define __Cpu


#define PEcfg_DZ60MLH 1


#include "bios_PE_Types.h"
#include "bios_PE_Error.h"
#include "bios_PE_Const.h"

#ifdef HCS08DZ128_ACTIVE
    #include <MC9S08DZ128.H>
#elif defined HCS08DZ48_ACTIVE
    #include <MC9S08DZ48.H>
#else
    #include <MC9S08DZ60.H>
#endif


#ifndef __BWUserType_tPowerDownModes
#define __BWUserType_tPowerDownModes
  typedef enum {                       
    PowerDown,
    PartialPowerDown,
    StandBy
  } tPowerDownModes;
#endif


extern volatile byte CCR_reg;          


__interrupt void Cpu_Interrupt(void);

#define   Cpu_DisableInt()  __DI()     

#define   Cpu_EnableInt()  __EI()      

void PE_low_level_init(void);


void check_ram_test(void);
extern void ram_test(void);

#endif 

