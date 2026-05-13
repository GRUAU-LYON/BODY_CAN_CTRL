#ifndef _MODBUS_H_
#define _MODBUS_H_

#include "bios_PE_Types.h"
#include "user_code.h"

extern unsigned char latch_out_meldung;





#define NICHT_VORHANDEN   0  
#define EMPFANG_LAEUFT	  1 		 
#define VORHANDEN	  2  			
#define AUSGEWERTET	  3  			
#define ANTWORT_GESENDET  4 		 


#define MODBUS_DATEN_SENDEN		    	1
#define MODBUS_DATEN_EMPFANGEN	  	0
#define MODBUS_DATEN_EMPFANGEN_SPEZ	3

#define READ_INPUT_REGISTER	       0x4
#define PRESET_MULTIPLE_REGISTERS  0x10
#define READ_WRITE_INPUT_REGISTER  0x17

#define SCI1_TDRE_0    SCISR &= ~0x80    
#define SCI1_TDRE        (SCISR &   0x80)    

#define SCI1_RDRF_0    SCISR &= ~0x40    
#define SCI1_RDRF        (SCISR &   0x20)   

#define FULL_TX          0x20          

#define START_AKT_DATEN        		      0
#define MODBUS_REGISTER_MAX       		  60
#define ENDE_AKT_DATEN_MASTER	          60
#define akt_WRITE_BEFEHL1               27 

#define MODBUS_KEIN_FEHLER	     			 0
#define MODBUS_CS_FALSCH	     			   1
#define MODBUS_FALSCHER_TELEGRAMMTYP   2
#define MODBUS_TX_BUFFER_UEBERLAUF  	 3
#define MODBUS_RX_BUFFER_UEBERLAUF  	 4
#define MODBUS_ZU_VIELE_BYTE	     		 5
#define MODBUS_PARITY_ERROR	     		   6
#define MODBUS_OVERRUN_ERROR	    		 7
#define MODBUS_FRAMING_ERROR	    		 8
#define MODBUS_BREAK_INTERRUPT	    	 9
#define MODBUS_TEILNEHMER_FALSCH       10
#define MODBUS_WRITE_FEHLER            11 

#define LAENGE_MODBUS_BUFFER	  		148 
#define LAENGE_MODBUS_DATENLISTE  		21
#define MAX_MODBUS_SLAVE_ADDRESS 		247  
#define MODBUS_BROADCAST_ADDRESS 		 0

#define KEIN_NEUER_MODBUS_WERT	0x7fff 


#define LAENGE_MULTISTATE_OUT   10
#define LAENGE_MULTISTATE_IN    10
#define READ_MULTISTATE          1
#define WRITE_MULTISTATE         2
#define READ_WRITE_MULTISTATE    3


#define SCI_19200BAUD   19200
#define SCI_9600BAUD    9600
#define SCI_4800BAUD    4800
#define SCI_28800BAUD   28800
#define SCI_115200BAUD  115200

#define TAKE_SCI1 0
#define TAKE_SCI2 1

typedef struct			      
  {
  unsigned char adresse;
  unsigned int	rx_buffer_pointer;
  unsigned int	tx_buffer_pointer;
  int	tx_buffer_count;
  unsigned  long rx_time;		           
  unsigned  long timeout_rx_freigabe;   



  unsigned char rx_tx_buffer[LAENGE_MODBUS_BUFFER+15];  

  unsigned char rx_daten_vorhanden;   
  unsigned char silent_interval;              
  unsigned char error;

  }typ_modbus;

 #define DELAY_KENNER 0xFF55    

 #ifndef USER_BUFFER_SIZE
  #define USER_BUFFER_SIZE 1
 #endif

 #ifndef SCI_USER_ACTIVE
    #undef USER_BUFFER_SIZE
    #define USER_BUFFER_SIZE 1
 #endif

 typedef struct {  
  unsigned int  pointer;
  unsigned int  pointer_buf;
  unsigned int  max;
  unsigned int  size;
  unsigned char send_active;  
  unsigned int  delay_after_send;
  unsigned int  msg_cnt;
  unsigned long timeout_rx_freigabe;
  unsigned char sci_nr;
  unsigned char sci_error_test;
  unsigned char sci_error_counter1;
  unsigned char sci_error_counter2;
  unsigned char data_bits_9;
  unsigned char parity;
  unsigned long baudrate;               
  unsigned int  baudrate_user_defined;  
  unsigned char full_duplex;    
  unsigned char rs485_de_pin;   
  unsigned char data[USER_BUFFER_SIZE];
 }  type_sci_tx_buffer;




extern typ_modbus modbus;
extern unsigned char Modbusempfang_OK ;    
extern unsigned long Timer_Modbusverarbeiten  ;

extern type_sci_tx_buffer sci_tx_buffer;



extern void ini_modbus(void);
extern void modbus_nachricht_auswerten_SLAVE( unsigned char );
extern void datenpunkte_rd_wr_SLAVE(unsigned char ,unsigned char, unsigned int, unsigned int);
extern void datenpunkte_rd_wr_SLAVE_spezial(unsigned char ,unsigned char, unsigned int, unsigned int);
extern unsigned int berechne_modbus_crc(unsigned int, unsigned char* );
extern void modbus_enable(uint8 mode_sel); 

extern void ini_modbus_sci1(unsigned int, unsigned char, unsigned char, unsigned char);
extern void modbus_sci1_start_senden(void);
extern void int_rx_sci1(uint8_t data);
extern void int_tx_sci1(void);
extern void print_text_sci1(unsigned char * text,unsigned char str_len);

void sci_buffer_send(void);
void sci_int_buffer_send(void);
void sci_init(void);
uint8 sci_put_queue(uint8 data);
void sci_timeout_control(void);
void unsigned_int_to_hi_lo(unsigned int  wert, unsigned char *hi ,unsigned char *lo) ;


extern void dyn_Modbus_silent_interval_finden(void);
extern void dyn_Modbus_INIT(void);
extern void dyn_Modbus_IN_and_OUT(void);
extern void Modbus_IN_and_OUT(void);
extern void MainDelay(unsigned int wait);

uint16_t modbus_read_register(uint8_t index); 
void modbus_write_register(uint8_t index, int16_t data);


#endif

