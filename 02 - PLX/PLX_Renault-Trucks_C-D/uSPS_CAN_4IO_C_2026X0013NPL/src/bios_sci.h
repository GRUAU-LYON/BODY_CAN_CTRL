#ifndef _BIOS_SCI_H_
#define _BIOS_SCI_H_

#include "bios_base.h"
#include "bios_cpu.h"
#include "modbus.h"



typedef enum
{
    BIOS_SCI1 = 0,
    BIOS_SCI2,
    BIOS_SCI_MODULES_MAX
} enum_bios_sci_modules_t;

typedef struct type_bios_sci_module
{
    uint8_t* SCIBDL;
    uint8_t* SCIBDH;
    uint8_t* SCICR1;
    uint8_t* SCICR2;
    uint8_t* SCICR3;
    uint8_t* SCISR1;
    uint8_t* SCISR2;
    uint8_t* SCID;
};

extern const struct type_bios_sci_module bios_sci_reg[BIOS_SCI_MODULES_MAX];


#define CPU_BUSCLK  20000000UL     


#define BIOS_SCI_BAUDRATE_CALC_REG(baud)  (uint16_t)((CPU_BUSCLK + (8UL * (baud))) / (16UL * (baud)) )


#define BIOS_SCI1_INT_TX_COMPLETE_ENABLED       0

#define BIOS_SCI1_INT_RDR_FULL_ENABLED          1
#define BIOS_SCI1_INT_IDLE_LINE_ENABLED         0
#define BIOS_SCI1_INT_RX_OVERRUN_ENABLED        0
#define BIOS_SCI1_INT_RX_ACTIVE_EDGE_ENABLED    0
#define BIOS_SCI1_INT_RX_BREAK_DETECT_ENABLED   0
#define BIOS_SCI1_INT_RX_NOISE_ENABLED          0
#define BIOS_SCI1_INT_RX_FRAMING_ERROR_ENABLED  0
#define BIOS_SCI1_INT_RX_PARITY_ERROR_ENABLED   0

#define BIOS_SCI1_RX_INT_MODE ( (BIOS_SCI1_INT_RDR_FULL_ENABLED         <<0) | \
                                (BIOS_SCI1_INT_IDLE_LINE_ENABLED        <<1) | \
                                (BIOS_SCI1_INT_RX_OVERRUN_ENABLED       <<2) | \
                                (BIOS_SCI1_INT_RX_ACTIVE_EDGE_ENABLED   <<3) | \
                                (BIOS_SCI1_INT_RX_BREAK_DETECT_ENABLED  <<4) | \
                                (BIOS_SCI1_INT_RX_NOISE_ENABLED         <<5) | \
                                (BIOS_SCI1_INT_RX_FRAMING_ERROR_ENABLED <<6) | \
                                (BIOS_SCI1_INT_RX_PARITY_ERROR_ENABLED  <<7) )

#define BIOS_SCI1_TX_INT_MODE ( (BIOS_SCI1_INT_TX_COMPLETE_ENABLED      <<0) )

#define BIOS_SCI2_INT_TX_COMPLETE_ENABLED       0

#define BIOS_SCI2_INT_RDR_FULL_ENABLED          1
#define BIOS_SCI2_INT_IDLE_LINE_ENABLED         0
#define BIOS_SCI2_INT_RX_OVERRUN_ENABLED        1
#define BIOS_SCI2_INT_RX_ACTIVE_EDGE_ENABLED    0
#define BIOS_SCI2_INT_RX_BREAK_DETECT_ENABLED   0
#define BIOS_SCI2_INT_RX_NOISE_ENABLED          0
#define BIOS_SCI2_INT_RX_FRAMING_ERROR_ENABLED  0
#define BIOS_SCI2_INT_RX_PARITY_ERROR_ENABLED   0

#define BIOS_SCI2_RX_INT_MODE ( (BIOS_SCI2_INT_RDR_FULL_ENABLED         <<0) | \
                                (BIOS_SCI2_INT_IDLE_LINE_ENABLED        <<1) | \
                                (BIOS_SCI2_INT_RX_OVERRUN_ENABLED       <<2) | \
                                (BIOS_SCI2_INT_RX_ACTIVE_EDGE_ENABLED   <<3) | \
                                (BIOS_SCI2_INT_RX_BREAK_DETECT_ENABLED  <<4) | \
                                (BIOS_SCI2_INT_RX_NOISE_ENABLED         <<5) | \
                                (BIOS_SCI2_INT_RX_FRAMING_ERROR_ENABLED <<6) | \
                                (BIOS_SCI2_INT_RX_PARITY_ERROR_ENABLED  <<7) )

#define BIOS_SCI2_TX_INT_MODE ( (BIOS_SCI2_INT_TX_COMPLETE_ENABLED      <<0) )

#define BIOS_SCI_MODUL_DEFAULT        1



#define BIOS_SCI_4800_BAUD            4800
#define BIOS_SCI_9600_BAUD            9600
#define BIOS_SCI_19200_BAUD           19200
#define BIOS_SCI_28800_BAUD           28800
#define BIOS_SCI_38400_BAUD           38400
#define BIOS_SCI_115200_BAUD          115200


#define BIOS_SCI_8N1                  1
#define BIOS_SCI_9N1                  2

#define BIOS_SCI_PARITY_EVEN          0
#define BIOS_SCI_PARITY_ODD           1

#define BIOS_SCI_SET_BREAK_LEN                      0
#define BIOS_SCI_SET_BREAK_LEN_AND_INT_DETECTION    1

#define BIOS_SCI_BREAK_LEN_10_11      0
#define BIOS_SCI_BREAK_LEN_13_14      1

#define BIOS_SCI_INT_TX_COMPLETE        (uint8_t)0x01

#define BIOS_SCI_INT_RDR_FULL           (uint8_t)0x01
#define BIOS_SCI_INT_IDLE_LINE          (uint8_t)0x02
#define BIOS_SCI_INT_RX_OVERRUN         (uint8_t)0x04
#define BIOS_SCI_INT_RX_ACTIVE_EDGE     (uint8_t)0x08
#define BIOS_SCI_INT_RX_BREAK_DETECT    (uint8_t)0x10
#define BIOS_SCI_INT_RX_NOISE           (uint8_t)0x20
#define BIOS_SCI_INT_RX_FRAMING_ERROR   (uint8_t)0x40
#define BIOS_SCI_INT_RX_PARITY_ERROR    (uint8_t)0x80



#define BIOS_SCI_BD_SBR0_MASK               SCI1BDL_SBR0_MASK
#define BIOS_SCI_BD_SBR1_MASK               SCI1BDL_SBR1_MASK
#define BIOS_SCI_BD_SBR2_MASK               SCI1BDL_SBR2_MASK
#define BIOS_SCI_BD_SBR3_MASK               SCI1BDL_SBR3_MASK
#define BIOS_SCI_BD_SBR4_MASK               SCI1BDL_SBR4_MASK
#define BIOS_SCI_BD_SBR5_MASK               SCI1BDL_SBR5_MASK
#define BIOS_SCI_BD_SBR6_MASK               SCI1BDL_SBR6_MASK
#define BIOS_SCI_BD_SBR7_MASK               SCI1BDL_SBR7_MASK

#define BIOS_SCI_BD_SBR8_MASK               SCI1BDH_SBR8_MASK
#define BIOS_SCI_BD_SBR9_MASK               SCI1BDH_SBR9_MASK
#define BIOS_SCI_BD_SBR10_MASK              SCI1BDH_SBR10_MASK
#define BIOS_SCI_BD_SBR11_MASK              SCI1BDH_SBR11_MASK
#define BIOS_SCI_BD_SBR12_MASK              SCI1BDH_SBR12_MASK
#define BIOS_SCI_BD_RXEDGIE_MASK            SCI1BDH_RXEDGIE_MASK
#define BIOS_SCI_BD_LBKDIE_MASK             SCI1BDH_LBKDIE_MASK
#define BIOS_SCI_BD_SBR_MASK                SCI1BDH_SBR_8_MASK
#define BIOS_SCI_BD_SBR_BITNUM              SCI1BDH_SBR_8_BITNUM


#define BIOS_SCI_CR1_PT_MASK                SCI1C1_PT_MASK
#define BIOS_SCI_CR1_PE_MASK                SCI1C1_PE_MASK
#define BIOS_SCI_CR1_ILT_MASK               SCI1C1_ILT_MASK
#define BIOS_SCI_CR1_WAKE_MASK              SCI1C1_WAKE_MASK
#define BIOS_SCI_CR1_M_MASK                 SCI1C1_M_MASK
#define BIOS_SCI_CR1_RSRC_MASK              SCI1C1_RSRC_MASK
#define BIOS_SCI_CR1_SCISWAI_MASK           SCI1C1_SCISWAI_MASK
#define BIOS_SCI_CR1_LOOPS_MASK             SCI1C1_LOOPS_MASK

#define BIOS_SCI_CR2_SBK_MASK               SCI1C2_SBK_MASK
#define BIOS_SCI_CR2_RWU_MASK               SCI1C2_RWU_MASK
#define BIOS_SCI_CR2_RE_MASK                SCI1C2_RE_MASK
#define BIOS_SCI_CR2_TE_MASK                SCI1C2_TE_MASK
#define BIOS_SCI_CR2_ILIE_MASK              SCI1C2_ILIE_MASK
#define BIOS_SCI_CR2_RIE_MASK               SCI1C2_RIE_MASK
#define BIOS_SCI_CR2_TCIE_MASK              SCI1C2_TCIE_MASK
#define BIOS_SCI_CR2_TIE_MASK               SCI1C2_TIE_MASK

#define BIOS_SCI_CR3_PEIE_MASK              SCI1C3_PEIE_MASK 
#define BIOS_SCI_CR3_FEIE_MASK              SCI1C3_FEIE_MASK 
#define BIOS_SCI_CR3_NEIE_MASK              SCI1C3_NEIE_MASK 
#define BIOS_SCI_CR3_ORIE_MASK              SCI1C3_ORIE_MASK 
#define BIOS_SCI_CR3_TXINV_MASK             SCI1C3_TXINV_MASK
#define BIOS_SCI_CR3_TXDIR_MASK             SCI1C3_TXDIR_MASK
#define BIOS_SCI_CR3_T8_MASK                SCI1C3_T8_MASK   
#define BIOS_SCI_CR3_R8_MASK                SCI1C3_R8_MASK   

#define BIOS_SCI_SR1_PF_MASK                SCI1S1_PF_MASK
#define BIOS_SCI_SR1_FE_MASK                SCI1S1_FE_MASK
#define BIOS_SCI_SR1_NF_MASK                SCI1S1_NF_MASK
#define BIOS_SCI_SR1_OR_MASK                SCI1S1_OR_MASK
#define BIOS_SCI_SR1_IDLE_MASK              SCI1S1_IDLE_MASK
#define BIOS_SCI_SR1_RDRF_MASK              SCI1S1_RDRF_MASK
#define BIOS_SCI_SR1_TC_MASK                SCI1S1_TC_MASK
#define BIOS_SCI_SR1_TDRE_MASK              SCI1S1_TDRE_MASK

#define BIOS_SCI_SR2_RAF_MASK               SCI1S2_RAF_MASK
#define BIOS_SCI_SR2_LBKDE_MASK             SCI1S2_LBKDE_MASK
#define BIOS_SCI_SR2_BRK13_MASK             SCI1S2_BRK13_MASK
#define BIOS_SCI_SR2_RWUID_MASK             SCI1S2_RWUID_MASK
#define BIOS_SCI_SR2_RXINV_MASK             SCI1S2_RXINV_MASK
#define BIOS_SCI_SR2_RXEDGIF_MASK           SCI1S2_RXEDGIF_MASK
#define BIOS_SCI_SR2_LBKDIF_MASK            SCI1S2_LBKDIF_MASK


#define BIOS_SCI_WHILE_TIMEOUT_MAX_VALUE    (uint16_t)65000

#if BIOS_SCI_MODUL_DEFAULT == 1
  #define bios_sci_default_func(func_name) bios_sci1_##func_name
#endif

#if BIOS_SCI_MODUL_DEFAULT == 2
  #define bios_sci_default_func(func_name) bios_sci2_##func_name
#endif




void bios_sci_module_init(uint8_t module, uint32_t baudrate, uint16_t baudrate_user, uint8_t sci_mode);

#define bios_sci_init   bios_sci_default_func(init)
#define bios_sci1_init(baudrate, sci_mode) bios_sci_module_init(BIOS_SCI1, baudrate, 0, sci_mode)
#define bios_sci2_init(baudrate, sci_mode) bios_sci_module_init(BIOS_SCI2, baudrate, 0, sci_mode)


void bios_sci_module_set_baudrate(uint8_t module, uint32_t baudrate);

#define bios_sci_set_baudrate   bios_sci_default_func(set_baudrate)
#define bios_sci1_set_baudrate(baudrate) bios_sci_module_set_baudrate(BIOS_SCI1, baudrate)
#define bios_sci2_set_baudrate(baudrate) bios_sci_module_set_baudrate(BIOS_SCI2, baudrate)


void bios_sci_module_enable_parity(uint8_t module, uint8_t mode);

#define bios_sci_enable_parity bios_sci_default_func(enable_parity)
#define bios_sci1_enable_parity(mode) bios_sci_module_enable_parity(BIOS_SCI1, mode)
#define bios_sci2_enable_parity(mode) bios_sci_module_enable_parity(BIOS_SCI2, mode)


void bios_sci_module_disable_parity(uint8_t module);

#define bios_sci_disable_parity   bios_sci_default_func(disable_parity)
#define bios_sci1_disable_parity() bios_sci_module_disable_parity(BIOS_SCI1)
#define bios_sci2_disable_parity() bios_sci_module_disable_parity(BIOS_SCI2)


uint8_t bios_sci_module_get_rx_interrupt_src(uint8_t module);

#define bios_sci_get_rx_interrupt_src   bios_sci_default_func(get_rx_interrupt_src)
#define bios_sci1_get_rx_interrupt_src() bios_sci_module_get_rx_interrupt_src(BIOS_SCI1)
#define bios_sci2_get_rx_interrupt_src() bios_sci_module_get_rx_interrupt_src(BIOS_SCI2)


uint8_t bios_sci_module_get_tx_interrupt_src(uint8_t module);

#define bios_sci_get_tx_interrupt_src   bios_sci_default_func(get_tx_interrupt_src)
#define bios_sci1_get_tx_interrupt_src() bios_sci_module_get_tx_interrupt_src(BIOS_SCI1)
#define bios_sci2_get_tx_interrupt_src() bios_sci_module_get_tx_interrupt_src(BIOS_SCI2)


void bios_sci_module_rx_interrupt_ack(uint8_t module, uint8_t src);

#define bios_sci_rx_interrupt_ack   bios_sci_default_func(rx_interrupt_ack)
#define bios_sci1_rx_interrupt_ack(src) bios_sci_module_rx_interrupt_ack(BIOS_SCI1, src)
#define bios_sci2_rx_interrupt_ack(src) bios_sci_module_rx_interrupt_ack(BIOS_SCI2, src)


void bios_sci_module_tx_interrupt_ack(uint8_t module, uint8_t src);

#define bios_sci_tx_interrupt_ack   bios_sci_default_func(tx_interrupt_ack)
#define bios_sci1_tx_interrupt_ack(src) bios_sci_module_tx_interrupt_ack(BIOS_SCI1, src)
#define bios_sci2_tx_interrupt_ack(src) bios_sci_module_tx_interrupt_ack(BIOS_SCI2, src)

void bios_sci_module_interrupt_ack(uint8_t module, uint16_t src);

#define bios_sci_interrupt_ack   bios_sci_default_func(interrupt_ack)                       
#define bios_sci1_interrupt_ack(src) bios_sci_module_interrupt_ack(1, src)                  
#define bios_sci2_interrupt_ack(src) bios_sci_module_interrupt_ack(2, src)                  


uint8_t bios_sci_module_read_byte(uint8_t module);

#define bios_sci_read_byte   bios_sci_default_func(read_byte)
#define bios_sci1_read_byte() bios_sci_module_read_byte(BIOS_SCI1)
#define bios_sci2_read_byte() bios_sci_module_read_byte(BIOS_SCI2)


uint8_t bios_sci_module_write_byte(uint8_t module, uint8_t value);

#define bios_sci_write_byte   bios_sci_default_func(write_byte)
#define bios_sci1_write_byte(value) bios_sci_module_write_byte(BIOS_SCI1, value)
#define bios_sci2_write_byte(value) bios_sci_module_write_byte(BIOS_SCI2, value)


void bios_sci_module_write_string(uint8_t module, char *ptr_string);

#define bios_sci_write_string   bios_sci_default_func(write_string)
#define bios_sci1_write_string(ptr_string) bios_sci_module_write_string(BIOS_SCI1, ptr_string)
#define bios_sci2_write_string(ptr_string) bios_sci_module_write_string(BIOS_SCI2, ptr_string)


void bios_sci_module_write_string_far(uint8_t module, char *__far ptr_string);

#define bios_sci_write_string_far   bios_sci_default_func(write_string_far)
#define bios_sci1_write_string_far(ptr_string) bios_sci_module_write_string_far(BIOS_SCI1, ptr_string)
#define bios_sci2_write_string_far(ptr_string) bios_sci_module_write_string_far(BIOS_SCI2, ptr_string)


void bios_sci_module_write_block(uint8_t module, char *ptr_string, uint16_t len);

#define bios_sci_write_block   bios_sci_default_func(write_block)
#define bios_sci1_write_block(ptr_string, len) bios_sci_module_write_block(BIOS_SCI1, ptr_string, len)
#define bios_sci2_write_block(ptr_string, len) bios_sci_module_write_block(BIOS_SCI2, ptr_string, len)



uint8_t bios_sci_module_send_break(uint8_t module);

#define bios_sci_send_break   bios_sci_default_func(send_break)
#define bios_sci1_send_break() bios_sci_module_send_break(BIOS_SCI1)
#define bios_sci2_send_break() bios_sci_module_send_break(BIOS_SCI2)


void bios_sci_module_enable_tci_and_ri(uint8_t module);

#define bios_sci_enable_tci_and_ri   bios_sci_default_func(enable_tci_and_ri)
#define bios_sci1_enable_tci_and_ri() bios_sci_module_enable_tci_and_ri(BIOS_SCI1)
#define bios_sci2_enable_tci_and_ri() bios_sci_module_enable_tci_and_ri(BIOS_SCI2)


void bios_sci_module_enable_tci(uint8_t module);

#define bios_sci_enable_tci bios_sci_default_func(enable_tci)
#define bios_sci1_enable_tci() bios_sci_module_enable_tci(BIOS_SCI1)
#define bios_sci2_enable_tci() bios_sci_module_enable_tci(BIOS_SCI2)


void bios_sci_module_disable_tci(uint8_t module);

#define bios_sci_disable_tci   bios_sci_default_func(disable_tci)
#define bios_sci1_disable_tci() bios_sci_module_disable_tci(BIOS_SCI1)
#define bios_sci2_disable_tci() bios_sci_module_disable_tci(BIOS_SCI2)


void bios_sci_module_enable_int_receive(uint8_t module);

#define bios_sci_enable_int_receive   bios_sci_default_func(enable_int_receive)
#define bios_sci1_enable_int_receive() bios_sci_module_enable_int_receive(BIOS_SCI1)
#define bios_sci2_enable_int_receive() bios_sci_module_enable_int_receive(BIOS_SCI2)


void bios_sci_module_disable_int_receive(uint8_t module);

#define bios_sci_disable_int_receive   bios_sci_default_func(disable_int_receive)
#define bios_sci1_disable_int_receive() bios_sci_module_disable_int_receive(BIOS_SCI1)
#define bios_sci2_disable_int_receive() bios_sci_module_disable_int_receive(BIOS_SCI2)


void bios_sci_module_enable_break(uint8_t module, uint8_t break_enable_mode, uint8_t break_len);

#define bios_sci_enable_break   bios_sci_default_func(enable_break)
#define bios_sci1_enable_break(break_enable_mode, break_len) bios_sci_module_enable_break(BIOS_SCI1, break_enable_mode, break_len)
#define bios_sci2_enable_break(break_enable_mode, break_len) bios_sci_module_enable_break(BIOS_SCI2, break_enable_mode, break_len)


void bios_sci_module_disable_break(uint8_t module);

#define bios_sci_disable_break   bios_sci_default_func(disable_break)
#define bios_sci1_disable_break() bios_sci_module_disable_break(BIOS_SCI1)
#define bios_sci2_disable_break() bios_sci_module_disable_break(BIOS_SCI2)

#endif


void bios_sci_module_rx_interrupt(uint8_t module);

#define bios_sci_rx_interrupt   bios_sci_default_func(rx_interrupt)
#define bios_sci1_rx_interrupt() bios_sci_module_rx_interrupt(BIOS_SCI1)
#define bios_sci2_rx_interrupt() bios_sci_module_rx_interrupt(BIOS_SCI2)


void bios_sci_module_tx_interrupt(uint8_t module);

#define bios_sci_tx_interrupt   bios_sci_default_func(tx_interrupt)
#define bios_sci1_tx_interrupt() bios_sci_module_tx_interrupt(BIOS_SCI1)
#define bios_sci2_tx_interrupt() bios_sci_module_tx_interrupt(BIOS_SCI2)






extern void (*os_sci_module_interrupt)(uint8_t module);
extern void (*user_sci_module_rx_interrupt)(uint8_t module, uint8_t data);
extern void (*user_sci_module_tx_interrupt)(uint8_t module);
extern void (*user_sci_module_stat_interrupt)(uint8_t module);
extern void (*lin_rx_frame_handling_interrupt)(uint8_t module, uint8_t data);
extern void (*lin_tx_frame_handling_interrupt)(uint8_t module);

extern uint8_t bios_sci_rx_int_src[];
extern uint8_t bios_sci_tx_int_src[];


