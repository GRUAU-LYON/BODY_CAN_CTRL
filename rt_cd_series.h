#ifndef RT_CD_SERIES_H
#define RT_CD_SERIES_H

#include "user_code.h"   /* uint8/uint16/uint32, types ICCS */

/* =======================================================================
 * Renault Trucks C/D - Carrossier / BBM (doc 936002-fr)
 * Base de données NO-FLOAT (entiers + flags de validité)
 * =======================================================================
 *
 * Scales:
 *  - SPN 84  speed:       km/h * 256 (1/256 km/h/bit)
 *  - SPN 190 engine rpm:  rpm (raw/8 ; 0.125 rpm/bit)
 *  - SPN 96  fuel level:  % * 10  (0.4%/bit -> %*10 = raw*4)
 *  - SPN 158 IGN voltage: mV (0.05V/bit -> mV = raw*50)
 *
 * Switch states (2 bits): 00 inactive, 01 active, 10 error, 11 not available
 */

typedef struct
{
    /* PGN FEF1 (CCVS) */
    uint8  speed_valid;
    uint16 speed_kmh_x256;        /* SPN 84 */

    uint8  park_brake_valid;
    uint8  park_brake_state;      /* SPN 70 (2-bit state) */

    uint8  brake_sw_valid;
    uint8  brake_sw_state;        /* SPN 597 (2-bit state) */

    uint8  clutch_sw_valid;
    uint8  clutch_sw_state;       /* SPN 598 (2-bit state) */

    /* PGN F004 (EEC1) */
    uint8  rpm_valid;
    uint16 rpm;                   /* SPN 190 */

    /* PGN FEFC (Fuel) */
    uint8  fuel_lvl_valid;
    uint16 fuel_level_pct_x10;    /* SPN 96 */

    /* PGN FEF7 (Key switch battery potential) */
    uint8  ign_mv_valid;
    uint16 ign_mv;                /* SPN 158 */

    /* PGN FECA (Engine lamps) */
    uint8  eng_yellow_valid;
    uint8  eng_yellow_on;
    uint8  eng_red_valid;
    uint8  eng_red_on;

} rt_cd_db_t;

void rt_cd_series_init(void);
void rt_cd_series_on_can_frame(uint32 can_id_29b, uint8 dlc, uint8* data);
const rt_cd_db_t* rt_cd_series_get(void);

#endif /* RT_CD_SERIES_H */
