/*--------------------------------------------------------------------------*/
/** \file     os_io_tables.c
*   \brief    Functions of operating system for initialization
*             and access to ports and pins of processor
*
*   \date     30/04/2026    \author   DS/
*
*   \platform HCS08DZ / HCS12XE / HCS12XD / HCS12P
* --------------------------------------------------------------------------*/


#include "os_io_tables.h" 
#include "bios_io.h" 



/** \ingroup io
*   \brief           Definition of port pins
* --------------------------------------------------------------------------*
*                    All the used pins with their initialization values are
*                    inserted in this table. The write- and read-functions
*                    #os_digin() and #os_digout() use the pin name as parameter.
*                    Output pins have to be inserted below the line
*                    #OS_PORT_INPUT_PIN_MAX
*                    Inputs and outputs could be debounced as high-low as well as
*                    low-high edges. One cycle is one call of #os_update_digin()
*                    or #os_update_digout().
*
*                    IMPORTANT: After inserting new lines the enum in os_io_tables.h
*                    has to be updated!
* --------------------------------------------------------------------------*/
const os_port_pin_def os_port_pin[] = {
//                                                                                                             Debounce cycles:
//  Pin-Name              Port                  Bit                   Direction             Pull-Dir              Pull-Enable           Interrupt Edge        Interrupt-Enable      Value                 Lo-Hi                 Hi-Lo                 Multiplex             Inverted              
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                              (0-7)                 (PD_IN,               (PU_UP                (PE_ON                (PI_RISE              (PI_ON                (0,1)                 (0-255)               (0-255)               (0,1)                 (0,1)                 
//                                                                    PD_OUT),              PU_DOWN)              PE_OFF)               PI_FALL)              PI_OFF)                                                                                                                                                   
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{   DI_87                 ,PORT_B               ,3                    ,PD_IN                ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,DONT_CARE            ,0                    ,0                    ,0                    ,0                    }, // Digital Input 87
{   DI_87A                ,PORT_B               ,2                    ,PD_IN                ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,DONT_CARE            ,0                    ,0                    ,0                    ,0                    }, // Digital Input 87A
{   DI_C                  ,PORT_B               ,6                    ,PD_IN                ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,DONT_CARE            ,0                    ,0                    ,0                    ,0                    }, // Digital Input C
{   DI_X                  ,PORT_B               ,4                    ,PD_IN                ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,DONT_CARE            ,0                    ,0                    ,0                    ,0                    }, // Digital Input X
{   DI_15                 ,PORT_A               ,6                    ,PD_IN                ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,DONT_CARE            ,0                    ,0                    ,0                    ,0                    }, // Digital Input Kl15
{   DI_CAN_ERR_N          ,PORT_F               ,3                    ,PD_IN                ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,DONT_CARE            ,0                    ,0                    ,0                    ,0                    }, // CAN Error Pin 1=OK, 0=ERROR
{   OS_PORT_INPUT_PIN_MAX ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    },
{   DO_87                 ,PORT_D               ,4                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,0                    ,0                    ,0                    ,0                    ,0                    }, // PIN8 Digital Output 87
{   DO_87A                ,PORT_D               ,5                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,0                    ,0                    ,0                    ,0                    ,0                    }, // PIN5 Digital Output 87a
{   DO_C                  ,PORT_D               ,2                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,0                    ,0                    ,0                    ,0                    ,0                    }, // PIN3 Digital Output C
{   DO_X                  ,PORT_D               ,3                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,0                    ,0                    ,0                    ,0                    ,0                    }, // PIN1 Digital Output X
{   DO_POWER              ,PORT_D               ,7                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,1                    ,0                    ,0                    ,0                    ,0                    }, // Self-holding, when Kl15 is removed the module holds itself awake
{   DO_CAN_EN             ,PORT_F               ,0                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,1                    ,0                    ,0                    ,0                    ,0                    }, // TJA1041 EN
{   DO_CAN_STB_N          ,PORT_F               ,2                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,1                    ,0                    ,0                    ,0                    ,0                    }, // TJA1041 STB
{   DO_CAN_WAKE           ,PORT_E               ,5                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,0                    ,0                    ,0                    ,0                    ,0                    }, // TJA1041 WAKE
{   DO_CS_DIS             ,PORT_F               ,4                    ,PD_OUT               ,DONT_CARE            ,PE_OFF               ,DONT_CARE            ,PI_OFF               ,0                    ,0                    ,0                    ,0                    ,0                    }, // VNQ5050AK-E CS_DIS
{   OS_PORT_PIN_MAX       ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    },
};




/** \ingroup io
*   \brief           Definition of analog inputs and outputs
* --------------------------------------------------------------------------*
*                    This is the list of analog inputs and outputs.
*                    You could enter a value range from Min to Max to generate
*                    an error if the value is not within the range.
*                    The errors could be masked by error filters
*                    ( #ERR_OFF, #ERR_MIN, #ERR_MAX, #ERR_MIN_MAX )
* --------------------------------------------------------------------------*/
const os_analog_pin_def os_analog_pin[] = {
//  Pin-Name              ADC-Channel           Direction             Value                 Min                   Max                   Error-Filter          Entprell-Takte        ADC-Max mV            Multiplex             Multiplex Type        Parameter 1           Samples               
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                              (PD_IN                (0-                   (0-                   (0-                   (ERR_OFF              (0-255)               (0-65535)             (0,1)                 (0-255)               (0-255)               (0-255)               
//                                              PD_OUT)               32767)                32767)                32767)                ERR_MIN                                                                                                                             0 Standard            
//                                                                                                                                      ERR_MAX,                                                                                                                            1-255 ms oversample   
//                                                                                                                                      ERR_MIN_MAX                                                                                                                                               
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{   AI_87                 ,11                   ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 11400               ,0                    ,0                    ,0                    ,0                    }, // PIN8 Analog Input 87
{   AI_87A                ,10                   ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 11400               ,0                    ,0                    ,0                    ,0                    }, // PIN5 Analog Input 87A
{   AI_C                  ,14                   ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 11400               ,0                    ,0                    ,0                    ,0                    }, // PIN3 Analog Input C
{   AI_X                  ,12                   ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 11400               ,0                    ,0                    ,0                    ,0                    }, // PIN1 Analog Input X
{   AI_15                 ,6                    ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 11400               ,0                    ,0                    ,0                    ,0                    }, // PIN4 Analog Input Kl15
{   AI_POTI               ,7                    ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 0                   ,0                    ,0                    ,0                    ,0                    }, // Poti Analog Input
{   AI_I_87               ,2                    ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 0                   ,0                    ,0                    ,AI_I_87              ,0                    }, // PIN8 Current Sense 87
{   AI_I_87A              ,1                    ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 0                   ,0                    ,0                    ,AI_I_87              ,0                    }, // PIN5 Current Sense 87A
{   AI_I_C                ,3                    ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 0                   ,0                    ,0                    ,AI_I_87              ,0                    }, // PIN3 Current Sense C
{   AI_I_X                ,5                    ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 0                   ,0                    ,0                    ,AI_I_87              ,0                    }, // PIN1 Current Sense X
{   ANA_TEMP              ,26                   ,PD_IN                ,DONT_CARE            ,0                    ,0                    ,ERR_OFF              ,0                    , 0                   ,0                    ,0                    ,224                  ,0                    }, // Temperature value
{   OS_ANALOG_PIN_MAX     ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    , 0                   ,0                    ,0                    ,0                    ,0                    },
};



/** \ingroup io
*   \brief           Definition of PWM outputs
* --------------------------------------------------------------------------*
*                    This table lists the properties of the PWM outputs.
* --------------------------------------------------------------------------*/
const os_pwm_pin_def os_pwm_pin[] = {
//  Pin-Name              Timer-Channel         Pulse Type            Init-Type             ADC active            ADC-Channel           ADC max volt          ADC Filter            ADC Startbed          Digout vorw           Digout rueckw         Current max           Digout index          
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                        (0-5)                 (HIGH_TRUE,           (0,1)                 (0,1)                 (0-23)                (0-                   (1-100)               (0-23)                (0-n)                 (0-n)                 (0-n)                 (0-n)                 
//                                              LOW_TRUE)                                                                               65535)                                                                                                                                                    
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{   PWM_87                ,2                    ,HIGH_TRUE            ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,DO_87                }, // PIN8 PWM Output 87
{   PWM_87A               ,3                    ,HIGH_TRUE            ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,DO_87A               }, // PIN5 PWM Output 87A
{   PWM_C                 ,0                    ,HIGH_TRUE            ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,DO_C                 }, // PIN3 PWM Output C
{   PWM_X                 ,1                    ,HIGH_TRUE            ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,DO_X                 }, // PIN1 PWM Output X
{   OS_PWM_PIN_MAX        ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    ,0                    },
};


// 4MHz or 8MHz oscillator => Adapt PLL multiplicator
const uint8_t bios_osc_clk = OSC_CLK_8MHZ;


// Device type number: This could activate module specific initialization code
const uint8_t modul_geraetetyp_nr = 0;

