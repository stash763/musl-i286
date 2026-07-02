/* setjmp/longjmp for 80286 */
/* Save/restore: BX, SI, DI, BP, DS, ES, IP */
/* Return value in AX */

typedef struct __jmp_buf_tag {
    unsigned int __bx, __si, __di, __bp;
    unsigned int __ds, __es;
    unsigned int __ip;
    unsigned int __ret;
} jmp_buf[1];

typedef jmp_buf sigjmp_buf;

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

typedef struct {
    jmp_buf __jb;
    unsigned long __fl;
} sigjmp_buf_t;

#endif
