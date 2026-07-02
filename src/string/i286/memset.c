/* C implementation of memset for 80286 */

#include <string.h>
#include <stdint.h>

void *memset(void *s, int c, size_t n)
{
    unsigned char *p = s;
    unsigned char val = (unsigned char)c;
    
    /* Set word-by-word for efficiency */
    unsigned short word = (val << 8) | val;
    
    while (n >= 2) {
        *(unsigned short *)p = word;
        p += 2;
        n -= 2;
    }
    
    /* Set remaining byte */
    if (n) {
        *p = val;
    }
    
    return s;
}
