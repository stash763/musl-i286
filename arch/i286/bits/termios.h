/* OS/2 terminal settings */
/* Minimal implementation for initial port */

#define NCCS 32

struct termios {
    unsigned long c_iflag;
    unsigned long c_oflag;
    unsigned long c_cflag;
    unsigned long c_lflag;
    unsigned char c_line;
    unsigned char c_cc[NCCS];
    unsigned long __c_ispeed;
    unsigned long __c_ospeed;
};

#define B0        0
#define B50       1
#define B75       2
#define B110      3
#define B134      4
#define B150      5
#define B200      6
#define B300      7
#define B600      8
#define B1200     9
#define B1800     10
#define B2400     11
#define B4800     12
#define B9600     13
#define B19200    14
#define B38400    15
#define B57600    16
#define B115200   17
#define B230400   18
#define B460800   19
#define B576000   20
#define B921600   21
#define B1000000  22
#define B1152000  23
#define B1500000  24
#define B2000000  25
#define B2500000  26
#define B3000000  27
#define B3500000  28
#define B4000000  29

#define CSIZE     0000060
#define CS5       0000000
#define CS6       0000020
#define CS7       0000040
#define CS8       0000060

#define CSTOPB    0000100
#define CREAD     0000200
#define PARENB    0000400
#define PARODD    0001000
#define HUPCL     0002000
#define CLOCAL    0004000

#define CBAUD     0010017
#define CBAUDEX   0010000

#define CIBAUD    002003600000
#define CMSPAR    010000000000

#define IBSIZE    0030000

#define ISIG      0000001
#define ICANON    0000002
#define XCASE     0000004
#define ECHO      0000010
#define ECHOE     0000020
#define ECHOK     0000040
#define ECHONL    0000100
#define NOFLSH    0000200
#define TOSTOP    0000400
#define ECHOCTL   0001000
#define ECHOPRT   0002000
#define ECHOKE    0004000
#define FLUSHO    0010000
#define PENDIN    0040000
#define IEXTEN    0100000
#define EXTPROC   0200000

#define IGNBRK    0000001
#define BRKINT    0000002
#define IGNPAR    0000004
#define PARMRK    0000010
#define INPCK     0000020
#define ISTRIP    0000040
#define INLCR     0000100
#define IGNCR     0000200
#define ICRNL     0000400
#define IUCLC     0001000
#define IXON      0002000
#define IXOFF     0004000
#define IXANY     0010000
#define IMAXBEL   0020000
#define IUTF8     0040000

#define OPOST     0000001
#define OLCUC     0000002
#define ONLCR     0000004
#define OCRNL     0000010
#define ONOCR     0000020
#define ONLRET    0000040
#define OFILL     0000100
#define OFDEL     0000200

#define NLDLY     0000400
#define CRDLY     0003000
#define TABDLY    0014000
#define BSDLY     0020000
#define VTDLY     0040000
#define FFDLY     0100000

#define NL0       0000000
#define NL1       0000400
#define CR0       0000000
#define CR1       0001000
#define CR2       0002000
#define CR3       0003000
#define TAB0      0000000
#define TAB1      0004000
#define TAB2      0010000
#define TAB3      0014000
#define BS0       0000000
#define BS1       0020000
#define FF0       0000000
#define FF1       0100000
#define VT0       0000000
#define VT1       0040000

#define VINTR     0
#define VQUIT     1
#define VERASE    2
#define VKILL     3
#define VEOF      4
#define VTIME     5
#define VMIN      6
#define VSWTC     7
#define VSTART    8
#define VSTOP     9
#define VSUSP     10
#define VEOL      11
#define VREPRINT  12
#define VDISCARD  13
#define VWERASE   14
#define VLNEXT    15
#define VEOL2     16

#define TCSANOW   0
#define TCSADRAIN 1
#define TCSAFLUSH 2

#define TCIFLUSH  0
#define TCOFLUSH  1
#define TCIOFLUSH 2

#define TCOOFF    0
#define TCOON     1
#define TCIOFF    2
#define TCION     3

#define TCGETS    0x5401
#define TCSETS    0x5402
#define TCSETSW   0x5403
#define TCSETSF   0x5404
#define TCGETA    0x5405
#define TCSETA    0x5406
#define TCSETAW   0x5407
#define TCSETAF   0x5408
#define TCSBRK    0x5409
#define TCXONC    0x540A
#define TCFLSH    0x540B
#define TIOCEXCL  0x540C
#define TIOCNXCL  0x540D
#define TIOCSCTTY 0x540E
#define TIOCGPGRP 0x540F
#define TIOCSPGRP 0x5410
#define TIOCOUTQ  0x5411
#define TIOCSTI   0x5412
#define TIOCGWINSZ 0x5413
#define TIOCSWINSZ 0x5414
#define TIOCMGET  0x5415
#define TIOCMBIS  0x5416
#define TIOCMBIC  0x5417
#define TIOCMSET  0x5418
#define TIOCGSOFTCAR 0x5419
#define TIOCSSOFTCAR 0x541A
#define FIONREAD  0x541B
#define TIOCINQ   FIONREAD
#define TIOCLINUX 0x541C
#define TIOCCONS  0x541D
#define TIOCGSERIAL 0x541E
#define TIOCSSERIAL 0x541F
#define TIOCPKT   0x5420
#define FIONBIO   0x5421
#define TIOCNOTTY 0x5422
#define TIOCSETD  0x5423
#define TIOCGETD  0x5424
#define TIOCSBRK  0x5427
#define TIOCCBRK  0x5428
#define TIOCGSID  0x5429
#define TCGETS2   0x542A
#define TCSETS2   0x542B
#define TCSETSW2  0x542C
#define TCSETSF2  0x542D
#define TIOCGRS485 0x542E
#define TIOCSRS485 0x542F
#define TIOCGPTN  0x5430
#define TIOCSPTLCK 0x5431
#define TIOCGDEV  0x5432
#define TCGETX    0x5432
#define TCSETX    0x5433
#define TCSETXF   0x5434
#define TCSETXW   0x5435
#define TIOCSIG   0x5436
#define TIOCVHANGUP 0x5437
#define TIOCGPKT  0x5438
#define TIOCGPTLCK 0x5439
#define TIOCGEXCL 0x5440
#define TIOCGICOUNT 0x545D

#define ECHOCTL   ECHOCTL
#define ECHOKE    ECHOKE

#define EXTA      B19200
#define EXTB      B38400

#define CBAUD_EXTA B19200
#define CBAUD_EXTB B38400

#define IUCLC     0001000
#define IXANY     0010000
#define IMAXBEL   0020000
#define IUTF8     0040000
