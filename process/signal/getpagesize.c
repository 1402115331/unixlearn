#include<stdio.h>
#include<unistd.h>
int main(){
	
	printf("页面大小:%dM\r\n",getpagesize()/1024);

	return 0;
}
