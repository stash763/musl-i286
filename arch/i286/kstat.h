/* OS/2 kernel stat structure */
/* Maps to DosFindFirst/DosQFileInfo file information */

struct kstat {
    unsigned long st_dev;
    unsigned long st_ino;
    unsigned short st_mode;
    unsigned short st_nlink;
    unsigned short st_uid;
    unsigned short st_gid;
    unsigned long st_rdev;
    long st_size;
    unsigned long st_blksize;
    long st_blocks;
    long st_atime;
    long st_mtime;
    long st_ctime;
};
