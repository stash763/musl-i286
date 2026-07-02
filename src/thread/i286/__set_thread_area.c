/* Set thread area - stub for initial port */
/* No GDT manipulation on OS/2 1.x */

#define _GNU_SOURCE
#include <errno.h>
#include <unistd.h>

struct _user_desc {
    unsigned int entry_number;
    unsigned long base_addr;
    unsigned int limit;
    unsigned int seg_32bit : 1;
    unsigned int contents : 2;
    unsigned int read_exec_only : 1;
    unsigned int limit_in_pages : 1;
    unsigned int seg_not_present : 1;
    unsigned int useable : 1;
    unsigned int reserved : 25;
};

int __set_thread_area(struct _user_desc *u_info)
{
    (void)u_info;
    /* No thread area for initial port */
    return 0;
}
