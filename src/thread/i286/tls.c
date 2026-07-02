/* Thread-local storage - stub for initial port */
/* No TLS support on OS/2 1.x initially */

#define _GNU_SOURCE
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include "libc.h"
#include "pthread_impl.h"

static struct tls_module main_tls;

void *__copy_tls(unsigned char *mem)
{
    (void)mem;
    return &__libc;
}

void __init_tls(long *auxv)
{
    (void)auxv;
    /* No TLS initialization for initial port */
}

void __reset_tls(void)
{
    /* No TLS reset for initial port */
}
