#ifndef IVECO_EUROCARGO_J1939_SERIES_H
#define IVECO_EUROCARGO_J1939_SERIES_H

#include "user_code.h"

typedef struct
{
    uint8  speed_valid;
    uint16 speed_kmh_x256;

    uint8  rpm_valid;
    uint16 rpm;

    uint8  park_brake_valid;
    uint8  park_brake_state; /* 0 released, 1 applied */

    uint8  brake_sw_valid;
    uint8  brake_sw_state;   /* 0/1 */

    uint8  ign_mv_valid;
    uint16 ign_mv;

} iveco_eurocargo_db_t;

void iveco_eurocargo_series_init(void);
void iveco_eurocargo_series_on_can_frame(uint32 can_id_29b, uint8 dlc, const uint8* data);
void iveco_eurocargo_series_tick_10ms(void);

const iveco_eurocargo_db_t* iveco_eurocargo_series_get(void);

#endif /* IVECO_EUROCARGO_J1939_SERIES_H */
