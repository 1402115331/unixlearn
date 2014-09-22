#include <stdio.h>
/*****
这个程序在默认的gun编辑下是不通过的，gum对c做了很多的拓展，其中的asm是关键字

而在ansi/iso下是正常的
***/
int main(){
	const char asm[]="12345";
	printf("%s\n",asm);
	return 0;
}
