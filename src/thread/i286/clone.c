/* Thread clone - stub for initial port */
/* OS/2 1.x does not support clone() in the Linux sense */

#define _GNU_SOURCE
#include <sched.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>

int clone(int (*fn)(void *), void *child_stack, int flags, void *arg, ...)
{
    (void)fn;
    (void)child_stack;
    (void)flags;
    (void)arg;
    errno = ENOSYS;
    return -1;
}
