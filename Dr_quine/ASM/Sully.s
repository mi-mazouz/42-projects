section .data
file_name:db"Sully_%d.s",0
file_name_exec:db"./Sully_%d",0
str_cmd:db"nasm -f macho64 Sully_%1$d.s -o Sully_%1$d && gcc -Wall -Werror -Wextra Sully_%1$d -o Sully_%1$d",0
str:db"section .data%1$cfile_name:db%2$cSully_%%d.s%2$c,0%1$cfile_name_exec:db%2$c./Sully_%%d%2$c,0%1$cstr_cmd:db%2$cnasm -f macho64 Sully_%%1$d.s -o Sully_%%1$d && gcc -Wall -Werror -Wextra Sully_%%1$d -o Sully_%%1$d%2$c,0%1$cstr:db%2$c%4$s%2$c,0%1$ccount:dq %3$d%1$csection .bss%1$cfile: resb 64%1$cexec: resb 64%1$cfile_name_check: resb 64%1$ccmd: resb 1000%1$csection .text%1$cglobal _main%1$cextern _sprintf%1$cextern _dprintf%1$cextern _system%1$c_main:%1$cpush rbp%1$cmov rbp,rsp%1$cmov r15, [rel count]%1$ccmp r15,0%1$cjle _exit%1$clea rdi, [rel file_name_check]%1$clea rsi, [rel file_name]%1$cmov rdx, r15%1$ccall _sprintf%1$clea rdi,[rel file_name_check]%1$cmov rsi,0x0000%1$cmov rax,0x2000005%1$csyscall%1$cjnc _decrem%1$cjmp _algo%1$cleave%1$cret%1$c_exit:%1$cmov rax,0x2000001%1$csyscall%1$c_decrem:%1$cdec r15%1$cjmp _algo%1$cleave%1$cret%1$c_algo:%1$clea rdi, [rel file]%1$clea rsi, [rel file_name]%1$cmov rdx, r15%1$ccall _sprintf%1$clea rdi, [rel exec]%1$clea rsi, [rel file_name_exec]%1$cmov rdx, r15%1$ccall _sprintf%1$clea rdi, [rel cmd]%1$clea rsi, [rel str_cmd]%1$cmov rdx, r15%1$ccall _sprintf%1$cclc%1$clea rdi,[rel file]%1$cmov rsi,2+1000o+100o%1$cmov rdx,0666o%1$cmov rax,0x2000005%1$csyscall%1$cjc _exit%1$cmov rdi, rax%1$clea rsi, [rel str]%1$cmov rdx,10%1$cmov rcx,34%1$cmov r8, r15%1$clea r9,[rel str]%1$ccall _dprintf%1$clea rdi, [rel cmd]%1$ccall _system%1$clea rdi, [rel exec]%1$ccall _system%1$cleave%1$cret%1$c",0
count:dq 5
section .bss
file: resb 64
exec: resb 64
file_name_check: resb 64
cmd: resb 1000
section .text
global _main
extern _sprintf
extern _dprintf
extern _system
_main:
push rbp
mov rbp,rsp
mov r15, [rel count]
cmp r15,0
jle _exit
lea rdi, [rel file_name_check]
lea rsi, [rel file_name]
mov rdx, r15
call _sprintf
lea rdi,[rel file_name_check]
mov rsi,0x0000
mov rax,0x2000005
syscall
jnc _decrem
jmp _algo
leave
ret
_exit:
mov rax,0x2000001
syscall
_decrem:
dec r15
jmp _algo
leave
ret
_algo:
lea rdi, [rel file]
lea rsi, [rel file_name]
mov rdx, r15
call _sprintf
lea rdi, [rel exec]
lea rsi, [rel file_name_exec]
mov rdx, r15
call _sprintf
lea rdi, [rel cmd]
lea rsi, [rel str_cmd]
mov rdx, r15
call _sprintf
clc
lea rdi,[rel file]
mov rsi,2+1000o+100o
mov rdx,0666o
mov rax,0x2000005
syscall
jc _exit
mov rdi, rax
lea rsi, [rel str]
mov rdx,10
mov rcx,34
mov r8, r15
lea r9,[rel str]
call _dprintf
lea rdi, [rel cmd]
call _system
lea rdi, [rel exec]
call _system
leave
ret
