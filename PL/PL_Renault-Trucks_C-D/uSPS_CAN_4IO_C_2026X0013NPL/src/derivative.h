
#ifdef HCS08DZ128_ACTIVE
    #include <MC9S08DZ128.H>
#elif defined HCS08DZ48_ACTIVE
    #include <MC9S08DZ48.H>
#else
    #include <MC9S08DZ60.H>
#endif

#define _Stop asm ( stop; )

#define _Wait asm ( wait; )



