#ifndef VEHICLE_LAYER_H
#define VEHICLE_LAYER_H

#include "user_code.h"
#include "vehicle_select.h"

/* Normalized vehicle data consumed by user_code (stable API). */
typedef enum
{
    VEH_PARK_BRAKE_RELEASED = 0,
    VEH_PARK_BRAKE_APPLIED  = 1
} veh_park_brake_state_t;

typedef struct
{
    uint8  speed_valid;
    uint16 speed_kmh_x256;     /* km/h * 256 */

    uint8  rpm_valid;
    uint16 rpm;               /* rpm integer */

    uint8  park_brake_valid;
    uint8  park_brake_state;  /* veh_park_brake_state_t */

    uint8  brake_sw_valid;
    uint8  brake_sw_pressed;  /* 0/1 */

    uint8  clutch_sw_valid;
    uint8  clutch_sw_pressed; /* 0/1 */

    uint8  ign_mv_valid;
    uint16 ign_mv;            /* mV */

    uint8  fuel_lvl_valid;
    uint16 fuel_level_pct_x10; /* % * 10 */

    uint8  eng_yellow_valid;
    uint8  eng_yellow_on;
    uint8  eng_red_valid;
    uint8  eng_red_on;

} vehicle_data_t;

/* Lifecycle */
void vehicle_layer_init(void);

/* Call on each received CAN frame (29-bit ID already OK; function masks internally). */
void vehicle_layer_on_can_frame(uint32 can_id_29b, uint8 dlc, uint8* data);

/* Call every 10ms for timeouts/validity handling. */
void vehicle_layer_tick_10ms(void);

const vehicle_data_t* vehicle_layer_get(void);

#endif /* VEHICLE_LAYER_H */
