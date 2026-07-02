/* OS/2 memory mapping definitions */
#define PROT_NONE   0x0
#define PROT_READ   0x1
#define PROT_WRITE  0x2
#define PROT_EXEC   0x4

#define MAP_SHARED  0x0001
#define MAP_PRIVATE 0x0002
#define MAP_TYPE    0x000f
#define MAP_FIXED   0x0010
#define MAP_ANON    0x0020
#define MAP_ANONYMOUS MAP_ANON
#define MAP_FAILED  ((void *)-1)

#define MS_ASYNC    0x0001
#define MS_SYNC     0x0004
#define MS_INVALIDATE 0x0002

#define MCL_CURRENT 0x0001
#define MCL_FUTURE  0x0002

#define MADV_NORMAL     0
#define MADV_RANDOM     1
#define MADV_SEQUENTIAL 2
#define MADV_WILLNEED   3
#define MADV_DONTNEED   4
#define MADV_REMOVE     9
#define MADV_DONTFORK   10
#define MADV_DOFORK     11
#define MADV_MERGEABLE  12
#define MADV_UNMERGEABLE 13
#define MADV_HWPOISON   100

#define POSIX_MADV_NORMAL 0
#define POSIX_MADV_RANDOM 1
#define POSIX_MADV_SEQUENTIAL 2
#define POSIX_MADV_WILLNEED 3
#define POSIX_MADV_DONTNEED 4
