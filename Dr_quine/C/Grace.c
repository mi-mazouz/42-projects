/*
	A comment.
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define NL 10
#define DQ 34
#define MAIN(x) int main(){int fd=open("Grace_kid.c",O_WRONLY|O_CREAT|O_TRUNC,0644);if (fd == -1){return(0);}char*s="/*%1$c%2$cA comment.%1$c*/%1$c#include<stdio.h>%1$c#include<unistd.h>%1$c#include<fcntl.h>%1$c#define NL 10%1$c#define DQ 34%1$c#define MAIN(x) int main(){int fd=open(%3$cGrace_kid.c%3$c,O_WRONLY|O_CREAT|O_TRUNC,0644);if (fd == -1){return(0);}char*s=%3$c%s%3$c;dprintf(fd,s,NL,9,DQ,s);close(fd);}%1$cMAIN(x)%1$c";dprintf(fd,s,NL,9,DQ,s);close(fd);}
MAIN(x)
