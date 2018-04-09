;You're outside of the main function.
section .data
str:db";You're outside of the main function.%1$csection .data%1$cstr:db%2$c%s%2$c%1$c.len:equ $-str%1$csection .text%1$cglobal start%1$cglobal _main%1$cextern _printf%1$cstart:%1$ccall _main%1$cret%1$c_main:%1$c;You're inside of the main function.%1$ccall _toto%1$cpush rbp%1$cmov rbp,rsp%1$clea rdi,[rel str]%1$cmov rsi,10%1$cmov rdx,34%1$clea rcx,[rel str]%1$ccall _printf%1$cleave%1$cret%1$c_toto:%1$cret%1$c"
.len:equ $-str
section .text
global start
global _main
extern _printf
start:
call _main
ret
_main:
;You're inside of the main function.
call _toto
push rbp
mov rbp,rsp
lea rdi,[rel str]
mov rsi,10
mov rdx,34
lea rcx,[rel str]
call _printf
leave
ret
_toto:
ret
