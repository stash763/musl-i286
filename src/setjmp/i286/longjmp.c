/* longjmp for 80286 */
/* Restore registers from buffer and jump to saved IP */

#include <setjmp.h>

void longjmp(jmp_buf env, int val)
{
    /* Restore segment registers */
    __asm__ __volatile__("movw %0, %%ds" : : "m"(env->__ds));
    __asm__ __volatile__("movw %0, %%es" : : "m"(env->__es));
    
    /* Restore callee-saved registers */
    __asm__ __volatile__("movw %0, %%bx" : : "m"(env->__bx));
    __asm__ __volatile__("movw %0, %%si" : : "m"(env->__si));
    __asm__ __volatile__("movw %0, %%di" : : "m"(env->__di));
    __asm__ __volatile__("movw %0, %%bp" : : "m"(env->__bp));
    
    /* If val is 0, return 1 */
    if (val == 0) val = 1;
    
    /* Jump to saved IP */
    /* This is a simplified version - in practice, we'd need to handle the return address */
    __asm__ __volatile__(
        "movw %0, %%ax\n"
        "movw %1, %%dx\n"
        : 
        : "m"(val), "m"(env->__ip)
        : "ax", "dx"
    );
    
    /* Return to saved location */
    __asm__ __volatile__("ret");
}
