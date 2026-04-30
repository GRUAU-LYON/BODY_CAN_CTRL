
#include "modbus.h"
#include "graph_defines.h"
#include "can_db.h"
#include "os_io.h"
#include "bios_i2c.h"
#include "user_code.h"

extern uint8 graph_disabled, adc_auto_disable, can_init_disable;
extern volatile uint8 BufferRead;

volatile byte AS1_SerFlag;
volatile byte AS2_SerFlag;


void fullbridge_10A_block(uint16_t pwm_freq,
                          uint16_t duty,
                          uint16_t ramp_max,
                          uint16_t ramp_up,
                          uint16_t ramp_dwn,
                          uint8_t dir,
                          uint8_t motor_check,
                          uint8_t* err_out,
                          uint16_t* curr_out);

#ifdef PWM_OUTPUT_FULLBRIDGE_10A_AKTIV

    extern void modulhardwarecode_fullbridge_10A_block(uint16_t pwm_freq, 
                                                       uint16_t duty, 
                                                       uint16_t ramp_max, 
                                                       uint16_t ramp_up, 
                                                       uint16_t ramp_dwn, 
                                                       uint8_t dir, 
                                                       uint8_t motor_check, 
                                                       uint8_t* err, 
                                                       uint16_t* curr);
#endif

void mot_ctrl_1x_fullbridge_block(uint16_t pwm_freq, 
                                  uint16_t duty_1, 
                                  uint16_t duty_2, 
                                  uint32_t ramp_up_time, 
                                  uint32_t ramp_down_time, 
                                  uint8_t rotation, 
                                  uint8_t start_1, 
                                  uint8_t start_2, 
                                  uint16_t mode, 
                                  uint8_t* status_1, 
                                  uint8_t* status_2, 
                                  uint16_t* curr_1, 
                                  uint16_t* curr_2);

#ifdef MOT_CTRL_1X_FULLBRIDGE_AKTIV

    extern void modulhardwarecode_mot_ctrl_1x_fullbridge_block(uint16_t pwm_freq, 
                                                               uint16_t duty_1, 
                                                               uint16_t duty_2, 
                                                               uint32_t ramp_up_time, 
                                                               uint32_t ramp_down_time, 
                                                               uint8_t rotation, 
                                                               uint8_t start_1, 
                                                               uint8_t start_2, 
                                                               uint16_t mode, 
                                                               uint8_t* status_1, 
                                                               uint8_t* status_2, 
                                                               uint16_t* curr_1, 
                                                               uint16_t* curr_2);
#endif

void mirror_ctrl_block(uint16_t pwm_freq, 
                       uint8_t duty_lm,
                       uint8_t duty_rm,
                       uint8_t dir_lm,
                       uint8_t dir_rm,
                       uint8_t heater_lm,
                       uint8_t heater_rm,
                       uint8_t enable,
                       uint8_t* stat_lm,
                       uint8_t* stat_rm,
                       uint16_t* curr_mirror_lm,
                       uint16_t* curr_mirror_rm,
                       uint16_t* curr_heater_lm,
                       uint16_t* curr_heater_rm);

#ifdef MIRROR_CTRL_AKTIV

    extern void modulhardwarecode_mirror_ctrl_block(uint16_t pwm_freq, 
                                                    uint8_t duty_lm,
                                                    uint8_t duty_rm,
                                                    uint8_t dir_lm,
                                                    uint8_t dir_rm,
                                                    uint8_t heater_lm,
                                                    uint8_t heater_rm,
                                                    uint8_t enable,
                                                    uint8_t* stat_lm,
                                                    uint8_t* stat_rm,
                                                    uint16_t* curr_mirror_lm,
                                                    uint16_t* curr_mirror_rm,
                                                    uint16_t* curr_heater_lm,
                                                    uint16_t* curr_heater_rm); 
#endif   


    void fullbridge_microplex_block(uint16_t pwm_freq,
                              uint16_t duty,
                              uint16_t ramp_max,
                              uint16_t ramp_up,
                              uint16_t ramp_dwn,
                              uint8_t dir,
                              uint8_t motor_check,
                              uint8_t* err_out,
                              uint16_t* curr_out,
                              uint16_t* motor_voltage);

         #ifdef PWM_OUTPUT_FULLBRIDGE_MICROPLEX_AKTIV

    extern void  modulhardwarecode_fullbridge_microplex_block((uint16_t pwm_freq,
                              uint16_t duty,
                              uint16_t ramp_max,
                              uint16_t ramp_up,
                              uint16_t ramp_dwn,
                              uint8_t dir,
                              uint8_t motor_check,
                              uint8_t* err_out,
                              uint16_t* curr_out,
                              uint16_t* motor_voltage);


         #endif



void lin_bound_to_sci_service_routine(void);

extern void lin_rx_frame_handling(uint8_t module, uint8_t data);
extern void lin_tx_frame_handling(uint8_t module);
extern void lin_ms_timer_handling(void);

extern void (*lin_ms_timer_handling_interrupt)(void);

void lin_initialization(void);


uint16  dyn_CAN_DP_MAX;
uint8   dyn_CAN_BUS_MAX;
uint16  dyn_CAN_BLOCK_MAX;
uint8   dyn_OS_PORT_INPUT_PIN_MAX;
uint8   dyn_OS_PORT_PIN_MAX;
uint8   dyn_OS_ANALOG_PIN_MAX;
uint8   dyn_CAN_BAUDRATE;
uint8   dyn_CAN_BAUDRATE_def_sj;
uint8   dyn_CAN_BAUDRATE_def_pre;
uint8   dyn_CAN_BAUDRATE_def_t_seg1;
uint8   dyn_CAN_BAUDRATE_def_t_seg2;
uint8   dyn_CAN_BAUDRATE_def_source;
uint8   dyn_CAN_BUS_1;
uint8   dyn_BIOS_NR_OF_PORTS;
uint16  dyn_I2C_BYTE_SIZE;

uint8   dyn_OS_PWM_PIN_MAX;
uint8   dyn_PWM_DUTY_READ_MAX;

uint8  dyn_CAN_FILTER_SETTING; 
uint32 dyn_CAN_FILTER[2];
uint32 dyn_CAN_MASK[2];


uint8 dyn_USERDATENSATZ_SIZE;   
uint8 dyn_USER_VARIABLE_SIZE;   
uint8 dyn_HSDDATENSATZ_SIZE;    

uint8 dyn_SLAVE_MODBUS_ADRESSE; 


const uint16 dyn_can_send_wait = 1000;    



can_block_db_ram_typ can1_block_db_ram[CAN_BLOCK_MAX+1];         
can_block_db_ram_typ *can_block_db_ram[CAN_BUS_MAX+1] =     
  {
        can1_block_db_ram ,
  };        



uint8 os_io_vals[(OS_PORT_PIN_MAX/8+1)+1];
uint8 os_io_prev_vals[(OS_PORT_PIN_MAX/8+1)+1];
uint8 os_io_vals_disable[OS_PORT_PIN_MAX/8+1];
uint8 os_pin_entprell_cnt[(OS_PORT_PIN_MAX)+1];

os_port_int_def os_port_int_val[BIOS_NR_OF_PORTS+1];


const uint16 os_port_int_val_limits[3] = {60, 150, 500};    
const uint16 os_port_int_val_refresh[4] = {300, 200, 100, 500};    

const uint16 os_pwm_duty_timeout = 500;

type_sci_tx_buffer sci_tx_buffer;



reg_p bios_port_data_reg[BIOS_NR_OF_PORTS] =      {(reg_p) &PTAD,   (reg_p) &PTBD,   (reg_p) &PTCD,   (reg_p) &PTDD,   (reg_p) &PTED,   (reg_p) &PTFD};

reg_p bios_port_dir_reg[BIOS_NR_OF_PORTS]  =      {(reg_p) &PTADD,  (reg_p) &PTBDD,  (reg_p) &PTCDD,  (reg_p) &PTDDD,  (reg_p) &PTEDD,  (reg_p) &PTFDD};

reg_p bios_port_pull_dir_reg[BIOS_NR_OF_PORTS]=   {(reg_p) &PTAES,  (reg_p) &PTBES,  BIOS_NULL_P,     (reg_p) &PTDES,  BIOS_NULL_P,     BIOS_NULL_P};

reg_p bios_port_pull_enable_reg[BIOS_NR_OF_PORTS]={(reg_p) &PTAPE,  (reg_p) &PTBPE,  (reg_p) &PTCPE,  (reg_p) &PTDPE,  (reg_p) &PTEPE,  (reg_p) &PTFPE};

reg_p bios_port_int_edge_reg[BIOS_NR_OF_PORTS] =  {(reg_p) &PTAES,  (reg_p) &PTBES,  BIOS_NULL_P,     (reg_p) &PTDES,  BIOS_NULL_P,     BIOS_NULL_P};

reg_p bios_port_int_enable_reg[BIOS_NR_OF_PORTS]= {(reg_p) &PTAPS,  (reg_p) &PTBPS,  BIOS_NULL_P,     (reg_p) &PTDPS,  BIOS_NULL_P,     BIOS_NULL_P};

reg_p bios_port_int_active_reg[BIOS_NR_OF_PORTS]= {(reg_p) &PTASC,  (reg_p) &PTBSC,  BIOS_NULL_P,     (reg_p) &PTDSC,  BIOS_NULL_P,     BIOS_NULL_P};

uint16 os_analog_io_vals[OS_ANALOG_PIN_MAX+1];
uint16 os_analog_io_vals_kal[OS_ANALOG_PIN_MAX+1];  
uint32 os_analog_io_sum[OS_ANALOG_PIN_MAX+1];
uint8 os_analog_io_sum_cnt[OS_ANALOG_PIN_MAX+1];
uint8 os_analog_io_sum_cnt_max[OS_ANALOG_PIN_MAX+1];
uint8 os_analog_io_pwm_index[OS_ANALOG_PIN_MAX+1];

uint8 os_analog_io_vals_disable[OS_ANALOG_PIN_MAX+1];


uint8 os_pwm_analog_cal_deactivate = 0;


os_pwm_vals_def os_pwm_vals[OS_PWM_PIN_MAX+1];
os_pwm_control_vals_def os_pwm_control_vals[OS_PWM_PIN_MAX+1];


os_pwm_duty_read_def os_pwm_duty_read[PWM_DUTY_READ_MAX];

bios_can_msg_typ os_can_msg_queue_A[OS_CAN_MSG_QUEUE_A_SIZE];   
bios_can_msg_typ os_can_msg_queue_B[OS_CAN_MSG_QUEUE_B_SIZE];

uint8 dyn_OS_CAN_MSG_QUEUE_A_SIZE; 
uint8 dyn_OS_CAN_MSG_QUEUE_B_SIZE;

bios_can_msg_typ os_can_msg_tx_buffer[OS_CAN_MSG_TX_BUFFER_SIZE];

uint8 dyn_OS_CAN_MSG_TX_BUFFER_SIZE; 

uint8_t dyn_init_can_listen_only;

uint8_t modbus_active = 0; 



#ifdef HSDDATENSATZ_SIZE_MASTER
    #undef  HSDDATENSATZ_SIZE
    #define HSDDATENSATZ_SIZE HSDDATENSATZ_SIZE_MASTER
#elif defined HSDDATENSATZ_SIZE_DYNAMIC
    #undef  HSDDATENSATZ_SIZE
    #define HSDDATENSATZ_SIZE HSDDATENSATZ_SIZE_DYNAMIC
#endif


#ifdef USER_VARIABLE_SIZE_MASTER
    #undef  USER_VARIABLE_SIZE
    #define USER_VARIABLE_SIZE USER_VARIABLE_SIZE_MASTER
#elif defined USER_VARIABLE_SIZE_DYNAMIC
    #undef  USER_VARIABLE_SIZE
    #define USER_VARIABLE_SIZE USER_VARIABLE_SIZE_DYNAMIC
#endif

uint32 user_variable[USER_VARIABLE_SIZE];
uint16 eeprom_hsddaten[HSDDATENSATZ_SIZE];
uint16 eeprom_hsddaten_type;
uint16 eeprom_userdaten[USERDATENSATZ_SIZE];

#if (defined ADC_CAL_ENABLE) && (!defined PWM_ANALOG_IO_TICK)
    #define PWM_ANALOG_IO_TICK
#endif



void sys_parameter_init(void)
{
  uint8 i;

  dyn_CAN_DP_MAX = CAN_DP_MAX;
  dyn_CAN_BUS_MAX  = CAN_BUS_MAX;
  dyn_CAN_BLOCK_MAX =   CAN_BLOCK_MAX;
  dyn_OS_PORT_INPUT_PIN_MAX = OS_PORT_INPUT_PIN_MAX;
  dyn_OS_PORT_PIN_MAX = OS_PORT_PIN_MAX;
  dyn_OS_ANALOG_PIN_MAX = OS_ANALOG_PIN_MAX;
  dyn_CAN_BAUDRATE =CAN_BAUDRATE;
  dyn_CAN_BAUDRATE_def_sj  = CAN_BAUDRATE_def_sj ;
  dyn_CAN_BAUDRATE_def_pre = CAN_BAUDRATE_def_pre;
  dyn_CAN_BAUDRATE_def_t_seg1 = CAN_BAUDRATE_def_t_seg1;
  dyn_CAN_BAUDRATE_def_t_seg2 = CAN_BAUDRATE_def_t_seg2;
  dyn_CAN_BAUDRATE_def_source = CAN_BAUDRATE_def_source;
  dyn_CAN_BUS_1 = CAN_BUS_1;
  dyn_BIOS_NR_OF_PORTS = BIOS_NR_OF_PORTS;

  dyn_OS_PWM_PIN_MAX = OS_PWM_PIN_MAX;

  dyn_PWM_DUTY_READ_MAX = PWM_DUTY_READ_MAX;    

  dyn_I2C_BYTE_SIZE = I2C_BYTE_SIZE;

  dyn_USERDATENSATZ_SIZE = USERDATENSATZ_SIZE;  
  dyn_USER_VARIABLE_SIZE = USER_VARIABLE_SIZE;  
  dyn_HSDDATENSATZ_SIZE = HSDDATENSATZ_SIZE;    

  dyn_SLAVE_MODBUS_ADRESSE = SLAVE_MODBUS_ADRESSE;  

  dyn_OS_CAN_MSG_QUEUE_A_SIZE = OS_CAN_MSG_QUEUE_A_SIZE;    
  dyn_OS_CAN_MSG_QUEUE_B_SIZE = OS_CAN_MSG_QUEUE_B_SIZE;    

  dyn_OS_CAN_MSG_TX_BUFFER_SIZE = OS_CAN_MSG_TX_BUFFER_SIZE;    


  for (i=0;i<BIOS_NR_OF_PORTS;i++) {      
    os_port_int_val[i].channel_active = 0;  
    os_port_int_val[i].calc_time = 1000;
  }

  #ifdef GRAPH_DISABLE
    graph_disabled = 1;
  #else
    graph_disabled = 0;
  #endif

  #ifdef ADC_AUTO_DISABLE
    adc_auto_disable = 1;  
  #else
    adc_auto_disable = 0;
  #endif

  #ifdef CAN_USER_SETTINGS_ACTIVE            

    dyn_CAN_FILTER_SETTING = CAN_FILTER_SETTING;
    dyn_CAN_FILTER[0] = CAN_FILTER_A;
    dyn_CAN_MASK[0] = CAN_MASK_A;
    dyn_CAN_FILTER[1] = CAN_FILTER_B;
    dyn_CAN_MASK[1] = CAN_MASK_B;

  #endif


    #ifndef SCI_USER_BAUDRATE
        #define SCI_USER_BAUDRATE 0
    #endif

    #ifndef SCI_USER_DEFINED_BAUDRATE
        #define SCI_USER_DEFINED_BAUDRATE 0
    #endif

    #if defined (SCI_USER_ACTIVE) || defined (MODBUS_AKTIV)
    sci_tx_buffer.size = USER_BUFFER_SIZE;
    sci_tx_buffer.sci_nr = SCI_NR;
    sci_tx_buffer.parity = SCI_USER_PARITY;
    sci_tx_buffer.data_bits_9 = SCI_USER_DATA_BITS_9;
    sci_tx_buffer.baudrate_user_defined = 0;    
    sci_tx_buffer.baudrate = SCI_USER_BAUDRATE; 

    if(sci_tx_buffer.baudrate >= 28800) 
    {
        os_adc_vals.adc_simple_flag = 1;
    }
    else
    {
        os_adc_vals.adc_simple_flag = 0;
    }

  #ifdef SCI_USER_DEFINED_BAUDRATE    
        #if SCI_USER_DEFINED_BAUDRATE > 0
            sci_tx_buffer.baudrate_user_defined = SCI_USER_DEFINED_BAUDRATE;
        #endif
    #endif

    #ifdef SCI_USER_FULL_DUPLEX
        sci_tx_buffer.full_duplex = 1;    
    #else
        sci_tx_buffer.full_duplex = 0;    
    #endif

    #ifdef SCI_NO_DELAY_AFTER_SEND
        sci_tx_buffer.delay_after_send = DELAY_KENNER;        
    #endif


  #endif


  #ifdef SCI_USER_RS485

    for (i=dyn_OS_PORT_INPUT_PIN_MAX+1;i<dyn_OS_PORT_PIN_MAX;i++)
    {
        if (os_port_pin[i].value == MAGIC_NUMBER_RS485_DE)
        {
            sci_tx_buffer.rs485_de_pin = i;
            break;
        }
    }

  #endif

  for (i=0;i<dyn_PWM_DUTY_READ_MAX;i++)
    os_pwm_duty_read[i].active = 0;

  #ifdef PWM_DUTYCYCLE_READ_ACTIVE

        os_pwm_duty_read[PWM_DUTYCYCLE_READ_CH].active = 1;
        os_pwm_duty_read[PWM_DUTYCYCLE_READ_CH].init_freq = PWM_DUTYCYCLE_READ_FREQ;
        os_pwm_duty_read[PWM_DUTYCYCLE_READ_CH].init_res = PWM_DUTYCYCLE_READ_RES;          

  #endif

  #ifdef CAN_INIT_DISABLE
    can_init_disable = 1;
  #endif

  #ifdef INIT_CAN_LISTEN_ONLY
    dyn_init_can_listen_only = 1;
  #endif

  #ifdef PWM_ANALOG_IO_TICK
    os_adc_vals.adc_simple_pwm_io_tick = 1;
  #else
    os_adc_vals.adc_simple_pwm_io_tick = 0;
  #endif
}



void can_create_mask(uint8 bus_nr, uint32* mask, uint32* filter, uint8 *mask_division) 
{

  #ifdef CAN_USER_SETTINGS_ACTIVE      

    (void)bus_nr;
    can_create_mask_simple(mask, filter, mask_division);  

  #else

    uint32 addr_id[2][CAN_BLOCK_MAX+20];
    uint32 addr_mask[2][CAN_BLOCK_MAX+20];      

    dyn_can_create_mask(bus_nr,  mask, filter, mask_division, (uint32*)addr_id,  (uint32*)addr_mask, CAN_BLOCK_MAX+20); 

  #endif
}



extern uint32 os_time_tick_1ms;
extern uint32 os_time_tick_1000ms;

void Modbus_silent_interval_finden(void) 
{      
  #ifdef MODBUS_AKTIV 

    dyn_Modbus_silent_interval_finden(); 

  #elif defined SCI_USER_ACTIVE     

    sci_timeout_control();            

  #endif     


}


void Modbus_INIT(void) 
{      
  #ifdef MODBUS_AKTIV
      modbus_active = 1;
      dyn_Modbus_INIT();

      AS1_SerFlag = 0;
      AS2_SerFlag = 0;

  #elif defined SCI_USER_ACTIVE  

      modbus_active = 0;
      sci_init();    

  #endif 
}   




word test_zw;
void Modbus_IN_and_OUT(void) 
{
  #ifdef MODBUS_AKTIV           

    dyn_Modbus_IN_and_OUT(); 

  #endif
}


void int_rx_sci_first(uint8_t module, uint8_t data)
{  
    #ifdef MODBUS_AKTIV

        int_rx_sci1(data);

    #elif defined SCI_USER_ACTIVE

        user_int_rx_sci(module, data);

    #else

        (void)module;
        (void)data;

    #endif
}


void int_stat_sci_first(uint8_t module)
{
    #ifdef SCI_USER_ACTIVE    

        user_int_stat_sci();

    #else

        (void)module;

    #endif
}


void int_tx_sci_first(uint8_t module)
{   
    #ifdef MODBUS_AKTIV

        if( module == 1 )
        {
            AS1_SerFlag &= ~FULL_TX;                   
            SCI1C2_TIE = 0;                      
        }
        else
        {
            AS2_SerFlag &= ~FULL_TX;                   
            SCI2C2_TIE = 0;                      
        }

        int_tx_sci1();

    #elif defined SCI_USER_ACTIVE

        if( module == BIOS_SCI1 )
        {
            SCI1C2_TIE = 0;
        }
        else
        {
            SCI2C2_TIE = 0;
        }


        #ifndef SCI_USER_TX_INT_HANDLE_ACTIVE

            sci_int_buffer_send();

        #else

            user_int_tx_sci(module);

        #endif

    #else

        (void)module;

    #endif
}


void i2c_INIT(void) 
{
  #ifdef I2C_AKTIV

    bios_i2c1_init();
    bios_i2c2_init();

  #endif        
}


void bios_i2c1_MC9S08DZ60_rom_save(void) 
{  
  #ifdef I2C_AKTIV

    bios_i2c1_interrupt_ack();  
    bios_i2c1_bus_handler();

  #endif  
}


void os_pwm_analog_io_average_first(void) 
{  
  #ifdef PWM_ANALOG_IO_TICK

    os_pwm_analog_io_average();  

  #endif
}


void os_timer1_dither_calculation_first(void) 
{  
  #ifdef PWM_ANALOG_IO_TICK

    os_timer1_dither_calculation();  

  #endif    
}


void bios_timer1_pwm_read_calc_first(uint8 channel) 
{  
  #ifdef  TIMER_CHANNELS_INTERRUPT_ACTIVE

    user_int_timer_channels(channel);

  #elif  defined PWM_DUTYCYCLE_READ_ACTIVE

    if (bios_pwm1_read[channel].active)
        bios_timer1_pwm_read_calc(channel);  

  #else

    (void)channel;

  #endif
}



void os_port_int_increment_first(void) 
{  
  #ifdef PORT_INTERRUPT_ACTIVE

    os_port_int_increment();    

  #else

    uint8 i;

    for (i=0;i<dyn_BIOS_NR_OF_PORTS;i++)
        if ((*bios_port_int_active_reg[i] & bios_bitmask[3]) != 0)   
             *bios_port_int_active_reg[i] |= bios_bitmask[2]; 

  #endif    
}


extern uint8 can_message_received;
void can_input_block_to_db_first(uint8 bus_nr, bios_can_msg_typ* msg)
{
    #ifndef GRAPH_DISABLE
        can_input_block_to_db(bus_nr, msg);            
    #endif

    user_can_message_receive(msg);  
    can_message_received = 1;        

}


uint8 can_db_output_to_bus_first(void)
{
    #ifndef GRAPH_DISABLE    
        return can_db_output_to_bus();
    #else
        return 0;
    #endif

}


void fullbridge_10A_block(uint16_t pwm_freq,
                          uint16_t duty,
                          uint16_t ramp_max,
                          uint16_t ramp_up,
                          uint16_t ramp_dwn,
                          uint8_t dir,
                          uint8_t motor_check,
                          uint8_t* err_out,
                          uint16_t* curr_out)
{
     #ifdef PWM_OUTPUT_FULLBRIDGE_10A_AKTIV    

        modulhardwarecode_fullbridge_10A_block(pwm_freq, 
                                               duty, 
                                               ramp_max, 
                                               ramp_up, 
                                               ramp_dwn, 
                                               dir, 
                                               motor_check, 
                                               err_out, 
                                               curr_out);

     #else

        (void)pwm_freq;
        (void)duty;
        (void)ramp_max;
        (void)ramp_up;
        (void)ramp_dwn;
        (void)dir;
        (void)motor_check;
        (void)err_out;
        (void)curr_out;

     #endif
}

void mot_ctrl_1x_fullbridge_block(uint16_t pwm_freq, 
                                  uint16_t duty_1, 
                                  uint16_t duty_2, 
                                  uint32_t ramp_up_time, 
                                  uint32_t ramp_down_time, 
                                  uint8_t rotation, 
                                  uint8_t start_1, 
                                  uint8_t start_2, 
                                  uint16_t mode, 
                                  uint8_t* status_1, 
                                  uint8_t* status_2, 
                                  uint16_t* curr_1, 
                                  uint16_t* curr_2)    
{
    #ifdef MOT_CTRL_1X_FULLBRIDGE_AKTIV

        modulhardwarecode_mot_ctrl_1x_fullbridge_block(pwm_freq, 
                                                       duty_1, 
                                                       duty_2, 
                                                       ramp_up_time, 
                                                       ramp_down_time, 
                                                       rotation, 
                                                       start_1, 
                                                       start_2, 
                                                       mode, 
                                                       status_1, 
                                                       status_2, 
                                                       curr_1, 
                                                       curr_2);

    #else

        (void)pwm_freq;
        (void)duty_1;
        (void)duty_2;
        (void)ramp_up_time;
        (void)ramp_down_time;
        (void)rotation;
        (void)start_1;
        (void)start_2;
        (void)mode;
        (void)status_1;
        (void)status_2;
        (void)curr_1;
        (void)curr_2;

    #endif        
} 

void mirror_ctrl_block(uint16_t pwm_freq, 
                       uint8_t duty_lm,
                       uint8_t duty_rm,
                       uint8_t dir_lm,
                       uint8_t dir_rm,
                       uint8_t heater_lm,
                       uint8_t heater_rm,
                       uint8_t enable,
                       uint8_t* stat_lm,
                       uint8_t* stat_rm,
                       uint16_t* curr_mirror_lm,
                       uint16_t* curr_mirror_rm,
                       uint16_t* curr_heater_lm,
                       uint16_t* curr_heater_rm)
{

    #ifdef MIRROR_CTRL_AKTIV

        modulhardwarecode_mirror_ctrl_block(pwm_freq, 
                                            duty_lm,
                                            duty_rm,
                                            dir_lm,
                                            dir_rm,
                                            heater_lm,
                                            heater_rm,
                                            enable,
                                            stat_lm,
                                            stat_rm,
                                            curr_mirror_lm,
                                            curr_mirror_rm,
                                            curr_heater_lm,
                                            curr_heater_rm);  

     #else

        (void)pwm_freq;
        (void)duty_lm;
        (void)duty_rm;
        (void)dir_lm;
        (void)dir_rm;
        (void)heater_lm;
        (void)heater_rm;
        (void)enable;
        (void)stat_lm;
        (void)stat_rm;
        (void)curr_mirror_lm;
        (void)curr_mirror_rm;
        (void)curr_heater_lm;
        (void)curr_heater_rm;

     #endif  

}

void lin_bound_to_sci_service_routine(void)
{
    lin_rx_frame_handling_interrupt = &lin_rx_frame_handling;
    lin_tx_frame_handling_interrupt = &lin_tx_frame_handling;
    lin_ms_timer_handling_interrupt = &lin_ms_timer_handling;
}

void lin_initialization(void)
{
    #ifndef LIN_STACK_EMPTY

        lin_bound_to_sci_service_routine();

        lin_init();

        sci_tx_buffer.delay_after_send = 0;

    #endif
}

void fullbridge_microplex_block(uint16_t pwm_freq,
                          uint16_t duty,
                          uint16_t ramp_max,
                          uint16_t ramp_up,
                          uint16_t ramp_dwn,
                          uint8_t dir,
                          uint8_t motor_check,
                          uint8_t* err_out,
                          uint16_t* curr_out,
                          uint16_t* motor_voltage)
{
     #ifdef PWM_OUTPUT_FULLBRIDGE_MICROPLEX_AKTIV

    modulhardwarecode_fullbridge_microplex_block(pwm_freq,
                                               duty,
                                               ramp_max,
                                               ramp_up,
                                               ramp_dwn,
                                               dir,
                                               motor_check,
                                               err_out,
                                               curr_out,
                                               motor_voltage);

     #else

        (void)pwm_freq;
        (void)duty;
        (void)ramp_max;
        (void)ramp_up;
        (void)ramp_dwn;
        (void)dir;
        (void)motor_check;
        (void)err_out;
        (void)curr_out;
        (void)motor_voltage;

     #endif
}




