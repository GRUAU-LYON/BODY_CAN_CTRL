#ifndef _BIOS_I2C_H_
#define _BIOS_I2C_H_
#include "bios_base.h"
#include "bios_cpu.h"
#include "bios.h"
#define MC9S08DZ60  






#ifdef MC9S08DZ60
    #define USE_I2C1               

    #define SCL1_ON_PTF2_SDA1_ON_PTF3 



    #define I2C1_BAUD_CLK_RATE   0x16 
    #define I2C1_BAUD_MULTIPLIER 0x01 


    #define I2C1_SLAVE_ADR 0x00 

    #define I2C1_RX_TX_TIMEOUT  50000

    #define I2C1_SEND_DELAY_AKTIV
    #define I2C1_SEND_DELAY 25

    #ifdef SCL1_ON_PTF2_SDA1_ON_PTF3 
        #define I2C1_PORT_SDA PTFD_PTFD3
        #define I2C1_PORT_SCL PTFD_PTFD2
        #define I2C1_DDR_SDA  PTFDD_PTFDD3
        #define I2C1_DDR_SCL  PTFDD_PTFDD2
    #endif 

    #ifdef SCL1_ON_PTE4_SDA1_ON_PTE5 
        #define I2C1_PORT_SDA PTED_PTED5
        #define I2C1_PORT_SCL PTED_PTED4
        #define I2C1_DDR_SDA  PTEDD_PTEDD5
        #define I2C1_DDR_SCL  PTEDD_PTEDD4
    #endif


    #ifdef HCS08DZ128_ACTIVE

        #define  I2C1_CR1           IIC1C1           
        #define  I2C1_CR2           IIC1C2           
        #define  I2C1_ADR           IIC1A            
        #define  I2C1_FDR           IIC1F            
        #define  I2C1_SR            IIC1S            
        #define  I2C1_DR            IIC1D            

        #define  I2C1_FDR_MULT      IIC1F_MULT      
        #define  I2C1_FDR_ICR       IIC1F_ICR       

        #define  I2C1_CR1_I2CEN     IIC1C1_IICEN     
        #define  I2C1_CR1_I2CIE     IIC1C1_IICIE     
        #define  I2C1_CR1_TX_RX     IIC1C1_TX        
        #define  I2C1_CR1_MS_SL     IIC1C1_MST       
        #define  I2C1_CR1_TXAK      IIC1C1_TXAK      
        #define  I2C1_CR1_RSTA      IIC1C1_RSTA      

        #define  I2C1_SR_TCF        IIC1S_TCF        
        #define  I2C1_SR_IAAS       IIC1S_IAAS       
        #define  I2C1_SR_BUSY       IIC1S_BUSY       
        #define  I2C1_SR_ARBL       IIC1S_ARBL       
        #define  I2C1_SR_SRW        IIC1S_SRW        
        #define  I2C1_SR_IF         IIC1S_IICIF      
        #define  I2C1_SR_RXAK       IIC1S_RXAK       

    #else


        #define  I2C1_CR1           IICC1           
        #define  I2C1_CR2           IICC2           
        #define  I2C1_ADR           IICA            
        #define  I2C1_FDR           IICF            
        #define  I2C1_SR            IICS            
        #define  I2C1_DR            IICD            

        #define  I2C1_FDR_MULT      IICF_MULT      
        #define  I2C1_FDR_ICR       IICF_ICR       

        #define  I2C1_CR1_I2CEN     IICC1_IICEN     
        #define  I2C1_CR1_I2CIE     IICC1_IICIE     
        #define  I2C1_CR1_TX_RX     IICC1_TX        
        #define  I2C1_CR1_MS_SL     IICC1_MST       
        #define  I2C1_CR1_TXAK      IICC1_TXAK      
        #define  I2C1_CR1_RSTA      IICC1_RSTA      

        #define  I2C1_SR_TCF        IICS_TCF        
        #define  I2C1_SR_IAAS       IICS_IAAS       
        #define  I2C1_SR_BUSY       IICS_BUSY       
        #define  I2C1_SR_ARBL       IICS_ARBL       
        #define  I2C1_SR_SRW        IICS_SRW        
        #define  I2C1_SR_IF         IICS_IICIF      
        #define  I2C1_SR_RXAK       IICS_RXAK       

    #endif

#endif


#ifdef MC9S08QE128
    #define USE_I2C1               

    #define SCL1_ON_PTA3_SDA1_ON_PTA2 

    #define I2C1_BAUD_CLK_RATE   0x1B 
    #define I2C1_BAUD_MULTIPLIER 0x01 

    #define I2C1_SLAVE_ADR 0x00 

    #define I2C1_RX_TX_TIMEOUT  50000

    #define I2C1_SEND_DELAY_AKTIV
    #define I2C1_SEND_DELAY 25
    #ifdef SCL1_ON_PTA3_SDA1_ON_PTA2 
        #define I2C1_PORT_SDA PTAD_PTAD2
        #define I2C1_PORT_SCL PTAD_PTAD3
        #define I2C1_DDR_SDA  PTADD_PTADD2
        #define I2C1_DDR_SCL  PTADD_PTADD3
    #endif

    #ifdef SCL1_ON_PTB6_SDA1_ON_PTB7 
        #define I2C1_PORT_SDA PTBD_PTBD6
        #define I2C1_PORT_SCL PTBD_PTBD7
        #define I2C1_DDR_SDA  PTBDD_PTBDD6
        #define I2C1_DDR_SCL  PTBDD_PTBDD7
    #endif


    #define  I2C1_CR1           IIC1C1          
    #define  I2C1_CR2           IIC1C2          
    #define  I2C1_ADR           IIC1A           
    #define  I2C1_FDR           IIC1F           
    #define  I2C1_SR            IIC1S           
    #define  I2C1_DR            IIC1D           

    #define  I2C1_FDR_MULT      IIC1F_MULT      
    #define  I2C1_FDR_ICR       IIC1F_ICR       

    #define  I2C1_CR1_I2CEN     IIC1C1_IICEN    
    #define  I2C1_CR1_I2CIE     IIC1C1_IICIE    
    #define  I2C1_CR1_TX_RX     IIC1C1_TX       
    #define  I2C1_CR1_MS_SL     IIC1C1_MST      
    #define  I2C1_CR1_TXAK      IIC1C1_TXAK     
    #define  I2C1_CR1_RSTA      IIC1C1_RSTA     

    #define  I2C1_SR_TCF        IIC1S_TCF       
    #define  I2C1_SR_IAAS       IIC1S_IAAS      
    #define  I2C1_SR_BUSY       IIC1S_BUSY      
    #define  I2C1_SR_ARBL       IIC1S_ARBL      
    #define  I2C1_SR_SRW        IIC1S_SRW       
    #define  I2C1_SR_IF         IIC1S_IICIF     
    #define  I2C1_SR_RXAK       IIC1S_RXAK      


    #define I2C2_BAUD_CLK_RATE   0x1B 
    #define I2C2_BAUD_MULTIPLIER 0x01 

    #define I2C2_SLAVE_ADR 0x00 

    #define I2C2_RX_TX_TIMEOUT  50000

    #define I2C2_SEND_DELAY_AKTIV
    #define I2C2_SEND_DELAY 25

    #define I2C2_PORT_SDA PTAD_PTAD2
    #define I2C2_PORT_SCL PTAD_PTAD3
    #define I2C2_DDR_SDA  PTADD_PTADD2
    #define I2C2_DDR_SCL  PTADD_PTADD3


    #define  I2C2_CR1           IIC2C1          
    #define  I2C2_CR2           IIC2C2          
    #define  I2C2_ADR           IIC2A           
    #define  I2C2_FDR           IIC2F           
    #define  I2C2_SR            IIC2S           
    #define  I2C2_DR            IIC2D           

    #define  I2C2_FDR_MULT      IIC1F_MULT      
    #define  I2C2_FDR_ICR       IIC1F_ICR       

    #define  I2C2_CR1_I2CEN     IIC2C1_IICEN    
    #define  I2C2_CR1_I2CIE     IIC2C1_IICIE    
    #define  I2C2_CR1_TX_RX     IIC2C1_TX       
    #define  I2C2_CR1_MS_SL     IIC2C1_MST      
    #define  I2C2_CR1_TXAK      IIC2C1_TXAK     
    #define  I2C2_CR1_RSTA      IIC2C1_RSTA     

    #define  I2C2_SR_TCF        IIC2S_TCF       
    #define  I2C2_SR_IAAS       IIC2S_IAAS      
    #define  I2C2_SR_BUSY       IIC2S_BUSY      
    #define  I2C2_SR_ARBL       IIC2S_ARBL      
    #define  I2C2_SR_SRW        IIC2S_SRW       
    #define  I2C2_SR_IF         IIC2S_IICIF     
    #define  I2C2_SR_RXAK       IIC2S_RXAK      
#endif


#ifdef MC9S12XDT512

    #define USE_I2C1               

    #define I2C1_BAUD_CLK_RATE   0x96 

    #define I2C1_SLAVE_ADR 0x00 

    #define I2C1_RX_TX_TIMEOUT  50000

    #define I2C1_SEND_DELAY_AKTIV
    #define I2C1_SEND_DELAY 25

    #define I2C1_PORT_SDA   PTJ_PTJ6
    #define I2C1_PORT_SCL   PTJ_PTJ7
    #define I2C1_DDR_SDA    DDRJ_DDRJ6
    #define I2C1_DDR_SCL    DDRJ_DDRJ7


    #define  I2C1_CR1           IIC0_IBCR       
    #define  I2C1_ADR           IIC0_IBAD       
    #define  I2C1_FDR           IIC0_IBFD       
    #define  I2C1_SR            IIC0_IBSR       
    #define  I2C1_DR            IIC0_IBDR       

    #define  I2C1_CR1_I2CEN     IIC0_IBCR_IBEN  
    #define  I2C1_CR1_I2CIE     IIC0_IBCR_IBIE  
    #define  I2C1_CR1_TX_RX     IIC0_IBCR_TX_RX 
    #define  I2C1_CR1_MS_SL     IIC0_IBCR_MS_SL 
    #define  I2C1_CR1_TXAK      IIC0_IBCR_TXAK  
    #define  I2C1_CR1_RSTA      IIC0_IBCR_RSTA  

    #define  I2C1_SR_TCF        IIC0_IBSR_TCF   
    #define  I2C1_SR_IAAS       IIC0_IBSR_IAAS  
    #define  I2C1_SR_BUSY       IIC0_IBSR_IBB   
    #define  I2C1_SR_ARBL       IIC0_IBSR_IBAL  
    #define  I2C1_SR_SRW        IIC0_IBSR_SRW   
    #define  I2C1_SR_IF         IIC0_IBSR_IBIF  
    #define  I2C1_SR_RXAK       IIC0_IBSR_RXAK  

#endif


#ifdef MC9S12XEQ512

    #define USE_I2C1               
    #define USE_I2C2               

    #define SCL1_ON_PTJ7_SDA1_ON_PTJ6

    #define I2C1_BAUD_CLK_RATE   0x63 

    #define I2C1_SLAVE_ADR 0x00 

    #define I2C1_RX_TX_TIMEOUT  50000

    #define I2C1_SEND_DELAY_AKTIV
    #define I2C1_SEND_DELAY 25

    #ifdef SCL1_ON_PTJ7_SDA1_ON_PTJ6 
        #define I2C1_PORT_SDA PTJ_PTJ6
        #define I2C1_PORT_SCL PTJ_PTJ7
        #define I2C1_DDR_SDA  DDRJ_DDRJ6
        #define I2C1_DDR_SCL  DDRJ_DDRJ7
    #endif

    #ifdef SCL1_ON_PTF5_SDA1_ON_PTF4 
        #define I2C1_PORT_SDA PTF_PTF4
        #define I2C1_PORT_SCL PTF_PTF5
        #define I2C1_DDR_SDA  DDRF_DDRF4
        #define I2C1_DDR_SCL  DDRF_DDRF5
    #endif


    #define  I2C1_CR1           IIC0_IBCR       
    #define  I2C1_CR2           IIC0_IBCR2          
    #define  I2C1_ADR           IIC0_IBAD       
    #define  I2C1_FDR           IIC0_IBFD       
    #define  I2C1_SR            IIC0_IBSR       
    #define  I2C1_DR            IIC0_IBDR       

    #define  I2C1_CR1_I2CEN     IIC0_IBCR_IBEN  
    #define  I2C1_CR1_I2CIE     IIC0_IBCR_IBIE  
    #define  I2C1_CR1_TX_RX     IIC0_IBCR_TX_RX 
    #define  I2C1_CR1_MS_SL     IIC0_IBCR_MS_SL 
    #define  I2C1_CR1_TXAK      IIC0_IBCR_TXAK  
    #define  I2C1_CR1_RSTA      IIC0_IBCR_RSTA  

    #define  I2C1_SR_TCF        IIC0_IBSR_TCF   
    #define  I2C1_SR_IAAS       IIC0_IBSR_IAAS  
    #define  I2C1_SR_BUSY       IIC0_IBSR_IBB   
    #define  I2C1_SR_ARBL       IIC0_IBSR_IBAL  
    #define  I2C1_SR_SRW        IIC0_IBSR_SRW   
    #define  I2C1_SR_IF         IIC0_IBSR_IBIF  
    #define  I2C1_SR_RXAK       IIC0_IBSR_RXAK  


    #define I2C2_BAUD_CLK_RATE   0x63 

    #define I2C2_SLAVE_ADR 0x00 

    #define I2C2_RX_TX_TIMEOUT  50000

    #define I2C2_SEND_DELAY_AKTIV
    #define I2C2_SEND_DELAY 25

    #define I2C2_PORT_SDA PTJ_PTJ4
    #define I2C2_PORT_SCL PTJ_PTJ5
    #define I2C2_DDR_SDA  DDRJ_DDRJ4
    #define I2C2_DDR_SCL  DDRJ_DDRJ5


    #define  I2C2_CR1           IIC1_IBCR       
    #define  I2C2_CR2           IIC1_IBCR2      
    #define  I2C2_ADR           IIC1_IBAD       
    #define  I2C2_FDR           IIC1_IBFD       
    #define  I2C2_SR            IIC1_IBSR       
    #define  I2C2_DR            IIC1_IBDR       

    #define  I2C2_CR1_I2CEN     IIC1_IBCR_IBIE  
    #define  I2C2_CR1_I2CIE     IIC1_IBCR_IBEN  
    #define  I2C2_CR1_TX_RX     IIC1_IBCR_TX_RX 
    #define  I2C2_CR1_MS_SL     IIC1_IBCR_MS_SL 
    #define  I2C2_CR1_TXAK      IIC1_IBCR_TXAK  
    #define  I2C2_CR1_RSTA      IIC1_IBCR_RSTA  

    #define  I2C2_SR_TCF        IIC1_IBSR_TCF   
    #define  I2C2_SR_IAAS       IIC1_IBSR_IAAS  
    #define  I2C2_SR_BUSY       IIC1_IBSR_IBB   
    #define  I2C2_SR_ARBL       IIC1_IBSR_IBAL  
    #define  I2C2_SR_SRW        IIC1_IBSR_SRW   
    #define  I2C2_SR_IF         IIC1_IBSR_IBIF  
    #define  I2C2_SR_RXAK       IIC1_IBSR_RXAK  
#endif



#if defined  MC9S08DZ60  || defined MC9S08QE128
    #define I2C_WATCHDOG_RESET bios_reset_watchdog();
#endif  
#if defined  MC9S12XDT512  || defined MC9S12XEQ512
    #define I2C_WATCHDOG_RESET WATCHDOG_ON_OFF(); 
#endif


#define BIOS_I2C_ARBITRATION_LOST        0x01
#define BIOS_I2C_BYTE_TRANSFER_COMPLETE  0x02
#define BIOS_I2C_RCV_ADDR_MATCH          0x03


#define BIOS_I2C_ERR_OK                0
#define BIOS_I2C_ERR_NO_ACK            1
#define BIOS_I2C_ERR_ARBITRATION_LOST  2
#define BIOS_I2C_ERR_TIMEOUT           3


#define BIOS_I2C_TX_BUFFER_SIZE   50
#define BIOS_I2C_RX_BUFFER_SIZE   50


typedef struct
{
  uint8 tx_buffer[BIOS_I2C_TX_BUFFER_SIZE];
  uint8 rx_buffer[BIOS_I2C_RX_BUFFER_SIZE];
  uint8 tx_count;
  uint8 tx_restart_count;
  uint8 rx_count;
  uint8 rx_dummy_read;
  uint8 rx_tx_busy;
  uint8 first_byte_ack;
  uint8 error;
}bios_i2c_conf_typ;


extern bios_i2c_conf_typ bios_i2c;



void bios_i2c1_init(void);

void bios_i2c2_init(void);

void bios_i2c1_generate_9stops (void);

void bios_i2c2_generate_9stops (void);

void bios_i2c1_interrupt_ack(void);

void bios_i2c2_interrupt_ack(void);

uint8 bios_i2c1_get_interrupt_src(void);

uint8 bios_i2c2_get_interrupt_src(void);

void bios_i2c1_bus_handler(void);

void bios_i2c2_bus_handler(void);

void bios_i2c1_rx_tx(void);

void bios_i2c2_rx_tx(void);

void bios_i2c1_wait_on_rx_tx (void);

void bios_i2c2_wait_on_rx_tx (void);


#if defined  MC9S12XDT512  || defined MC9S12XEQ512

    #pragma CODE_SEG __NEAR_SEG NON_BANKED
    __interrupt void I2C1_Interrupt(void);
    __interrupt void I2C2_Interrupt(void);
    #pragma CODE_SEG DEFAULT
#endif

#endif
