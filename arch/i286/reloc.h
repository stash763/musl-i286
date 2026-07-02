/* Relocation types for OS/2 NE format */
/* Initial port: no dynamic linking, so minimal definitions */

#define LDSO_ARCH "i286"

/* Relocation types - stubs for initial port */
#define REL_SYMBOLIC 0
#define REL_OFFSET   0
#define REL_GOT      0
#define REL_PLT      0
#define REL_RELATIVE 0
#define REL_DTPMOD   0
#define REL_DTPOFF   0
#define REL_TPMOD    0
#define REL_TPOFF    0

/* No dynamic linking in initial port */
#define NO_SHARED_LIBS 1
