#ifndef _BIOS_SPI_H_
#define _BIOS_SPI_H_

#include "bios_base.h"
#include "bios_cpu.h"



#define SS1_INP_BUF_SIZE 0x04          
#define SS1_OUT_BUF_SIZE 0x04          




#define BIOS_SPI_MODE_0                  0
#define BIOS_SPI_MODE_3                  3


void bios_spi_slave_init(uint8 spi_mode);


extern byte SS1_OutLen;                
extern byte SS1_InpLen;                
extern char InpBuffer[SS1_INP_BUF_SIZE+5]; 
extern char OutBuffer[SS1_OUT_BUF_SIZE+5]; 

extern byte SS1_InpLen;                               
extern byte SS1_InpFull;                              

extern char bios_spi_inpbuffer[SS1_INP_BUF_SIZE+2];   
extern byte SS1_OutLen;                               
extern char bios_spi_outbuffer[SS1_OUT_BUF_SIZE+2];   



#ifdef HCS08DZ128_ACTIVE

    #define SPI_S       SPI1S
    #define SPI_D       SPI1D
    #define SPI_C1      SPI1C1
    #define SPI_C2      SPI1C2
    #define SPI_C1_SPE  SPI1C1_SPE

#else

    #define SPI_S       SPIS
    #define SPI_D       SPID
    #define SPI_C1      SPIC1
    #define SPI_C2      SPIC2
    #define SPI_C1_SPE  SPIC1_SPE

#endif

#endif
