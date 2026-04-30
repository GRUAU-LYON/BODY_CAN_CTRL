//--------------------------------------------------------------------------
/// \file     user_code.c
/// \brief    user code
/// \author   user
/// \date     11.06.2016
/// \version  1.00
/// \comment  file to write user specific code
//--------------------------------------------------------------------------

#include "user_code.h"


// --------------------------------------------------------------------------------
// Example variables
// --------------------------------------------------------------------------------
uint16_t variable1, variable2;
uint32_t time_val;


/// \ingroup user
/// \brief           user-defined c-code INIT
//--------------------------------------------------------------------------
/// \return          None
//--------------------------------------------------------------------------
void usercode_init(void)
{
    // Set the SW-Version, maximal length=20
    //(void)strncpy(EEPROM_SW_Version, "V1.0", 20);

}


/// \ingroup user
/// \brief           user-defined c-code
//--------------------------------------------------------------------------
/// \return          None
//--------------------------------------------------------------------------
void usercode(void)
{

    //-----------------------------------------------------------
    //-----------------------------------------------------------
    //  To start programming in C set 2 #define in "user_code.h":
    //
    //    1. Select your hardware type (#define HW_TYPE HW_CAN_IO_V2)
    //
    //    2. Enable or disable the synchronous execution of graph code (#define GRAPH_DISABLE)
    //
    //  Furthermore you can set up CAN baudrate and CAN filter / masks
    //  in "can_db_tables.h"
    //
    //  CodeWarrior 6.3 can be found here:
    //  => http://www.freescale.com/webapp/sps/site/prod_summary.jsp?code=CW-MICROCONTROLLERS
    //
    //  Downloadlink: http://www.freescale.com/lgfiles/devsuites/HC08/CW_MCU_V6_3_SE.exe
    //-----------------------------------------------------------
    //-----------------------------------------------------------


    /*
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // INPUTS AND OUTPUTS
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------


    //--------------------------------------------------------------------------
    // Available    ONLY GRAPH
    // Procedure	  uint8_t os_digin(uint16_t i);
    // Overview	    read a digital input
    // Input		    digital input, see #os_port_pin in os_io_tables.c
    // Output	      state of the pin
    //--------------------------------------------------------------------------

    // Example: ("D_IN0" = name of digital input, see #os_port_pin in os_io_tables.c):

    variable1 = os_digin(D_IN0);


    //--------------------------------------------------------------------------
    // Available    ONLY GRAPH DISABLED
    // Procedure	  uint8_t os_pin_read(uint16_t i);
    // Overview	    read a digital input
    // Input		    i     digital input, see #os_port_pin in os_io_tables.c
    // Output	      state of the pin
    //--------------------------------------------------------------------------

    // Example: ("D_IN0" = name of digital input, see #os_port_pin in os_io_tables.c):

    variable1 = os_pin_read(D_IN0);


    //--------------------------------------------------------------------------
    // Available    ONLY GRAPH
    // Procedure	  void os_digout(uint16_t i, uint8_t value);
    // Overview	    set a digital output
    // Input		    i       digital output, see #os_port_pin in os_io_tables.c
    //              value   value of the output
    // Output	      None
    //--------------------------------------------------------------------------

    // Example: ("OUT_HSD0" = name of digital ouput; "1" = output is set to 1):

    os_digout(OUT_HSD0, 1);


    //--------------------------------------------------------------------------
    // Available    ONLY GRAPH DISABLED
    // Procedure	  void os_pin_write(uint16_t i, uint8_t value);
    // Overview	    set a digital output
    // Input		    i       digital output, see #os_port_pin in os_io_tables.c
    //              value   value of the output
    // Output	      None
    //--------------------------------------------------------------------------

    // Example: ("OUT_HSD0" = name of digital ouput; "1" = output is set to 1):

    os_pin_write(OUT_HSD0, 1);


    //--------------------------------------------------------------------------
    // Available    BOTH
    // Procedure	  uint16_t os_algin_mv(uint8_t i)
    // Overview	    read an analog input
    // Input		    i     analog input, see #os_analog_pin in os_io_tables.c
    // Output	      value of the pin in mV
    //--------------------------------------------------------------------------

    // Example: ("ANA0" = name of analog input, see #os_analog_pin in os_io_tables.c)

    variable1 =  os_algin_mv(ANA0);





    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // CAN-BUS
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------


    //--------------------------------------------------------------------------
    // Available    BOTH
    // Procedure	  uint8_t os_can_send_message(uint32_t id, uint8_t id_type,  uint8_t dlc,
    //                        uint8_t byte0 , uint8_t byte1 , uint8_t byte2 , uint8_t byte3 ,
    //                        uint8_t byte4 , uint8_t byte5 , uint8_t byte6 , uint8_t byte7);
    // Overview	    send an user-defined CAN message
    // Input		    id        CAN identifier
    //              id_type   "0" 11bit id, "1" 29bit id
    //              dlc       data length
    //              byte 0-7  data of the message
    // Output	      0=OK, 1=Error(Send buffer full or CAN not initialized or bus heavy)
    //--------------------------------------------------------------------------

    // Example:

    ret = os_can_send_message(0x720, 0, 8, 0x66, 0x33, 0x11, 0, 0, 0, 0, 0);


    //--------------------------------------------------------------------------
    // Available    BOTH
    // Procedure	  void user_can_message_receive(bios_can_msg_typ* msg);
    // Overview	    THE PROCEDURE IS AT THE END OF THIS FILE
    //              It's the simpliest way to evaluate a received CAN message
    //              When a message is received it is stored in a buffer. Every
    //              cycle time the buffer is read, and when something is in
    //              the procedure is called
    // Input		    -
    // Output	      -
    //--------------------------------------------------------------------------



    //--------------------------------------------------------------------------
    // Available    BOTH
    // Procedure	void can_db_transmit_deactivate(uint8 status);
    // Overview     Stops sending of all can Blocks.
    // Input		status uint8 value for all can dbs, 1 = stop, 0 = run.
    //
    // Output	    None
    //--------------------------------------------------------------------------

    // Example:

	  can_db_transmit_deactivate(1);




    //--------------------------------------------------------------------------
    // Available    ONLY GRAPH
    // Procedure	  uint32_t can_db_get_value(uint8_t bus_nr, uint32_t name_signal);
    // Overview	    read a CAN message
    // Input		    bus_nr        "0"
    //              name_signal   name of datapoint, see #can1_datenpunkt_db_const
    //                            in can_db_tables.c
    // Output	      value of datapoint
    //--------------------------------------------------------------------------

    // Example: ("0" = bus-nr, there's only one bus; "POINT1" = datapoint-name):

    variable1 =  can_db_get_value(0, POINT1);



    //--------------------------------------------------------------------------
    // Available    ONLY GRAPH
    // Procedure	  uint8_t can_db_test_dp_value(uint8_t bus_nr, uint32_t id);
    // Overview	    see whether the CAN message with that datapoint is received
    // Input		    bus_nr    "0"
    //              id        name of datapoint, see #can1_datenpunkt_db_const
    //                        in can_db_tables.c
    // Output	      "0" no message received,
    //              "1" message received, datapoint has same value,
    //              "2" message received, datapoint has another value
    //--------------------------------------------------------------------------

    // Example: ("0" = bus-nr, there's only one bus; "POINT1" = datapoint-name):

    variable1 =  can_db_test_dp_value(0, POINT1);

    //--------------------------------------------------------------------------
    // Available    ONLY GRAPH
    // Procedure	  void can_db_set_value(uint8_t bus_nr, uint32_t name_signal, uint32_t wert_int);
    // Overview	    set the value of a datapoint (it's sended automatically)
    // Input		    bus_nr        "0"
    //              name_signal   name of datapoint, see #can1_datenpunkt_db_const
    //                            in can_db_tables.c
    //              wert_int      specify value of datapoint
    // Output	      None
    //--------------------------------------------------------------------------

    // Example: ("0" = bus-nr, there's only one bus; "POINT1" = datapoint-name; "23" = datapoint is set to 23);

    can_db_set_value(0, POINT2, 23);



    //--------------------------------------------------------------------------
    // Available    ONLY GRAPH
    // Procedure	  void can_db_set_transmit_flag(uint8_t bus_nr, uint32_t id );
    // Overview	    manually send a message defined in graphical programming
    // Input		    bus_nr    "0"
    //              id        name of datapoint, see #can1_datenpunkt_db_const
    //                        in can_db_tables.c
    // Output	      None
    //--------------------------------------------------------------------------

    // Example: ("0" = bus-nr, there's only one bus; "POINT2" = datapoint-name)

    can_db_set_transmit_flag(0, POINT2);


    //--------------------------------------------------------------------------
    // Available    ONLY C-CODE
    // Procedure    void os_can_set_baudrate (uint8_t bus_id, uint8_t can_baudrate);
    // Overview     Change baudrate during running time.
    //              Make sure that the resulting error frames are handled and the function is only called once.
    //              After restart, the baud rate is reset to the default value.
    // Input        bus_id uint8_t  CAN bus module number (CAN_BUS_0, CAN_BUS_1, CAN_BUS_2, CAN_BUS_3, CAN_BUS_4)
    //              can_baudrate uint8_t  CAN baudrate, e.g. CAN_BAUD_USER_125, CAN_BAUD_USER_250, CAN_BAUD_USER_500, see enum_USER_CAN_BAUDRADE in os_can.h
    //
    // Output	    None
    //--------------------------------------------------------------------------

    // Example: Set CAN0 to 250kBaud

  	void os_can_set_baudrate (CAN_BUS_0, CAN_BAUD_USER_250);




    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // TIME BEHAVIOR
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    // check if a time of 500ms passed since last timestamp
    if( os_time_past(time_val, 500, OS_1ms) )
    {
        // if the time passed, set "time_val" to a new timestamp to start cycling
        os_timestamp(&time_val, OS_1ms);
    }


    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // USER VARIABLE FOR DATA EXCHANGE WITH GRAPHICAL PROGRAMMING
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    // Index 0 - USER_VARIABLE_SIZE (s. user_code.h) as 32bit values, same index as in graphical programming
    variable1 = (uint16_t)user_variable[0];



    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // EEPROM SAVE AND READ DATA
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    // The array eeprom_userdaten[] with Index 0 - USERDATENSATZ_SIZE (s. user_code.h)
    // is read from EEPROM on startup
    // You can read and write to that array as often you want to
    variable1 = eeprom_userdaten[0];

    // If you want to save that array to the EEPROM call (maximal 100.000 times)
    os_eeprom_write_all(EEPROM_USER);



    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // EEPROM DIRECT ROUTINES
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    // User-EEPROM-Range (Addr) is 0x000 - 0x5FF  (=1536 bytes)
    // With the following routines you can read and write to user-EEPROM range for
    // the specified number (Size) in bytes.

    // Read any EEPROM data:

    //--------------------------------------------------------------------------
    // Procedure	  uint8_t os_eeprom_read_data(uint16_t Addr, uint8_t *Data, uint16_t Size);
    // Overview     Read EEPROM data
    // Input        Addr      Start address, range 0x000 - 0x5FF
    //              Size      Length in bytes
    // Output	      *Data     Pointer to uint8_t array
    // Return       0: ERR_OK, > 0: Error occured (see PE_Error.h for error possibilities)
    //--------------------------------------------------------------------------

    e.g.
    ret = os_eeprom_read_data(addr, &data_arr[0], 8);


    // Write any EEPROM data:

    //--------------------------------------------------------------------------
    // Procedure	  uint8_t os_eeprom_write_data(uint16_t Addr, uint8_t *Data, uint16_t Size);
    // Overview     Write EEPROM data
    // Input        Addr      Start address, range 0x000 - 0x5FF
    //              Size      Length in bytes
    // Output	      *Data     Pointer to uint8_t array
    // Return       0: ERR_OK, > 0: Error occured (see PE_Error.h for error possibilities)
    //--------------------------------------------------------------------------

    e.g.
    ret = os_eeprom_write_data(addr, &data_arr[0], 8);




    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // SETTING A PWM IN GENERAL
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // Available  BOTH
    // Procedure	void os_pwm_duty_cycle(uint8_t i, uint16_t pwm_promille, uint16_t pwm_frequency, uint16_t pwm_dither_promille, uint16_t pwm_dither_frequency) {
    // Overview	Set a pwm duty cycle and frequency (+dither if needed)
    // Input		i               channel, see os_pwm_pin in os_io_tables.c
    //            pwm_promille    duty cycle in 1/1000 (value range from 0 - 1000)
    //            pwm_frequency   20Hz - 40kHz (1digit / Hz), max frequency depending from output driver
    //            pwm_dither_promille     dither duty cycle
    //            pwm_dither_frequency    dither frequency in Hz
    // Output	    None
    //--------------------------------------------------------------------------

    // Example:
    os_pwm_duty_cycle(0, 500, 150, 0, 0);



    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // SETTING A PWM AT THE OUTPUTS OF THE CAN I/O
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // Available    BOTH
    // Procedure	  void os_pwm_all_channels(uint8_t i, uint16_t duty_cycle, uint16_t pwm_frequency);
    // Overview	    Set a pwm duty cycle and frequency at outputs OUT_HSD2-7 on CAN I/O
    // Input		    i               0: OUT_HSD2, 1: OUT_HSD3, 2: OUT_HSD4, ..., 5: OUT_HSD7
    //              duty_cycle      in 1/1000 (value range from 0 - 1000)
    //              pwm_frequency   20Hz - 1kHz (1digit / Hz), max frequency depended from high side driver
    // Output	      None
    //--------------------------------------------------------------------------

    // Example: (on OUT_HSD2 a pwm with 150Hz and 50% duty cycle)

    os_pwm_all_channels(0, 500, 150);


    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // SETTING CURRENT CONTROL WITH PWM IN GENERAL
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // Available  BOTH
    // Procedure	void os_pwm_control(uint8_t i, uint16_t w, uint16_t pwm_frequency, uint16_t pwm_dither_promille, uint16_t pwm_dither_frequency, uint16_t rampe, uint16_t kp_min, uint16_t kp_max, uint16_t time_diff, uint16_t *kp_calc, uint8_t *error);
    // Overview	Set a pwm duty cycle and frequency (+dither if needed) for current control
    // Input		i               channel, see os_pwm_pin in os_io_tables.c
    //            w               current in mA, range 0-5000
    //            pwm_frequency   20Hz - 40kHz (1digit / Hz), max frequency depending from output driver
    //            pwm_dither_promille     dither duty cycle in 1/1000
    //            pwm_dither_frequency    dither frequency in Hz
    //            rampe           ramp in ms for 100%
    //            kp_min          minimum kp*1024, e.g. 200
    //            kp_max          maximum kp*1024, e.g. 4000
    //            time_diff       graph_cycle_time, e.g. 10
    //            *kp_calc        pointer for actual kp value
    //            *error          pointer for error, 0=OK
    // Output	    None
    //--------------------------------------------------------------------------

    // Activate #define PWM_ANALOG_IO_TICK in graph_defines.h first! Otherwise current control wouldn't be possible.

    // Example: Setting PWM0 to 500mA at 1kHz PWM

    os_pwm_control(PWM0, 500, 1000, 0, 0, 0, 200, 1500, graph_cycle_time, &var_kp_calc, &var_error);




    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // SETTING MOTOR OUTPUT OF CAN_FULLBRIDGE
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // Available    BOTH
    // Procedure    void os_pwm_motor_control(uint8_t i, uint16_t w, uint8_t w_dir, uint16_t pwm_frequency, uint16_t time_diff, uint8_t m2_trigger, uint8_t* error_stat);
    // Overview     Set a pwm duty cycle and frequency and direction for motor control
    // Input        i                      channel, see os_pwm_pin in os_io_tables.c
    //              w                      duty cycle in 1/1000 (range 0-1000)
    //              w_dir                  0=direction A, 1=direction B
    //              pwm_frequency          20Hz - 40kHz (1digit / Hz)
    //              time_diff              graph_cycle_time, e.g. 10
    //              m2_trigger             re-check if motor is connected
    //              *error_stat            Bit0=Motor not correctly connected, Bit1=Current too high, waiting 5s
    // Output       None
    //--------------------------------------------------------------------------

    // Example: Setting motor to turn in direction A(0) with duty cycle of 50% at 150Hz

    os_pwm_motor_control(PWM0, 500, 0, 150, graph_cycle_time, 0, &var_error);


	//--------------------------------------------------------------------------
    // SETTING MOTOR OUTPUT FOR 10A, 10A PRO
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // Available    C-Code
    // Procedure    void modulhardwarecode_fullbridge_10A_block(uint16_t pwm_freq, uint16_t duty_1, uint32_t ramp_max, uint32_t ramp_up, uint32_t ramp_dwn uint8_t rotation, uint8_t motor_check, uint8_t* error, uint16_t* curr);
    // Overview     Set a pwm duty cycle, frequency and ramp for motor control
    // Input        pwm_freq [in]          pwm frequency [Hz]
    //              duty [in]              duty cycle [% * 10]
    //              ramp_max [in]          ramp max [ms]
    //              ramp_up [in]           ramp up [ms]
    //              ramp_dwn               ramp dwn [ms]
    //              dir [in]               direction
    //              motor_check [in]       motor check enb.
    //              *error [in]            status output
    //              *curr [in]             current output
    // Output       None
    //--------------------------------------------------------------------------

    // Example:     Setting motor to turn in direction B(1) with duty cycle of 50% at 150Hz and motor_check disabled.

    (void)modulhardwarecode_fullbridge_10A_block(150, 500, 1000, 0, 0, 1, 0, &error, &curr);



    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // READ FREQUENCY
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------


    //--------------------------------------------------------------------------
    // Available  BOTH
    // Procedure	uint16_t os_frequency_calc(uint8_t channel_def)
    // Overview	Read frequency
    // Input		channel_def     D_ANA3 (name of digital input)
    // Output	    frequency value
    //--------------------------------------------------------------------------

    // Activate PORT_INTERRUPT_ACTIVE in graph_defines.h

    ret = os_frequency_calc(D_ANA3);



    //--------------------------------------------------------------------------
    // Available  C-Code
    // Procedure    void os_frequency_read(uint8_t channel_def, uint32_t* measure_period_timestamp, uint16_t* measured_frequency)
    // Overview     Read frequency
    // Input        channel_def                  name of digital input. see os_io_tables.c
    //              measure_period_timestamp     time variable
    // Output       measured_frequency           frequency at selected pin
    //--------------------------------------------------------------------------

    // Activate PORT_INTERRUPT_ACTIVE in graph_defines.h
    // to initialize call os_init_frequency_read in user_init.

    // Exmaple: Read frequency at D_ANA5

    os_frequency_read(D_ANA5, &time_val, &variable1);

    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // READ ENCODER SIGNALS
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------




    //--------------------------------------------------------------------------
    // Available  BOTH
    // Procedure	uint16_t os_incremental_encoder(uint8_t mode_type, uint8_t channel_def1, uint8_t channel_def2, uint16_t min, uint16_t max)
    // Overview	Read and calculate 2 encoder signales which have a 90° phase shift
    // Input		mode_type       PORT_INT_INCR_ENCODER
    //            channel_def1    D_ANA3
    //            channel_def2    D_ANA5
    //            min             0
    //            max             100 (if min=max=0, value won't be limited. To get signed value read with cast (int16_t).
    // Output	    actual counter value
    //--------------------------------------------------------------------------

    // Activate PORT_INTERRUPT_ACTIVE in graph_defines.h

    ret = os_incremental_encoder(PORT_INT_INCR_ENCODER, D_ANA3, D_ANA5, 0, 100);





    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // READ A PWM DUTY CYCLE BY TIMER REGISTER (CAN I/O)
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    // See user_code.h
    // Call os_init_pwm_duty_read(); in void usercode_init(void)

    // variable1 = os_pwm_duty_read[i].duty;
    // variable2 = os_pwm_duty_read[i].frequency;

    // i = Timer channel, see PWM_DUTYCYCLE_READ_CH in user_code.h




    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // SEND AND RECEIVE RS485 DATA WITH SERIAL COMMUNCATION INTERFACE (SCI)
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    // You need the CAN I/O with RS485 option!
    // Go to user_code.h and specify 3 #define:
    // Set SCI_USER_ACTIVE, set the USER_BUFFER_SIZE (maximum 255) and the SCI baud rate

    // TYPE 1: SEND A BLOCK: Fill out an array, specify the size and send it all away

    //--------------------------------------------------------------------------
    // Available    BOTH
    // Procedure	  void sci_buffer_send(void)
    // Overview	    After you filled out the array, start sending
    // Input		    None
    // Output	      None
    //--------------------------------------------------------------------------

    // Example1:
    sci_tx_buffer.data[0] = 0x22;
    sci_tx_buffer.data[1] = 0x33;
    sci_tx_buffer.data[2] = 0x44;
    sci_tx_buffer.max = 3;
    sci_buffer_send();

    // Example2:
    (void)sprintf(sci_tx_buffer.data, "This text will be sent!");
    sci_tx_buffer.max = strlen(sci_tx_buffer.data);
    sci_buffer_send();


    // TYPE 2: PUT BYTE TO THE TRANSMIT BUFFER:

    //--------------------------------------------------------------------------
    // Available    BOTH
    // Procedure	  unsigned char sci_put_queue(unsigned char data)
    // Overview	    Put one byte to the transmit buffer, when it's full you get
    //              back FALSE
    // Input		    data    One byte which should be sent
    // Output	      TRUE    byte was put to the buffer
    //              FALSE   buffer is full, byte was not put to the buffer
    //--------------------------------------------------------------------------

    // Example1:
    sci_put_queue(0x58);
    sci_put_queue(0x68);  // ....

    // Example2:
    if( sci_put_queue(0x58) == FALSE )  // Remember not successful sends
    {}




    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // USE LOOKUP TABLE FUNCTIONS
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    int16_t os_util_lookup1D(int16_t *table_x, int16_t *table_y, uint8_t count, int16_t val, uint8_t mode)

    * \param *table_x [in]             pointer x-array (1D)
    * \param *table_y [in]             pointer y-array (1D)
    * \param count [in]                counts of x-array elements
    * \param val [in]                  x-value
    * \param mode [in]                 LUT_MODE_EXTRAPOLATION (Standard): away from the array extrapolate
    *                                  LUT_MODE_LIMIT: away from the array not extrapolate
    *                                  LUT_MODE_KALIBRATION: y-value always >= 0, extrapolating upwards with difference (y_max - x_max)
    * \return int16_t                  y-value

    //--------------------------------------------------------------------------
    // for example

    int16_t arr_x[] = {136,200,311,444,666};
    int16_t arr_y[] = {-10,5,16,27,39};

    ret = os_util_lookup1D(arr_x, arr_y, 5, 250, LUT_MODE_EXTRAPOLATION);   // ret == 10
    //--------------------------------------------------------------------------



    //--------------------------------------------------------------------------
    int16_t os_util_lookup2D(int16_t *table_x, int16_t *table_y, uint8_t count_x, uint8_t count_y, int16_t *table_z, int16_t val_x, int16_t val_y)

    * \param *table_x [in]             pointer x-array (1D)
    * \param *table_y [in]             pointer y-array (1D)
    * \param count_x [in]              counts of x-array elements
    * \param count_y [in]              counts of y-array elements
    * \param *table_z [in]             pointer z-array (1D with (count_y * count_x) elements)
    * \param val_x [in]                x-value (away from the x-array => extrapolation)
    * \param val_y [in]                y-value (away from the y-array => extrapolation)
    * \return int16_t                  z-value

    //--------------------------------------------------------------------------
    // for example

    int16_t arr_x_2d[] = {10,20,30,40,50};
    int16_t arr_y_2d[] = {100,200,300};

    // y * x Matrix
    int16_t arr_z[] = {
        10,  20,  50, 90,150,
        25,  70, 150,250,400,
        50, 120, 240,400,860
    };

    ret = os_util_lookup2D(arr_x, arr_y, 5, 3, arr_z, 25, 270);   // ret == 159
    //--------------------------------------------------------------------------





    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // ACTIVATE PORT INTERRUPT
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    Goto graph_defines.h and activate #define PORT_INTERRUPT_ACTIVE (or in graphical project use MODULE_CONFIG_STRING and set it to 0x02)

    Initialization code:

    void user_int_port_init(uint8_t channel_def);

    Example:
    Initialization port interrupt D_IN0

    user_int_port_init(D_IN0);




    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // READ µC TEMPERATURE
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    // This feature is only available if os_analog_pin[] in os_io_tables.c contains an
    // ADC channel for temperature with column parameter1 set to 224

    int8_t os_temperature_read(void);

    // e.g.
    ret = os_temperature_read();  // ret = 32 => 32°C



    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // CHECK CAN STATE / ERRORS
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    uint8_t os_can_check_error(void);

    Return values:
    0: 0   <= transmit error counter <= 96
    1: 96  <  transmit error counter <= 127
    2: 127 <  transmit error counter <= 255
    3: transmit error counter > 255



    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // READ ADC-VALUES ON YOUR OWN
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    // At first set #define ADC_AUTO_DISABLE in user_code.h

    // To start reading of e.g. ADC channel 8 type:

    bios_analog_select_channel(8);

    // When the value is analog-digital converted an interrupt will raise and call
    // the procedure "void user_int_adc(void);" in user_code.c.
    // To read the value and acknowledge the interrupt call

    variable1 = bios_analog_get_channel_single();

    // After that you can stop reading adc-values or continue with ch9 by calling:

    bios_analog_select_channel(9);


    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // EXAMPLES:
    //  - Read analog pin ANA1 and send it on CAN bus on ID 0x18FA3000 byte 0+1
    //  - Switch the output OUT_HSD2 when bit8 of byte3 of 0x1FF004AB is "1"
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    // GRAPH DISABLED:

    variable1 = os_algin(ANA1);

    os_can_send_message(0x18FA3000, 1, 8, (uint8_t)variable1, (uint8_t)(variable1>>8), 0, 0, 0, 0, 0, 0);

    // For switching of output OUT_HSD2 see procedure user_can_message_receive() at the end...



    // WITH GRAPH:

    variable1 = os_algin(ANA1);

    can_db_set_value(0, DATA2, variable1); // DATA must be defined in #can1_datenpunkt_db_const


    variable2 = (uint8_t)can_db_get_value(0, DATA3); // DATA3 must be defined in #can1_datenpunkt_db_const

    os_digout(OUT_HSD3, variable2);




    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // USE LIN bus functionality
    //--------------------------------------------------------------------------
    // Actual LIN stack software version string in this macro --> MRS_LIN_STACK_SW_VERSION
    // In case of LIN communication the LIN transceiver EN Pin must be enabled on init (for example os_digout(DO_LIN_EN, 1);)
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    * \ingroup  lin
    * \brief    get the datapoint value from the LIN database
    * \details  
    *           
    * \pre      
    *           
    * \param    datapoint_id    [in] uint32_t   index of the LIN datapoint
    * \return   uint32_t                        the datapoint value
    //--------------------------------------------------------------------------
    uint32_t lin_db_get_value(uint32_t datapoint_id);
    
    value = lin_db_get_value(LIN0_RX_SIGNAL_NAME_15)
    
    //--------------------------------------------------------------------------
    * \ingroup  lin
    * \brief    set / write a datapoint value to the LIN database
    * \details  
    *           
    * \pre      
    *           
    * \param    datapoint_id    [in] uint32_t   index of the LIN datapoint
    * \param    set_value       [in] uint32_t   value to set / write
    * \return   void      
    //--------------------------------------------------------------------------
    void lin_db_set_value(uint32_t datapoint_id, uint32_t set_value);
    
    lin_db_set_value(LIN0_TX_SIGNAL_NAME_1, 0x0F);
    
    //--------------------------------------------------------------------------
    * \ingroup  lin
    * \brief    Check if a frame from the selected lin_module was received,\n
    *           without knowing about request or response frame on master or slave.
    * \details  
    *           
    * \pre      
    *           
    * \param    lin_module  [in] uint8_t    LIN index number --> enum_lin_bus_id
    * \param    frame_index [in] uint8_t    frame index number or name from enum_lin_frame_id
    * \param    reset       [in] uint8_t    TRUE (1) clear the flag to detect a new receive, FALSE (0) don't clear the flag to reset it manual
    * \return   uint8_t                     TRUE (1) received, FALSE (0) nothing received
    //--------------------------------------------------------------------------
    uint8_t lin_check_for_received_frame(uint8_t lin_module, uint8_t frame_index, uint8_t reset);

    if( lin_check_for_received_frame(LIN_BUS_0, LIN0_FRM_RX_INDEX_NAME_01, TRUE) == TRUE )
    {
        // frame was received
    }

	//--------------------------------------------------------------------------
     * \ingroup  lin
     * \brief    Check if a header form the selected lin_module was received.
     *
     * \details  After received a header you must clear the flag with the command
     *           lin_clear_response_frame_flag(frame_index);
     *           If you don´t clear the frame you will receive just one frame.
     * \pre
     *
     * \param    frame_index	[in] uint8_t	frame index number or name from enum_lin_frame_id
	//--------------------------------------------------------------------------

  	if (lin_check_for_received_response_frame(uint8_t frame_index))
  	{
  	lin_clear_response_frame_flag( uint8_t frame_index );
  	}

    //--------------------------------------------------------------------------
    * \ingroup  lin
    * \brief    Clear the response frame flag to transmit the slave response data field.
    * \details  On Slave mode to transmit the slave response data field./n
    *           On Master mode to tell the stack that we have read all received data./n
    *           It's not functional necessary for Master mode.
    * \pre      
    *           
    * \param    frame_index [in] uint8_t frame index number or name from enum_lin_frame_id
    * \return   void      
    //--------------------------------------------------------------------------
    void lin_clear_response_frame_flag(uint8_t frame_index);

    lin_clear_response_frame_flag(LIN0_FRM_RESP_INDEX_NAME_01);

    //--------------------------------------------------------------------------
    * \ingroup  lin
    * \brief    Clear the request frame flag to detect a new receive.
    * \details  Only on Slave mode to detect a master request frame correctly.
    *
    * \pre      
    *           
    * \param    frame_index [in] uint8_t frame index number or name from enum_lin_frame_id
    * \return   void      
    //--------------------------------------------------------------------------
    void lin_clear_request_frame_flag(uint8_t frame_index);

    lin_clear_request_frame_flag(LIN0_FRM_REQ_INDEX_NAME_01);

    //--------------------------------------------------------------------------
    // LIN Master only functionality
    //--------------------------------------------------------------------------
    * \ingroup  lin
    * \brief    Schedule table handling and bus idle check with automatic go to sleep command if bus was idle for 4s.
    * \details  --> lin_schedule_handling() must be called for each bus schedule table\n
    *           With lin_st_active parameter is it possible to hold and resume a schedule table.
    * \pre      
    *           
    * \param    lin_schedule_table_index [in] uint8_t
    * \param    lin_st_active            [in] uint8_t
    * \return   void      
    //--------------------------------------------------------------------------
    void lin_schedule_handling(uint8_t lin_schedule_table_index, uint8_t lin_st_active);

    lin_schedule_handling(LIN0_SCHEDULE_TABLE_NR1, TRUE);

    //--------------------------------------------------------------------------
    * \ingroup  lin
    * \brief    help function to reset a started schedule table, reset the schedule line index
    * \details  call this function only one time to reset the schedule line index,\n
    *           other you send only the first frame at the first schedule line
    * \pre      
    *           
    * \param    lin_schedule_table_index [in] uint8_t
    * \return   void      
    //--------------------------------------------------------------------------
    void lin_schedule_handling_reset(uint8_t lin_schedule_table_index);

    lin_schedule_handling_reset(LIN0_SCHEDULE_TABLE_NR1);

    //--------------------------------------------------------------------------
    * \ingroup  lin
    * \brief    Check if response timeout was received, only on Master mode.
    * \details  
    *           
    * \pre      
    *           
    * \param    frame_index [in] uint8_t    frame index number or name from enum_lin_frame_id
    * \return   uint8_t                     TRUE (1) = Slave not responding (timeout), FALSE (0) = not timeout reached
    //--------------------------------------------------------------------------
    uint8_t lin_ma_check_frame_resp_timeout(uint8_t frame_index);

    if( lin_ma_check_frame_resp_timeout(LIN0_FRM_INDEX_NAME_01) == TRUE )
    {
        // timeout reached - Slave not responding
    }


    */
}



/// \ingroup user
/// \brief           Manually interpret the CAN messages
//--------------------------------------------------------------------------
///                  When a CAN message is received this function will be
///                  automatically called in main-loop, while reading from
///                  the buffered messages. This routine is not called in
///                  CAN-interrupt.
///
/// \param *msg      Pointer to the message with its struct bios_can_msg_typ
/// \return          None
//--------------------------------------------------------------------------
void user_can_message_receive(bios_can_msg_typ* msg)
{
    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)msg;

    /*
    // When 0x400 is received, send an acknowledge
    if( (msg->id == 0x400) && (msg->id_ext == 0) )
    {
        if(msg->data[0] == 0x33)
        os_can_send_message(0x720, 0, 8, 0x66, 0x33, 0x11, 0, 0, 0, 0, msg->data[7]);
    }
    else
    {
        // do nothing
    }

    // Switch the output OUT_HSD2 when bit8 of byte3 of 0x1FF004AB is "1"
    if( (msg->id == 0x1FF004AB) && (msg->id_ext == 1) )
    {
        os_digout(OUT_HSD2, (msg->data[3] & 0x80));
    }
    else
    {
        // do nothing
    }
    */
}


/// \ingroup user
/// \brief           Receive interrupt of serial communication interface (RS485)
//--------------------------------------------------------------------------
///                  When a message on SCI (RS485) is received, this function is
///                  called directly in the interrupt
///
/// \param data      The received byte
/// \return          None
//--------------------------------------------------------------------------
void user_int_rx_sci(uint8_t module, uint8_t data)
{
    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)module;
    (void)data;
}


/// \ingroup user
/// \brief           Timer tpm2 interrupt every 1ms
//--------------------------------------------------------------------------
///                  Take care not to put much code in here
///
/// \return          None
//--------------------------------------------------------------------------
void user_int_timer_1ms(void)
{

}


/// \ingroup user
/// \brief           Timer tpm1 interrupt
//--------------------------------------------------------------------------
///                  If activated this function is called on timer interrupt
///                  For initialization set #define TIMER_CHANNELS_INT_ACTIVE in graph_defines.h and call
///                  os_init_timer_channel(uint8_t channel, uint8_t pulse_type); in usercode_init();.
///                  Possible pulse_type: PWM_READ_RISING, PWM_READ_FALLING, PWM_READ_RISING_FALLING
/// \return          None
//--------------------------------------------------------------------------
void user_int_timer_channels(uint8_t channel)
{

}


/// \ingroup user
/// \brief           Port interrupt
//--------------------------------------------------------------------------
///                  If activated this function is called on port interrupt
///
/// \param k         Index of os_port_int_val[] - structure
/// \return          None
//--------------------------------------------------------------------------
void user_int_port(uint8_t k)
{
    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)k;

    // For initialization set #define PORT_INTERRUPT_ACTIVE in graph_defines.h

    // If only one port interrupt is active, you know which one it is (discard parameter k)
    // If several port interrupts are active, they should either be on different ports or
    // you can check logic level with os_pin_read() to decide depending on interrupt edge
    // if this pin generated the port interrupt
}


/// \ingroup user
/// \brief           ADC-interrupt
//--------------------------------------------------------------------------
///                  This procedure is called, when an ADC-Value is
///                  converted and ready to be read.
///
/// \return          None
//--------------------------------------------------------------------------
void user_int_adc(void)
{
  (void)bios_analog_get_channel_single(); // This function returns the 12bit ADC-value
}


/// \ingroup user
/// \brief           Status interrupt of serial communication interface
//--------------------------------------------------------------------------
///                  When a status interrupt on SCI occurs, this function is
///                  called directly in the interrupt
///
/// \return          None
//--------------------------------------------------------------------------
void user_int_stat_sci(void)
{

}



// EOF
