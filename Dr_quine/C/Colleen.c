#include<stdio.h>
/*
	You're outside of any functions.
*/
void to_call(){return;}int main(void){
/*
	You're in the main function.
*/
to_call();char*s="#include<stdio.h>%1$c/*%1$c%2$cYou're outside of any functions.%1$c*/%1$cvoid to_call(){return;}int main(void){%1$c/*%1$c%2$cYou're in the main function.%1$c*/%1$cto_call();char*s=%3$c%s%3$c;printf(s, 10, 9, 34, s);}%1$c";printf(s, 10, 9, 34, s);}
