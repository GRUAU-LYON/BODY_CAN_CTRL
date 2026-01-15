ULTRA ROBUST PACKAGE (DIRECT IO)

Included files:
- vehicle_select.h
- vehicle_layer.c / vehicle_layer.h  (stable vehicle_data_t API)
- rt_cd_series.c / rt_cd_series.h    (Renault Trucks)
- iveco_eurocargo_j1939_series.c / iveco_eurocargo_j1939_series.h  (IVECO Eurocargo subset + timeouts)
- user_code.c / user_code.h          (direct DO_*/DI_* usage)

Integration requirements:
- Call vehicle_layer_init() once at boot.
- Call vehicle_layer_tick_10ms() every 10 ms.
- Call vehicle_layer_on_can_frame(can_id_29b, dlc, data) on each received CAN frame.
- User edits user_code.c to choose DO_87 / DO_C / etc.

Notes:
- IVECO model currently decodes CCVS (speed, park brake, brake switch), EEC1 (rpm), VEP1 (keyswitch voltage -> ign_mv).
- Add additional PGNs later without changing user_code API.

ICCS SDK note: user_code.c keeps mandatory hooks. Verify bios_can_msg_typ fields (id/len/data) and adapt if needed.


ICCS SDK verification:
- bios_can_msg_typ fields verified in src/bios_can.h: id, id_ext, remote_tx, data[8], len, prty.
- user_can_message_receive() now uses these exact fields, clamps DLC to 8, ignores remote frames, and normalizes ID.
