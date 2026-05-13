#ifndef _GRAPH_INDEXTYP_H_
#define _GRAPH_INDEXTYP_H_

typedef unsigned int index_type;



#ifdef GRAPH_USE_DOUBLE

  #define GRAPH_LONG double
  #define GRAPH_ULONG double

#else

  #define GRAPH_LONG signed long int
  #define GRAPH_ULONG unsigned long int

#endif

#endif
