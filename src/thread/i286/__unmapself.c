/* Unmap self - stub for initial port */
/* No mmap/munmap for initial port */

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/mman.h>

void __unmapself(void *base, size_t size)
{
    (void)base;
    (void)size;
    /* No unmap for initial port */
}
