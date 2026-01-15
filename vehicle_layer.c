#include "vehicle_layer.h"

#if defined(RT_C_D_SERIES)
#include "rt_cd_series.h"
#endif

#if defined(IVECO_EUROCARGO_J1939)
#include "iveco_eurocargo_j1939_series.h"
#endif

static vehicle_data_t g_v;

static void vehicle_clear(void)
{
    g_v.speed_valid = 0U; g_v.speed_kmh_x256 = 0U;
    g_v.rpm_valid = 0U; g_v.rpm = 0U;
    g_v.park_brake_valid = 0U; g_v.park_brake_state = (uint8)VEH_PARK_BRAKE_RELEASED;
    g_v.brake_sw_valid = 0U; g_v.brake_sw_pressed = 0U;
    g_v.clutch_sw_valid = 0U; g_v.clutch_sw_pressed = 0U;
    g_v.ign_mv_valid = 0U; g_v.ign_mv = 0U;
    g_v.fuel_lvl_valid = 0U; g_v.fuel_level_pct_x10 = 0U;
    g_v.eng_yellow_valid = 0U; g_v.eng_yellow_on = 0U;
    g_v.eng_red_valid = 0U; g_v.eng_red_on = 0U;
}

void vehicle_layer_init(void)
{
    vehicle_clear();

#if defined(RT_C_D_SERIES)
    rt_cd_series_init();
#endif

#if defined(IVECO_EUROCARGO_J1939)
    iveco_eurocargo_series_init();
#endif
}

void vehicle_layer_on_can_frame(uint32 can_id_29b, uint8 dlc, uint8* data)
{
#if defined(RT_C_D_SERIES)
    const rt_cd_db_t* db;

    rt_cd_series_on_can_frame(can_id_29b, dlc, data);
    db = rt_cd_series_get();

    g_v.speed_valid = db->speed_valid;
    g_v.speed_kmh_x256 = db->speed_kmh_x256;

    g_v.rpm_valid = db->rpm_valid;
    g_v.rpm = db->rpm;

    g_v.park_brake_valid = db->park_brake_valid;
    g_v.park_brake_state = (uint8)((db->park_brake_valid && (db->park_brake_state == 1U))
                          ? VEH_PARK_BRAKE_APPLIED
                          : VEH_PARK_BRAKE_RELEASED);

    g_v.brake_sw_valid = db->brake_sw_valid;
    g_v.brake_sw_pressed = (uint8)(db->brake_sw_valid && (db->brake_sw_state == 1U));

    g_v.clutch_sw_valid = db->clutch_sw_valid;
    g_v.clutch_sw_pressed = (uint8)(db->clutch_sw_valid && (db->clutch_sw_state == 1U));

    g_v.ign_mv_valid = db->ign_mv_valid;
    g_v.ign_mv = db->ign_mv;

    g_v.fuel_lvl_valid = db->fuel_lvl_valid;
    g_v.fuel_level_pct_x10 = db->fuel_level_pct_x10;

    g_v.eng_yellow_valid = db->eng_yellow_valid;
    g_v.eng_yellow_on = db->eng_yellow_on;
    g_v.eng_red_valid = db->eng_red_valid;
    g_v.eng_red_on = db->eng_red_on;

#elif defined(IVECO_EUROCARGO_J1939)
    const iveco_eurocargo_db_t* db;

    iveco_eurocargo_series_on_can_frame(can_id_29b, dlc, (const uint8*)data);
    db = iveco_eurocargo_series_get();

    g_v.speed_valid = db->speed_valid;
    g_v.speed_kmh_x256 = db->speed_kmh_x256;

    g_v.rpm_valid = db->rpm_valid;
    g_v.rpm = db->rpm;

    g_v.park_brake_valid = db->park_brake_valid;
    g_v.park_brake_state = (uint8)((db->park_brake_valid && (db->park_brake_state == 1U))
                          ? VEH_PARK_BRAKE_APPLIED
                          : VEH_PARK_BRAKE_RELEASED);

    g_v.brake_sw_valid = db->brake_sw_valid;
    g_v.brake_sw_pressed = (uint8)(db->brake_sw_valid && (db->brake_sw_state == 1U));

    g_v.ign_mv_valid = db->ign_mv_valid;
    g_v.ign_mv = db->ign_mv;

    /* Not yet implemented for IVECO in this robust subset */
    g_v.clutch_sw_valid = 0U; g_v.clutch_sw_pressed = 0U;
    g_v.fuel_lvl_valid = 0U; g_v.fuel_level_pct_x10 = 0U;
    g_v.eng_yellow_valid = 0U; g_v.eng_yellow_on = 0U;
    g_v.eng_red_valid = 0U; g_v.eng_red_on = 0U;
#else
    (void)can_id_29b; (void)dlc; (void)data;
#endif
}

void vehicle_layer_tick_10ms(void)
{
#if defined(RT_C_D_SERIES)
    rt_cd_series_tick_10ms();
#endif
#if defined(IVECO_EUROCARGO_J1939)
    iveco_eurocargo_series_tick_10ms();
#endif
}

const vehicle_data_t* vehicle_layer_get(void)
{
    return &g_v;
}
