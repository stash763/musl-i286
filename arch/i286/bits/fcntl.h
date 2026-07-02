/* OS/2 file open flags */
#define O_RDONLY    0x0001
#define O_WRONLY    0x0002
#define O_RDWR      0x0003
#define O_ACCMODE   0x0003
#define O_APPEND    0x0100
#define O_CREAT     0x0010
#define O_TRUNC     0x0020
#define O_EXCL      0x0040
#define O_NOCTTY    0x0000  /* Not applicable on OS/2 */
#define O_NONBLOCK  0x0000  /* Not applicable on OS/2 */
#define O_SYNC      0x0200
#define O_DSYNC     0x0400
#define O_RSYNC     0x0800
#define O_LARGEFILE 0x0000  /* Not applicable on OS/2 */
#define O_CLOEXEC   0x0000  /* Not applicable on OS/2 */
#define O_DIRECTORY 0x0000  /* Not applicable on OS/2 */
#define O_NOFOLLOW  0x0000  /* Not applicable on OS/2 */

#define F_DUPFD     0
#define F_GETFD     1
#define F_SETFD     2
#define F_GETFL     3
#define F_SETFL     4
#define F_GETLK     5
#define F_SETLK     6
#define F_SETLKW    7

#define FD_CLOEXEC  1
