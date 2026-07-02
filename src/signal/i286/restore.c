/* Signal restore - stub for initial port */
/* No signal handling for initial port */

#define _GNU_SOURCE
#include <signal.h>
#include <errno.h>

int __restore_rt(void)
{
    errno = ENOSYS;
    return -1;
}
