/* C implementation of memmove for 80286 */
/* Handles overlapping memory regions */

#include <string.h>
#include <stdint.h>

void *memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;
    
    if (d == s) return dest;
    
    /* If destination is after source, copy backwards */
    if (d > s && d < s + n) {
        d += n;
        s += n;
        while (n--) {
            *--d = *--s;
        }
    } else {
        /* Otherwise copy forwards */
        while (n >= 2) {
            *(unsigned short *)d = *(const unsigned short *)s;
            d += 2;
            s += 2;
            n -= 2;
        }
        if (n) {
            *d = *s;
        }
    }
    
    return dest;
}
