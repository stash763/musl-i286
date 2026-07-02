/* setjmp for 80286 */
/* Save registers to buffer: BX, SI, DI, BP, DS, ES, IP */

#include <setjmp.h>

int setjmp(jmp_buf env)
{
    /* Save callee-saved registers */
    env->__bx = __builtin_ia32_bx();
    env->__si = __builtin_ia32_si();
    env->__di = __builtin_ia32_di();
    env->__bp = __builtin_ia32_bp();
    
    /* Save segment registers */
    __asm__ __volatile__("movw %%ds, %0" : "=m"(env->__ds));
    __asm__ __volatile__("movw %%es, %0" : "=m"(env->__es));
    
    /* Save return address (IP) - this is tricky in C */
    /* We use a label and compute the offset */
    __asm__ __volatile__("movw $1f, %0" : "=m"(env->__ip));
    __asm__ __volatile__("1:");
    
    return 0;
}
