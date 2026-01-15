#include "user_code.h"
#include "vehicle_layer.h"
#include "os_io.h"
#include "os_io_tables.h"

/* =========================================================================
 * Robust initialization guard
 * ========================================================================= */

void usercode_init(void)
{
    vehicle_layer_init();
}

static void app_ensure_init(void)
{
    static uint8 init_done = 0u;
    if (!init_done) {
        vehicle_layer_init();
        init_done = 1u;
    }
}

/* =========================================================================
 * Business logic (keep readable)
 * ========================================================================= */
void usercode(void)
{
    const vehicle_data_t* v;

    app_ensure_init();
    v = vehicle_layer_get();

    /* Gyro ON only if park brake is released */
    if (v->park_brake_valid && (v->park_brake_state == 0u)) {
        os_digout(DO_87, 1u);
    } else {
        os_digout(DO_87, 0u);
    }

    /* Scene light OFF if moving above 5 km/h */
    if (v->speed_valid && (v->speed_kmh_x256 > (5u * 256u))) {
        os_digout(DO_C, 0u);
    } else {
        os_digout(DO_C, 1u);
    }
}

/* =========================================================================
 * Mandatory ICCS hooks
 * ========================================================================= */
void user_can_message_receive(bios_can_msg_typ* msg)
{
    uint32 id;
    uint8 dlc;

    if (msg == 0) {
        return;
    }

    app_ensure_init();

    /* Filter remote frames if present */
    if (msg->remote_tx) {
        return;
    }

    id = (uint32)msg->id;
    dlc = (uint8)msg->len;
    if (dlc > 8u) {
        dlc = 8u;
    }

    /* Normalize ID width (ext vs std) */
    if (msg->id_ext) {
        id &= 0x1FFFFFFFul;
    } else {
        id &= 0x7FFu;
    }

    vehicle_layer_on_can_frame(id, dlc, (uint8*)msg->data);
}

void user_int_timer_1ms(void)
{
    static uint8 cnt10 = 0u;

    app_ensure_init();

    cnt10++;
    if (cnt10 >= 10u) {
        cnt10 = 0u;
        vehicle_layer_tick_10ms();
    }
}

void user_int_rx_sci(uint8_t module, uint8_t data) { (void)module; (void)data; }
void user_int_timer_channels(uint8_t channel) { (void)channel; }
void user_int_port(uint8_t k) { (void)k; }
void user_int_adc(void) { }
void user_int_stat_sci(void) { }
