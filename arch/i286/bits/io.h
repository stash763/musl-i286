/* I/O port access for OS/2 */
/* Not fully implemented - stub definitions */

#define __outb(value, port) \
    __asm__ __volatile__("outb %b0, %w1" : : "a"(value), "Nd"(port))

#define __inb(port) \
    ({ unsigned char _v; \
       __asm__ __volatile__("inb %w1, %b0" : "=a"(_v) : "Nd"(port)); \
       _v; })

#define __outw(value, port) \
    __asm__ __volatile__("outw %w0, %w1" : : "a"(value), "Nd"(port))

#define __inw(port) \
    ({ unsigned short _v; \
       __asm__ __volatile__("inw %w1, %w0" : "=a"(_v) : "Nd"(port)); \
       _v; })

#define __outl(value, port) \
    __asm__ __volatile__("outl %0, %w1" : : "a"(value), "Nd"(port))

#define __inl(port) \
    ({ unsigned int _v; \
       __asm__ __volatile__("inl %w1, %0" : "=a"(_v) : "Nd"(port)); \
       _v; })
