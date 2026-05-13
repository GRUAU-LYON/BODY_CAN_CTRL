#ifndef ZZGRAPHCODE
#define ZZGRAPHCODE 


#include "os.h"
#include "bios.h"
#include "can_db.h"
#include "graph_indextyp.h"
#include "graph_defines.h"
#include "graph_lib.h"

#define DATEN_IN 0
#define DATEN_OUT 1



#define DIG_PARAM(port,index) set(index,port)
#define ALG32_PARAM(port,index) set(index,port)

#ifdef GRAPH_USE_DOUBLE
  #define ROUND(x)       \
   if (x < 0)            \
     (int32)(x - 0.5)    \
   else                  \
     (int32)(x + 0.5)
#else                   
  #define ROUND(x) x
#endif                  



#endif
