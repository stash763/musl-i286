/* C implementation of memcpy for 80286 */
/* Replaces i386 assembly version */

#include <string.h>
#include <stdint.h>

void *memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;
    
    /* Copy word-by-word for aligned data */
    while (n >= 2) {
        *(unsigned short *)d = *(const unsigned short *)s;
        d += 2;
        s += 2;
        n -= 2;
    }
    
    /* Copy remaining byte */
    if (n) {
        *d = *s;
    }
    
    return dest;
}

/* Forward copy for overlapping regions */
void *__memcpy_fwd(void *dest, const void *src, size_t n)
{
    return memcpy(dest, src, n);
}
