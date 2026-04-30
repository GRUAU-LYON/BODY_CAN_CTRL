//--------------------------------------------------------------------------
/// \file     modulhardwarecode.c
/// \brief    Multiplexen des Einlesens der Statusausgänge der HSD. Bei der 
///           uSPS-CAN müssen die Statusausgänge nicht gemultiplext werden,
///           da es schlicht keine zum Mulitplexen gibt.
/// \author   Daniel Riegel
/// \date     23.09.08
/// \version  1.00
//--------------------------------------------------------------------------
#include "bios.h"
#include "os.h"


void modulhardwarecode (void) {    

}


void modulhardwarecode_adc_multiplex(uint8 multiplex_nr) { }


void modulhardwarecode_timer(void) { }


void modulhardwarecode_sleep(void) 
{       
    DisableInterrupts;                            
    
    (void)Start_wait(30); // 1ms warten // os_wait() nicht möglich da Interrupts deaktiviert.
         
    os_pin_write(DO_CAN_STB_N, 0);     
          
    (void)Start_wait(30); // 1ms warten
    os_pin_write(DO_CAN_EN, 0);     
    
    os_pin_write(DO_POWER, 0);
    
    (void)Start_wait(7000); // Zur Sicerheit ca. 200ms auf Sleep warten

    // Notstrategie, falls nicht erfolgreich
    os_pin_write(DO_POWER, 1);
    
    os_pin_write(DO_CAN_STB_N, 1);     
    os_pin_write(DO_CAN_EN, 1);         
    
    EnableInterrupts;      
}


void modulhardwarecode_init(void) {
                    
    	os_pin_write(DO_CAN_WAKE, 1);
    	os_pin_write(DO_CAN_WAKE, 0);
        
 }
