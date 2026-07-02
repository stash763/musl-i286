/* FPU environment management for 80287 FPU */
/* Uses 80287 FPU instructions */

#include <fenv.h>
#include <stdint.h>

/* Clear floating-point exceptions */
int feclearexcept(int excepts)
{
    /* Use fnclex to clear all FPU exceptions */
    __asm__ __volatile__("fnclex");
    return 0;
}

/* Raise floating-point exceptions */
int feraiseexcept(int excepts)
{
    /* Get current status word */
    unsigned short sw;
    __asm__ __volatile__("fnstsw %0" : "=m"(sw));
    
    /* Set requested exceptions */
    sw |= (unsigned short)(excepts & 0x3f);
    
    /* Load modified status word */
    __asm__ __volatile__("fldenv %0" : : "m"(sw));
    
    return 0;
}

/* Get floating-point rounding mode */
int fegetround(void)
{
    unsigned short cw;
    __asm__ __volatile__("fnstcw %0" : "=m"(cw));
    return (int)(cw & 0xc00);
}

/* Set floating-point rounding mode */
int fesetround(int rnd)
{
    unsigned short cw;
    __asm__ __volatile__("fnstcw %0" : "=m"(cw));
    cw = (cw & ~0xc00) | (unsigned short)(rnd & 0xc00);
    __asm__ __volatile__("fldcw %0" : : "m"(cw));
    return 0;
}

/* Get floating-point environment */
int fegetenv(fenv_t *envp)
{
    __asm__ __volatile__("fnstenv %0" : "=m"(*envp));
    return 0;
}

/* Set floating-point environment */
int fesetenv(const fenv_t *envp)
{
    __asm__ __volatile__("fldenv %0" : : "m"(*envp));
    return 0;
}

/* Test floating-point exceptions */
int fetestexcept(int excepts)
{
    unsigned short sw;
    __asm__ __volatile__("fnstsw %0" : "=m"(sw));
    return (int)(sw & (unsigned short)(excepts & 0x3f));
}

/* Save floating-point environment */
int feholdexcept(fenv_t *envp)
{
    /* Get current environment */
    __asm__ __volatile__("fnstenv %0" : "=m"(*envp));
    
    /* Clear all exception masks */
    envp->__control_word |= 0x3f;
    
    /* Load modified environment */
    __asm__ __volatile__("fldenv %0" : : "m"(*envp));
    
    return 0;
}

/* Update floating-point environment */
int feupdateenv(const fenv_t *envp)
{
    /* Test current exceptions */
    unsigned short sw;
    __asm__ __volatile__("fnstsw %0" : "=m"(sw));
    
    /* Load new environment */
    __asm__ __volatile__("fldenv %0" : : "m"(*envp));
    
    /* Raise any saved exceptions */
    sw &= 0x3f;
    if (sw) {
        feraiseexcept((int)sw);
    }
    
    return 0;
}

/* Set rounding mode for fe* functions */
int __fesetround(int rnd)
{
    return fesetround(rnd);
}
