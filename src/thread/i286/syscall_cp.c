/* Cancellation point syscall - stub for initial port */
/* No thread cancellation for initial port */

#define _GNU_SOURCE
#include <signal.h>
#include "syscall.h"
#include "libc.h"

long __syscall_cp_sysnr(long nr, ...)
{
    /* For initial port, just call the regular syscall */
    long (*f)(long, ...) = (long (*)(long, ...))__syscall;
    return f(nr);
}
