/* Thread pointer access - stub for initial port */
/* No thread-local storage on OS/2 1.x initially */

static inline uintptr_t __get_tp(void)
{
    return 0;
}

#define TP_ADJ(p) (p)

#define MC_PC eip

/* No TLS_ABOVE_TP for initial port */
/* No TLS_ABOVE_TP */

/* No canary for initial port */
/* No CANARY_PAD */

/* No DT_EXITED, DT_EXITING, DT_JOINABLE, DT_DETACHED */
/* These are defined in pthread_impl.h */

/* No pthread_self() for initial port */
/* __pthread_self() will return &__libc */
