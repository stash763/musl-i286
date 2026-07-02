/* OS/2 syscall implementation via C wrappers */
/* Replaces Linux int $128 with OS/2 Dos* API calls */

#define __SYSCALL_LL_E(x) \
    ((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
    ((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) __SYSCALL_LL_E((x))

/* External C wrappers for OS/2 API calls */
extern long __os2_syscall0(long n);
extern long __os2_syscall1(long n, long a1);
extern long __os2_syscall2(long n, long a1, long a2);
extern long __os2_syscall3(long n, long a1, long a2, long a3);
extern long __os2_syscall4(long n, long a1, long a2, long a3, long a4);
extern long __os2_syscall5(long n, long a1, long a2, long a3, long a4, long a5);
extern long __os2_syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6);

static inline long __syscall0(long n)
{
    return __os2_syscall0(n);
}

static inline long __syscall1(long n, long a1)
{
    return __os2_syscall1(n, a1);
}

static inline long __syscall2(long n, long a1, long a2)
{
    return __os2_syscall2(n, a1, a2);
}

static inline long __syscall3(long n, long a1, long a2, long a3)
{
    return __os2_syscall3(n, a1, a2, a3);
}

static inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
    return __os2_syscall4(n, a1, a2, a3, a4);
}

static inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
    return __os2_syscall5(n, a1, a2, a3, a4, a5);
}

static inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
    return __os2_syscall6(n, a1, a2, a3, a4, a5, a6);
}

#define __syscall_cp(...) __syscall(__VA_ARGS__)
#define __syscall_cp_sysnr(n, ...) __syscall(n, __VA_ARGS__)
