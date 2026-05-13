
#include "graph_includes.h"

#pragma MESSAGE DISABLE C5915   

#define MEMBITARRAY_VALUES  (MEMBITARRAY_INDICES)
#define MEM16ARRAY_VALUES   (MEMBITARRAY_VALUES+MEM16ARRAY_INDICES)
#define MEM32ARRAY_VALUES   (MEM16ARRAY_VALUES+MEM32ARRAY_INDICES)
#define CONST32ARRAY_VALUES (MEM32ARRAY_VALUES+CONST32ARRAY_INDICES)



extern unsigned char membitarray[MEMBITARRAY_SIZE];
extern signed int mem16array[MEM16ARRAY_SIZE];
extern GRAPH_LONG mem32array[MEM32ARRAY_SIZE];
extern const GRAPH_LONG const32array[CONST32ARRAY_SIZE];
extern const GRAPH_LONG i2c_slaves[I2C_ARRAY_SIZE];
extern uint8 i2c_array[I2C_ARRAY_SIZE][I2C_BYTE_SIZE];

extern void modulhardwarecode(void);


GRAPH_LONG get_max(index_type index)
{
    if (index >= MEMBITARRAY_VALUES)
        if (index >= MEM16ARRAY_VALUES)
            if (index >= CONST32ARRAY_VALUES)
                return (GRAPH_LONG) 1;  
            else
#ifdef GRAPH_USE_DOUBLE
                return (GRAPH_LONG) 1e40; 
#else
    return (GRAPH_LONG) 0x7fffffff; 
#endif
    else
        return (GRAPH_LONG) 0x7fff; 
    else
        return 1;
}



GRAPH_LONG get_min(index_type index)
{
    if (index >= MEMBITARRAY_VALUES)
        if (index >= MEM16ARRAY_VALUES)
            if (index >= CONST32ARRAY_VALUES)
                return (GRAPH_LONG) 0;  
            else
#ifdef GRAPH_USE_DOUBLE
                return (GRAPH_LONG) -1e40; 
#else
    return (GRAPH_LONG) 0x80000000; 
#endif
    else
        return (GRAPH_LONG) 0x8000; 
    else
        return 1;
}







index_type temp1, temp2;           


GRAPH_LONG get(index_type index)
{
    if (index >= MEMBITARRAY_VALUES)                        
        if (index >= MEM16ARRAY_VALUES)                       
            if (index >= MEM32ARRAY_VALUES)                     
                if (index >= CONST32ARRAY_VALUES)
                    return (GRAPH_LONG) 0;  
                else
                {
                    temp2 = index-MEM32ARRAY_VALUES;
                    return (GRAPH_LONG) const32array[temp2]; 
                }
            else
            {
                temp1 = MEM16ARRAY_VALUES;
                temp2 = index-temp1;
                return (GRAPH_LONG) mem32array[temp2]; 
            }
        else
        {
            temp2 = index-MEMBITARRAY_VALUES;
            return (GRAPH_LONG) mem16array[temp2]; 
        }
    else
        if(membitarray[index >> 3] & bios_bitmask[index & 7])
            return 1;
        else
            return 0;

}



void set(index_type index, GRAPH_LONG value)
{
    index_type temp2;
    if (index >= MEMBITARRAY_VALUES)
    {
        if (index >= MEM16ARRAY_VALUES)
        {
            if (index >= MEM32ARRAY_VALUES)
                return; 
            else
            {
                temp2 = index-MEM16ARRAY_VALUES;
                mem32array[temp2] = value;  
                return;
            }
        }
        else
        {
            temp2 = index-MEMBITARRAY_VALUES;
            mem16array[temp2] = (uint16)(ROUND(value));  
            return;
        }
    }
    else
    {
        if((1 & ROUND(value)) > 0)
            membitarray[index >> 3] |= (bios_bitmask[index & 7]); 
        else
            membitarray[index >> 3] &= (~bios_bitmask[index & 7]); 
        return;
    }
}



uint8 slave_to_index(uint8 slave_in)
{
    uint8 cnt_it;   
    for (cnt_it=0;cnt_it<I2C_ARRAY_SIZE;cnt_it++)
        if (i2c_slaves[cnt_it] == slave_in)                       
            break;

    return cnt_it;

}



uint8 *get_pointer_to_i2c_array(uint8 slave_in) {

    return i2c_array[slave_in]; 

}



uint8 get_value_from_i2c_array(uint8 index1, uint8 index2) {

    return i2c_array[index1][index2];    
}



void write_value_to_i2c_array(uint8 index1, uint8 index2, uint8 the_value) {

    i2c_array[index1][index2] = the_value;    
}




void modbus_enable(uint8 mode_sel)
{
    if (sci_tx_buffer.rs485_de_pin)
    {
        os_pin_write(sci_tx_buffer.rs485_de_pin, mode_sel); 
        os_digout(   sci_tx_buffer.rs485_de_pin, mode_sel);

        if (os_port_pin[sci_tx_buffer.rs485_de_pin].multiplex)
        {
            modulhardwarecode();
        }
    }

}




