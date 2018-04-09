;A comment
%define NL 10
%define DQ 34
%macro PROG 0
_main:
push rbp
mov rbp,rsp
clc
lea rdi,[rel file_name]
mov rsi,2+1000o+100o;O_WRONLY|O_TRUNC|O_CREAT
mov rdx,0666o
mov rax,0x2000005
syscall
jc _exit
mov rdi,rax
lea rsi,[rel str]
mov rdx,NL
mov rcx,DQ
lea r8,[rel str]
call _dprintf
mov rdi,rax
mov rax,0x2000006
leave
ret
%endmacro
section .data
file_name:db "Grace_kid.s", 0
str:db ";A comment%1$c%%define NL 10%1$c%%define DQ 34%1$c%%macro PROG 0%1$c_main:%1$cpush rbp%1$cmov rbp,rsp%1$cclc%1$clea rdi,[rel file_name]%1$cmov rsi,2+1000o+100o;O_WRONLY|O_TRUNC|O_CREAT%1$cmov rdx,0666o%1$cmov rax,0x2000005%1$csyscall%1$cjc _exit%1$cmov rdi,rax%1$clea rsi,[rel str]%1$cmov rdx,NL%1$cmov rcx,DQ%1$clea r8,[rel str]%1$ccall _dprintf%1$cmov rdi,rax%1$cmov rax,0x2000006%1$cleave%1$cret%1$c%%endmacro%1$csection .data%1$cfile_name:db %2$cGrace_kid.s%2$c, 0%1$cstr:db %2$c%s%2$c%1$csection .text%1$cglobal _main%1$cextern _dprintf%1$c_exit:%1$cmov rax,0x2000001%1$csyscall%1$cPROG%1$c"
section .text
global _main
extern _dprintf
_exit:
mov rax,0x2000001
syscall
PROG
