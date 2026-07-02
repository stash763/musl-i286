/* OS/2 NE executable entry point */
/* ..start: is the entry point for OS/2 NE executables */
/* DS = DGROUP on entry, stack is set up by OS */

__asm__(
".global _start\n"
"_start:\n"
"  ; Save entry parameters\n"
"  push bp\n"
"  mov bp, sp\n"
"  \n"
"  ; Set up data segment (should already be DGROUP from OS/2)\n"
"  push ds\n"
"  \n"
"  ; Call _start_c with argc, argv, envp\n"
"  ; For initial port: argc=0, argv=NULL, envp=NULL\n"
"  push 0      ; envp\n"
"  push 0      ; argv\n"
"  push 0      ; argc\n"
"  call _start_c\n"
"  \n"
"  ; If _start_c returns, exit\n"
"  push 0     ; return code\n"
"  push 0     ; action code 0 = terminate\n"
"  call far DOSEXIT\n"
);
