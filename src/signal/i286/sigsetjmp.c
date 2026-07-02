/* Signal setjmp - stub for initial port */
/* No signal handling for initial port */

#define _GNU_SOURCE
#include <setjmp.h>
#include <signal.h>

typedef struct {
    jmp_buf __jb;
    unsigned long __fl;
} sigjmp_buf_impl;

int sigsetjmp(sigjmp_buf env, int savemask)
{
    (void)savemask;
    return setjmp(env);
}

_Noreturn void siglongjmp(sigjmp_buf env, int val)
{
    longjmp(env, val);
}
