#ifndef _GRAPH_LIB_H_
#define _GRAPH_LIB_H_

#include "graph_includes.h"
#include "os_iee.h"
#include "MODBUS.H"

#define PRLX_FUNCTIONS_ACTIV        

#define volt *1000L  
#define Volt *1000L

#define sec  *1000L
#define Sec  *1000L

extern uint8  timer_diff;
extern uint16 graph_cycle_time;
extern uint8  graph_save_eeprom_flag;
extern uint16 eeprom_hsddaten[];
extern uint32 user_variable[];
extern void modulhardwarecode_sleep(void);  
extern unsigned int aktuelle_daten[];
extern unsigned int edit_aktuelle_daten[];

GRAPH_LONG get(index_type index);
void set(index_type index, GRAPH_LONG value);
GRAPH_LONG get_max(index_type index);
GRAPH_LONG get_min(index_type index);
uint8 slave_to_index(uint8 slave_in);
uint8 *get_pointer_to_i2c_array(uint8 slave_nr);
uint8 get_value_from_i2c_array(uint8 index1, uint8 index2);
void write_value_to_i2c_array(uint8 index1, uint8 index2, uint8 the_value);

void AND_2(index_type a, index_type b, index_type c);
void AND_4(index_type a, index_type b, index_type c, index_type d, index_type e);
void AND_6(index_type a, index_type b, index_type c, index_type d, index_type e, index_type f, index_type g);
void AVERAGE_2(index_type in1, index_type in2, index_type out);
void BUS_1BIT(index_type);
void BUS_16BIT(index_type);
void BYTE_SPLITTER(index_type in, index_type bit0, index_type bit1, index_type bit2, index_type bit3, index_type bit4, index_type bit5, index_type bit6, index_type bit7);
void CHANGE_DETECT(index_type mem, index_type in, index_type out);
void COMPARATOR(index_type a, index_type b, index_type out1, index_type out2);
void COMPARATOR_HYSTERESIS(index_type sig, index_type top, index_type bottom, index_type q);
void COMPARATOR_WINDOW(index_type sig, index_type top, index_type bottom, index_type q);
void CONVERTER_AD(index_type A, index_type D);
void CONVERTER_DA(index_type D, index_type A);
void COUNTER(index_type buff, index_type cnt, index_type sel, index_type dir, index_type r, index_type max,  index_type q);
void COUNTER_MIN_MAX(index_type buff, index_type buff_set, index_type cnt, index_type sel, index_type dir, index_type r, index_type min, index_type max, index_type set_it, index_type set_it_now, index_type limit, index_type q);
void D_FLIPFLOP(index_type buff, index_type in, index_type c, index_type out);
void D_FLIPFLOP_RES(index_type buff, index_type in, index_type c, index_type r, index_type out);
void D_LATCH(index_type buff, index_type c, index_type in, index_type out);
void DELAY(index_type buff, index_type in, index_type out);
void DELAY_OFF(index_type curpos, index_type in, index_type timepos, index_type out);
void DELAY_OFF_RTR(index_type timer, index_type in, index_type delay, index_type out);
void DELAY_ON(index_type curpos, index_type in, index_type timepos, index_type out);
void DELAY_ON_RTR(index_type curpos, index_type in, index_type timepos, index_type out);
void DELAY_ON_AND_OFF_RTR(index_type timer_on, index_type timer_off, index_type in, index_type delay, index_type out);
void DIG_0(index_type out);
void DIG_1(index_type out);
void EDGE_DETECT_LH(index_type mem, index_type in, index_type out);
void EDGE_DETECT_HL(index_type mem, index_type in, index_type out);
void LOW_PASS(index_type big_brain, index_type in, index_type anzahl, index_type out);
void MATH_ABS(index_type a, index_type q);
void MATH_ADD(index_type a, index_type b, index_type q);
void MATH_DIV(index_type in1, index_type in2, index_type out);
void MATH_MULDIV(index_type in, index_type mul, index_type div, index_type out);
void MATH_MUL(index_type in1, index_type in2, index_type out);
void MATH_SUB(index_type a, index_type b, index_type q);
void MERGE_TO_BYTE(index_type bit0, index_type bit1, index_type bit2, index_type bit3, index_type bit4, index_type bit5, index_type bit6, index_type bit7, index_type out);
void MERGE_TO_WORD(index_type byte0, index_type byte1, index_type byte2, index_type byte3, index_type out);
void MINMAX_MEM(index_type, index_type , index_type , index_type );
void MUX_2(index_type sel, index_type in0, index_type in1, index_type out);
void MUX_4(index_type sel0, index_type sel1, index_type in0, index_type in1, index_type in2,index_type in3, index_type out);
void MUX_4_DEZ(index_type sel, index_type in0, index_type in1, index_type in2,index_type in3, index_type out);
void MUX_5(index_type sel_0, index_type sel_1, index_type sel_2, index_type sel_3, index_type sel_4, index_type in_0, index_type in_1, index_type in_2, index_type in_3, index_type in_4, index_type out);
void MUX_OUT_4(index_type sel0, index_type sel1, index_type in, index_type out0, index_type out1,index_type out2, index_type out3);
void NOT(index_type a, index_type b);
void OR_2(index_type a, index_type b, index_type c);
void OR_4(index_type a, index_type b, index_type c, index_type d, index_type e);
void OR_6(index_type a, index_type b, index_type c, index_type d, index_type e, index_type f, index_type g);
void OSCILLATOR(index_type curpos, index_type sel, index_type tl, index_type th, index_type q);
void RAMP(index_type counter, index_type in, index_type max, index_type ms_pro_100_up, index_type ms_pro_100_down, index_type out);
void RANGE_LIMITER(index_type , index_type , index_type , index_type );
void RS_FLIPFLOP(index_type s, index_type r, index_type q);
void SAVE_EEPROM(uint16 eeprom_def, index_type in);
void SAVE_VALUE(index_type mem, index_type in, index_type trigger, index_type out);
void T_FLIPFLOP(index_type mem, index_type in, index_type reset, index_type out);
void VALUE(index_type value_, index_type out);
void WORD_SPLITTER(index_type in, index_type byte0, index_type byte1, index_type byte2, index_type byte3);
void XOR(index_type a, index_type b, index_type c);

void ALGIN(uint16 channel_def, index_type out);
void CAN_CHECK_ERROR(index_type out);
void DIGIN(index_type port_def, index_type pos);
void DIGOUT(index_type port_def, index_type in);
void FREQUENCY_CNT(uint16 channel_def, index_type out);
void FREQUENCY_CNT_VAL(uint16 channel_def, index_type out);
void INCREMENTAL_ENCODER(index_type mem, index_type channel_def1, index_type channel_def2, index_type min, index_type max, index_type clk, index_type init_val, index_type counter);
void I2C_READ_VAL (index_type slave_addr, index_type byte_nr, index_type out);
void I2C_WRITE_VAL(index_type slave_addr, index_type trigger_old, index_type the_value, index_type trigger_new, index_type byte_nr, index_type trigger_always);
void I2C_SEND(index_type slave_addr, index_type trigger_old, index_type index_start, index_type byte_length, index_type trigger_new, index_type trigger_always);
void I2C_REQUEST(index_type slave_addr, index_type trigger_old, index_type index_start, index_type byte_length, index_type trigger_new, index_type trigger_always);
void IN32_DB(uint16 index_db, index_type index_leitung_out);
void IN32_DB_CHECK(uint16 index_db, index_type out);
void OUT32_DB(uint16 index_db, index_type index_leitung_in);
void OUT32_DB_TRIGGER(uint16 index_db, index_type trigger_alt, index_type in, index_type trigger);
void OUT32_DB_STOP(index_type in);
void SLEEP_MODE(index_type mem, index_type c_in);
void TEMP_READ(index_type out);


void CALC_CYCLE_TIME (index_type out1, index_type out2);
void CAN_MSG_RCV (index_type out);
void CASE_MACHINE(index_type in);
void EEPROM_INCR(index_type index, index_type mem, index_type c);
void EEPROM_READ(index_type mem, index_type c);
void EEPROM_WRITE(index_type mem, index_type c);
void EEPROM_READ_VAR(index_type index, index_type out);
void EEPROM_WRITE_VAR(index_type index, index_type in);
void EEPROM_WRITE_VAR_TRIG(index_type index, index_type mem, index_type c, index_type in);
void HW_BL_ACCESS(index_type in);
void MODBUS_READ(index_type index, index_type out);
void MODBUS_WRITE(index_type index, index_type in);
void SEVEN_SEGMENT_DISPLAY(index_type number, index_type dot_position, index_type disabled);
void VARIABLE_OUT(uint16 index_def, index_type in);
void VARIABLE_IN(uint16 index_def, index_type in);

void PWM_OUTPUT_PROP_CAN(index_type prozent, index_type frequenz, index_type dither_freq, index_type dither_amp);
void PWM_CONTROL_PROP_CAN(index_type w, index_type rampe_ms_pro_A, index_type frequenz, index_type dither_freq, index_type dither_amp, index_type kp_mal_1024_min, index_type kp_mal_1024_max, index_type current_min, index_type current_max, index_type kp_mal_1024, index_type error_pwm);
void PWM_OUTPUT_PROP_CAN_60A(index_type duty1, index_type duty2, index_type pwm_frequency);
void PWM_OUTPUT_CAN_IO(index_type freq_in, index_type duty_hsd2, index_type duty_hsd3, index_type duty_hsd4, index_type duty_hsd5, index_type duty_hsd6, index_type duty_hsd7);
void PWM_OUTPUT_FULLBRIDGE(index_type mem_dir_in, index_type duty_cycle, index_type dir_in, index_type freq_in);
void PWM_OUTPUT_FULLBRIDGE_EXT(index_type mem_dir_in, index_type duty_cycle, index_type dir_in, index_type freq_in, index_type m2_trigger, index_type error_output);
void PWM_CONTROL_UNI(uint16 index_db, index_type w, index_type frequenz, index_type current_min, index_type current_max, index_type kp_mal_1024_min, index_type kp_mal_1024_max, index_type dither_amp, index_type dither_freq);
void PWM_OUTPUT_UNI(uint16 index_db, index_type w, index_type frequenz, index_type dither_amp, index_type dither_freq);
void SPECIFIC_VAL(GRAPH_LONG value_, index_type out_);
void ALG_CAL_STATE(index_type in);

void PWM_OUTPUT_FULLBRIDGE_10A (index_type motor_check,
                                index_type pwm_freq,
                                index_type dir,
                                index_type duty,
                                index_type ramp_max,
                                index_type ramp_up,
                                index_type ramp_dwn,
                                index_type err,
                                index_type curr);

extern void fullbridge_10A_block(uint16_t pwm_freq,
                                 uint16_t duty,
                                 uint16_t ramp_max,
                                 uint16_t ramp_up,
                                 uint16_t ramp_dwn,
                                 uint8_t dir,
                                 uint8_t motor_check,
                                 uint8_t* err_out,
                                 uint16_t* curr_out);

void MICROPLEX_HB (index_type motor_check,
                                index_type pwm_freq,
                                index_type dir,
                                index_type duty,
                                index_type ramp_max,
                                index_type ramp_up,
                                index_type ramp_dwn,
                                index_type err,
                                index_type curr,
                                index_type motor_voltage);

extern  void fullbridge_microplex_block(uint16_t pwm_freq,
                                        uint16_t duty,
                                        uint16_t ramp_max,
                                        uint16_t ramp_up,
                                        uint16_t ramp_dwn,
                                        uint8_t dir,
                                        uint8_t motor_check,
                                        uint8_t* err_out,
                                        uint16_t* curr_out,
                                        uint16_t* motor_voltage);


void MOT_CTRL_1X_FULLBRIDGE (index_type pwm_freq, 
                             index_type duty_HB1_FB, 
                             index_type duty_HB2, 
                             index_type ramp_up_time, 
                             index_type ramp_down_time, 
                             index_type rotation, 
                             index_type start_HB1_FB, 
                             index_type start_HB2,
                             index_type mode, 
                             index_type status_HB1_FB, 
                             index_type status_HB2,
                             index_type curr_HB1,
                             index_type curr_HB2);

extern void mot_ctrl_1x_fullbridge_block(uint16_t pwm_freq, 
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


void MIRROR_CTRL (index_type pwm_freq, 
                  index_type duty_lm,
                  index_type duty_rm,
                  index_type dir_lm,
                  index_type dir_rm,
                  index_type heater_lm,
                  index_type heater_rm,
                  index_type enable,
                  index_type stat_lm,
                  index_type stat_rm,
                  index_type curr_mirror_lm,
                  index_type curr_mirror_rm,
                  index_type curr_heater_lm,
                  index_type curr_heater_rm);

void MOT_CTRL_2X_FULLBRIDGE (index_type pwm_freq,
                  index_type duty_lm,
                  index_type duty_rm,
                  index_type dir_lm,
                  index_type dir_rm,
                  index_type heater_lm,
                  index_type heater_rm,
                  index_type enable,
                  index_type stat_lm,
                  index_type stat_rm,
                  index_type curr_mirror_lm,
                  index_type curr_mirror_rm,
                  index_type curr_heater_lm,
                  index_type curr_heater_rm);

extern void mirror_ctrl_block(uint16_t pwm_freq, 
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

    #ifdef PRLX_FUNCTIONS_ACTIV
        void SPECIFIC_DEVICE1(index_type net_1,
                              index_type net_2,
                              index_type net_3,
                              index_type net_4,
                              index_type net_5,
                              index_type net_6,
                              index_type net_7,
                              index_type net_17,
                              index_type net_18,
                              index_type net_19,
                              index_type net_24,
                              index_type net_25,
                              index_type net_26,
                              index_type net_27,
                              index_type verrieg_u_i,
                              index_type verrieg_taste_ein_aus,
                              index_type verrieg_handbremse,
                              index_type impuls_von_taste,
                              index_type reset_impuls,
                              index_type analogeingang_stromwert,
                              index_type filterwert_stromwert,
                              index_type abschaltwert_strom,
                              index_type reset_ueberstrom,
                              index_type not_aus,
                              index_type output,
                              index_type ueberstrom_out,
                              index_type stromwert_gefiltert);

        void SPECIFIC_DEVICE2(index_type net_3,
                              index_type net_4,
                              index_type net_5,
                              index_type net_6,
                              index_type net_7,
                              index_type net_8,
                              index_type net_19,
                              index_type net_21,
                              index_type net_22,
                              index_type verrieg_u_i,
                              index_type verrieg_taste_ein_aus,
                              index_type verrieg_handbremse,
                              index_type input_1,
                              index_type input_2,
                              index_type analogeingang_stromwert,
                              index_type filterwert_stromwert,
                              index_type abschaltwert_strom,
                              index_type not_aus,
                              index_type reset_ueberstrom,
                              index_type output,
                              index_type ueberstrom_out,
                              index_type stromwert_gefiltert);


        void SPECIFIC_DEVICE3(index_type net_1,
                              index_type net_2,
                              index_type net_3,
                              index_type net_4,
                              index_type net_5,
                              index_type net_6,
                              index_type net_7,
                              index_type net_8,
                              index_type net_9,
                              index_type net_19,
                              index_type net_20,
                              index_type net_21,
                              index_type net_30,
                              index_type net_31,
                              index_type net_32,
                              index_type net_33,
                              index_type net_34,
                              index_type verrieg_u_i,
                              index_type verrieg_taste_ein_aus,
                              index_type verrieg_handbremse,
                              index_type impuls_von_taste,
                              index_type reset_impuls,
                              index_type analogeingang_stromwert_1,
                              index_type filterwert_stromwert_1,
                              index_type abschaltwert_strom_1,
                              index_type analogeingang_stromwert_2,
                              index_type filterwert_stromwert_2,
                              index_type abschaltwert_strom_2,
                              index_type reset_ueberstrom,
                              index_type not_aus,
                              index_type output,
                              index_type ueberstrom_out,
                              index_type stromwert_gefiltert_1,
                              index_type stromwert_gefiltert_2);  


        void SPECIFIC_DEVICE4(index_type net_1,
                              index_type net_2,
                              index_type net_3,
                              index_type net_4,
                              index_type net_5,
                              index_type net_6,
                              index_type net_7,
                              index_type net_12,
                              index_type net_17,
                              index_type net_18,
                              index_type net_19,
                              index_type net_20,
                              index_type net_21,
                              index_type einschaltimpuls_taste,
                              index_type geschalteter_ausgang,
                              index_type i_mess_verzoegerung,
                              index_type stromwert_untergrenze,
                              index_type stromwert_gefiltert,
                              index_type nachlaufzeit_keine_last,
                              index_type kein_ausgang_aktiv,
                              index_type keine_last);                                          

        void SPECIFIC_DEVICE5(index_type net_1,
                              index_type net_2,
                              index_type net_3,
                              index_type net_4,
                              index_type net_6,
                              index_type net_7,
                              index_type net_8,
                              index_type net_9,
                              index_type net_12,
                              index_type net_16,
                              index_type net_17,
                              index_type net_18,
                              index_type net_19,
                              index_type net_20,
                              index_type net_21,
                              index_type net_22,
                              index_type net_24,
                              index_type net_25,
                              index_type net_26,
                              index_type net_27,
                              index_type net_28,
                              index_type net_29,
                              index_type net_30,
                              index_type net_31,
                              index_type net_32,
                              index_type zeit_reset_ueberstrom,
                              index_type zuendung_ein,
                              index_type ausschaltverzoegerung,
                              index_type can_wake_up_impuls,
                              index_type reset_ueberstrom_impuls,
                              index_type zuendung_aus_nach_1s,
                              index_type can_wake_up_trigger);

        void SPECIFIC_DEVICE6(index_type net_2,
                              index_type net_3,
                              index_type net_4,
                              index_type net_11,
                              index_type input,
                              index_type analogeingang_stromwert,
                              index_type filterwert_stromwert,
                              index_type abschaltwert_strom,
                              index_type reset_ueberstrom,
                              index_type output,
                              index_type stromwert_gefiltert);


        void ANA_TO_DIG_4(index_type net_11,
                              index_type net_12,
                              index_type net_13,
                              index_type net_14,
                              index_type net_15,
                              index_type net_16,
                              index_type net_17,
                              index_type net_18,
                              index_type ana_wert_1,
                              index_type ana_wert_2,
                              index_type ana_wert_3,
                              index_type ana_wert_4,
                              index_type anzahl_der_filterwerte,
                              index_type spannungsschaltschwelle,
                              index_type out_1,
                              index_type out_2,
                              index_type out_3,
                              index_type out_4);


        void ANA_TO_DIG_2(index_type net_7,
                              index_type net_8,
                              index_type net_9,
                              index_type net_10,
                              index_type ana_wert_1,
                              index_type ana_wert_2,
                              index_type anzahl_der_filterwerte,
                              index_type spannungsschaltschwelle,
                              index_type out_1,
                              index_type out_2);
    #endif


#endif

