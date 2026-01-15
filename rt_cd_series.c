#include "rt_cd_series.h"

/* PGN (J1939) */
#define PGN_FEF1   0x00FEF1UL  /* CCVS */
#define PGN_F004   0x00F004UL  /* EEC1 */
#define PGN_FEFC   0x00FEFCUL  /* Fuel */
#define PGN_FEF7   0x00FEF7UL  /* Key switch batt potential */
#define PGN_FECA   0x00FECAUL  /* Lamps */

static rt_cd_db_t g_db;

static uint32 j1939_extract_pgn(uint32 can_id_29b)
{
    uint32 dp;
    uint32 pf;
    uint32 ps;
    uint32 pgn;

    dp = (can_id_29b >> 24) & 0x1UL;
    pf = (can_id_29b >> 16) & 0xFFUL;
    ps = (can_id_29b >> 8)  & 0xFFUL;

    pgn = (dp << 16) | (pf << 8);
    if (pf >= 240UL) { pgn |= ps; }
    return pgn;
}

void rt_cd_series_init(void)
{
    g_db.speed_valid = 0U; g_db.speed_kmh_x256 = 0U;
    g_db.park_brake_valid = 0U; g_db.park_brake_state = 0U;
    g_db.brake_sw_valid = 0U; g_db.brake_sw_state = 0U;
    g_db.clutch_sw_valid = 0U; g_db.clutch_sw_state = 0U;
    g_db.rpm_valid = 0U; g_db.rpm = 0U;
    g_db.fuel_lvl_valid = 0U; g_db.fuel_level_pct_x10 = 0U;
    g_db.ign_mv_valid = 0U; g_db.ign_mv = 0U;
    g_db.eng_yellow_valid = 0U; g_db.eng_yellow_on = 0U;
    g_db.eng_red_valid = 0U; g_db.eng_red_on = 0U;
}

const rt_cd_db_t* rt_cd_series_get(void)
{
    return &g_db;
}

void rt_cd_series_on_can_frame(uint32 can_id_29b, uint8 dlc, uint8* data)
{
    uint32 pgn;
    uint8  b0, b1, b2, b3, b6, b7;
    uint16 raw16;
    uint8  state2;
    uint16 tmp;

    if (!data) { return; }
    (void)dlc;

    pgn = j1939_extract_pgn(can_id_29b);

    switch (pgn)
    {
        case PGN_FEF1:
            b0 = data[0];
            b1 = data[1];
            b2 = data[2];
            b3 = data[3];

            /* SPN 70: start bit 0 len 2 -> data[0] bits 0..1 */
            state2 = (uint8)(b0 & 0x3U);
            g_db.park_brake_state = state2;
            g_db.park_brake_valid = (uint8)((state2 == 0U) || (state2 == 1U));

            /* SPN 84: start bit 8 len 16 -> data[1..2] LE */
            raw16 = (uint16)((uint16)b1 | ((uint16)b2 << 8));
            g_db.speed_kmh_x256 = raw16;
            g_db.speed_valid = 1U;

            /* SPN 597: start bit 28 len 2 -> data[3] bits 4..5 */
            state2 = (uint8)((b3 >> 4) & 0x3U);
            g_db.brake_sw_state = state2;
            g_db.brake_sw_valid = (uint8)((state2 == 0U) || (state2 == 1U));

            /* SPN 598: start bit 30 len 2 -> data[3] bits 6..7 */
            state2 = (uint8)((b3 >> 6) & 0x3U);
            g_db.clutch_sw_state = state2;
            g_db.clutch_sw_valid = (uint8)((state2 == 0U) || (state2 == 1U));
            break;

        case PGN_F004:
            /* SPN 190: start bit 24 len 16 -> data[3..4] LE */
            raw16 = (uint16)((uint16)data[3] | ((uint16)data[4] << 8));
            g_db.rpm = (uint16)((raw16 + 4U) / 8U);
            g_db.rpm_valid = 1U;
            break;

        case PGN_FEFC:
            /* SPN 96: byte 2 (index 1) ; 0.4%/bit -> %*10 = raw*4 */
            tmp = (uint16)data[1];
            g_db.fuel_level_pct_x10 = (uint16)(tmp * 4U);
            g_db.fuel_lvl_valid = 1U;
            break;

        case PGN_FEF7:
            /* SPN 158: start bit 48 len 16 -> data[6..7] LE ; mV = raw*50 */
            b6 = data[6];
            b7 = data[7];
            raw16 = (uint16)((uint16)b6 | ((uint16)b7 << 8));
            tmp = (uint16)(raw16 * 50U);
            g_db.ign_mv = tmp;
            g_db.ign_mv_valid = 1U;
            break;

        case PGN_FECA:
            /* 2-bit states -> valid for 00/01, on for 01 */
            b0 = data[0];

            state2 = (uint8)((b0 >> 2) & 0x3U); /* yellow */
            g_db.eng_yellow_on = (uint8)(state2 == 1U);
            g_db.eng_yellow_valid = (uint8)((state2 == 0U) || (state2 == 1U));

            state2 = (uint8)((b0 >> 4) & 0x3U); /* red */
            g_db.eng_red_on = (uint8)(state2 == 1U);
            g_db.eng_red_valid = (uint8)((state2 == 0U) || (state2 == 1U));
            break;

        default:
            break;
    }
}
