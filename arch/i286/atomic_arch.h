/* 80286 atomic operations - C-only implementation */
/* No inline assembly for atomic operations */
/* Initial port: single-threaded, simple non-atomic implementations */

#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
    int old = *p;
    if (old == t) *p = s;
    return old;
}

#define a_swap a_swap
static inline int a_swap(volatile int *p, int v)
{
    int old = *p;
    *p = v;
    return old;
}

#define a_fetch_add a_fetch_add
static inline int a_fetch_add(volatile int *p, int v)
{
    int old = *p;
    *p = old + v;
    return old;
}

#define a_fetch_and a_fetch_and
static inline int a_fetch_and(volatile int *p, int v)
{
    int old = *p;
    *p = old & v;
    return old;
}

#define a_fetch_or a_fetch_or
static inline int a_fetch_or(volatile int *p, int v)
{
    int old = *p;
    *p = old | v;
    return old;
}

#define a_and a_and
static inline void a_and(volatile int *p, int v)
{
    a_fetch_and(p, v);
}

#define a_or a_or
static inline void a_or(volatile int *p, int v)
{
    a_fetch_or(p, v);
}

#define a_inc a_inc
static inline void a_inc(volatile int *p)
{
    a_fetch_add(p, 1);
}

#define a_dec a_dec
static inline void a_dec(volatile int *p)
{
    a_fetch_add(p, -1);
}

#define a_store a_store
static inline void a_store(volatile int *p, int v)
{
    *p = v;
}

#define a_barrier a_barrier
static inline void a_barrier()
{
    volatile int tmp = 0;
    a_cas(&tmp, 0, 0);
}

#define a_spin a_barrier

#define a_crash a_crash
static inline void a_crash()
{
    *(volatile char *)0 = 0;
}

#define a_ctz_32 a_ctz_32
static inline int a_ctz_32(unsigned int x)
{
    static const char debruijn32[32] = {
        0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13,
        31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14
    };
    return debruijn32[(x & -x) * 0x076be629 >> 27];
}

#define a_clz_32 a_clz_32
static inline int a_clz_32(unsigned int x)
{
    x >>= 1;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x++;
    return 31 - a_ctz_32(x);
}

#define a_ctz_64 a_ctz_64
static inline int a_ctz_64(unsigned long long x)
{
    unsigned int y = (unsigned int)x;
    if (!y) {
        y = (unsigned int)(x >> 32);
        return 32 + a_ctz_32(y);
    }
    return a_ctz_32(y);
}

#define a_clz_64 a_clz_64
static inline int a_clz_64(unsigned long long x)
{
    unsigned int y = (unsigned int)(x >> 32);
    if (y)
        return a_clz_32(y);
    y = (unsigned int)x;
    return a_clz_32(y) + 32;
}

static inline int a_ctz_l(unsigned long x)
{
    return (sizeof(long) < 8) ? a_ctz_32(x) : a_ctz_64(x);
}

#define a_and_64 a_and_64
static inline void a_and_64(volatile unsigned long long *p, unsigned long long v)
{
    union { unsigned long long v; unsigned int r[2]; } u = { v };
    if (u.r[0] + 1) a_and((int *)p, u.r[0]);
    if (u.r[1] + 1) a_and((int *)p + 1, u.r[1]);
}

#define a_or_64 a_or_64
static inline void a_or_64(volatile unsigned long long *p, unsigned long long v)
{
    union { unsigned long long v; unsigned int r[2]; } u = { v };
    if (u.r[0]) a_or((int *)p, u.r[0]);
    if (u.r[1]) a_or((int *)p + 1, u.r[1]);
}

#define a_or_l a_or_l
static inline void a_or_l(volatile void *p, long v)
{
    if (sizeof(long) == sizeof(int)) a_or(p, v);
    else a_or_64(p, v);
}
