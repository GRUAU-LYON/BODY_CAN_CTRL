#include "iveco_eurocargo_j1939_series.h"
#include <string.h>

#define J1939_ID_MASK_29B  (0x1FFFFFFFUL)

#define PGN_EEC1 (0x00F004UL)
#define PGN_CCVS (0x00FEF1UL)
#define PGN_VEP1 (0x00FEF7UL)

#define TIMEOUT_CCVS_MS (500u)
#define TIMEOUT_EEC1_MS (500u)
#define TIMEOUT_VEP1_MS (1000u)

static iveco_eurocargo_db_t g_db;

static struct {
    uint32 now_ms;
    uint32 last_ccvs_ms;
    uint32 last_eec1_ms;
    uint32 last_vep1_ms;
} g_t;

static uint32 j1939_get_pgn(uint32 id29)
{
    uint32 pf = (id29 >> 16) & 0xFFUL;
    uint32 ps = (id29 >> 8)  & 0xFFUL;
    uint32 dp = (id29 >> 24) & 0x01UL;
    uint32 pgn = (dp << 16) | (pf << 8);
    if (pf >= 240UL) pgn |= ps;
    return pgn;
}

static uint16 u16_le(const uint8* d, uint8 ofs)
{
    return (uint16)((uint16)d[ofs] | ((uint16)d[ofs+1] << 8));
}

static void invalidate_all(void)
{
    g_db.speed_valid = 0U;
    g_db.rpm_valid = 0U;
    g_db.park_brake_valid = 0U;
    g_db.brake_sw_valid = 0U;
    g_db.ign_mv_valid = 0U;
}

void iveco_eurocargo_series_init(void)
{
    (void)memset(&g_db, 0, sizeof(g_db));
    (void)memset(&g_t, 0, sizeof(g_t));
    invalidate_all();
}

static void decode_ccvs(uint8 dlc, const uint8* data)
{
    uint8 b0, b3;
    uint16 raw_speed;

    if (dlc < 8u) return;

    b0 = data[0];
    b3 = data[3];

    /* SPN70 Parking brake switch: byte0 bits2..3 */
    {
        uint8 pb = (uint8)((b0 >> 2) & 0x03u);
        if (pb == 1u) { g_db.park_brake_state = 1u; g_db.park_brake_valid = 1u; }
        else if (pb == 0u) { g_db.park_brake_state = 0u; g_db.park_brake_valid = 1u; }
        else { g_db.park_brake_valid = 0u; }
    }

    /* SPN597 Brake switch: startbit 28 => byte3 bits4..5 */
    {
        uint8 bs = (uint8)((b3 >> 4) & 0x03u);
        if (bs == 1u) { g_db.brake_sw_state = 1u; g_db.brake_sw_valid = 1u; }
        else if (bs == 0u) { g_db.brake_sw_state = 0u; g_db.brake_sw_valid = 1u; }
        else { g_db.brake_sw_valid = 0u; }
    }

    /* SPN84 Wheel-based speed: bytes 1..2, scale 1/256 km/h/bit */
    raw_speed = u16_le(data, 1u);
    if (raw_speed != 0xFFFFu) { g_db.speed_kmh_x256 = raw_speed; g_db.speed_valid = 1u; }
    else { g_db.speed_valid = 0u; }

    g_t.last_ccvs_ms = g_t.now_ms;
}

static void decode_eec1(uint8 dlc, const uint8* data)
{
    uint16 raw_rpm;
    if (dlc < 8u) return;

    /* SPN190 engine speed: startbit24 => bytes3..4, scale 0.125 rpm/bit */
    raw_rpm = u16_le(data, 3u);
    if (raw_rpm != 0xFFFFu) { g_db.rpm = (uint16)(raw_rpm >> 3); g_db.rpm_valid = 1u; }
    else { g_db.rpm_valid = 0u; }

    g_t.last_eec1_ms = g_t.now_ms;
}

static void decode_vep1(uint8 dlc, const uint8* data)
{
    uint16 raw_key;
    if (dlc < 8u) return;

    /* SPN158 Keyswitch battery potential: bytes6..7, 0.05V/bit -> mV = raw*50 */
    raw_key = u16_le(data, 6u);
    if (raw_key != 0xFFFFu) {
        uint32 mv = (uint32)raw_key * 50ul;
        if (mv > 65535ul) mv = 65535ul;
        g_db.ign_mv = (uint16)mv;
        g_db.ign_mv_valid = 1u;
    } else {
        g_db.ign_mv_valid = 0u;
    }

    g_t.last_vep1_ms = g_t.now_ms;
}

void iveco_eurocargo_series_on_can_frame(uint32 can_id_29b, uint8 dlc, const uint8* data)
{
    uint32 id29;
    uint32 pgn;

    if (data == 0) return;

    id29 = (can_id_29b & J1939_ID_MASK_29B);
    pgn = j1939_get_pgn(id29);

    switch (pgn) {
        case PGN_CCVS: decode_ccvs(dlc, data); break;
        case PGN_EEC1: decode_eec1(dlc, data); break;
        case PGN_VEP1: decode_vep1(dlc, data); break;
        default: break;
    }
}

void iveco_eurocargo_series_tick_10ms(void)
{
    g_t.now_ms += 10ul;

    if ((g_t.now_ms - g_t.last_ccvs_ms) > (uint32)TIMEOUT_CCVS_MS) {
        g_db.speed_valid = 0u;
        g_db.park_brake_valid = 0u;
        g_db.brake_sw_valid = 0u;
    }
    if ((g_t.now_ms - g_t.last_eec1_ms) > (uint32)TIMEOUT_EEC1_MS) {
        g_db.rpm_valid = 0u;
    }
    if ((g_t.now_ms - g_t.last_vep1_ms) > (uint32)TIMEOUT_VEP1_MS) {
        g_db.ign_mv_valid = 0u;
    }
}

const iveco_eurocargo_db_t* iveco_eurocargo_series_get(void)
{
    return &g_db;
}
