#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main(){
int i=5;
char file_check[64];sprintf(file_check, "Sully_%d.c", i);int fd1;if(i<=0){return(0);}if((fd1=open(file_check,O_RDONLY))>-1){i--;}char file[64];char exec[64];char cmd[1000];char*str="#include<stdio.h>%1$c#include<unistd.h>%1$c#include<stdlib.h>%1$c#include<fcntl.h>%1$c#include<string.h>%1$cint main(){%1$cint i=%2$d;%1$cchar file_check[64];sprintf(file_check, %3$cSully_%%d.c%3$c, i);int fd1;if(i<=0){return(0);}if((fd1=open(file_check,O_RDONLY))>-1){i--;}char file[64];char exec[64];char cmd[1000];char*str=%3$c%4$s%3$c;sprintf(file, %3$cSully_%%d.c%3$c, i);sprintf(exec, %3$c./Sully_%%d%3$c, i);sprintf(cmd, %3$cclang -Wall -Wextra -Werror ./Sully_%%1$d.c -o Sully_%%1$d%3$c, i);int fd=open(file,O_WRONLY|O_CREAT|O_TRUNC,0644);if (fd == -1){return(0);}dprintf(fd, str, 10, i, 34, str);system(cmd);system(exec);}%1$c";sprintf(file, "Sully_%d.c", i);sprintf(exec, "./Sully_%d", i);sprintf(cmd, "clang -Wall -Wextra -Werror ./Sully_%1$d.c -o Sully_%1$d", i);int fd=open(file,O_WRONLY|O_CREAT|O_TRUNC,0644);if (fd == -1){return(0);}dprintf(fd, str, 10, i, 34, str);system(cmd);system(exec);}
