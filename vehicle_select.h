#ifndef VEHICLE_SELECT_H
#define VEHICLE_SELECT_H

/* =======================================================================
 * VEHICLE SELECT (compile-time)
 * Décommenter EXACTEMENT un modèle véhicule.
 * ======================================================================= */

/* #define RT_C_D_SERIES */
#define IVECO_EUROCARGO_J1939

#if (defined(RT_C_D_SERIES) + defined(IVECO_EUROCARGO_J1939)) > 1
#error "Select only ONE vehicle in vehicle_select.h"
#endif

#if !defined(RT_C_D_SERIES) && !defined(IVECO_EUROCARGO_J1939)
#error "No vehicle selected in vehicle_select.h"
#endif

#endif /* VEHICLE_SELECT_H */
