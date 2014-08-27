#include<stdio.h>
#include<unistd.h>

int main(int argc,char ** argv){

	pid_t p =vfork();
	if(p<0){
	puts("进程常见失败啦\r\n");
	}else if(p==0){
	puts("我的子进程，我结束之前父进程不会结束!!!\r\n");
	exit(1);
	}else{
	puts("我是父亲 I love my son ,但他寄生！！\r\n");
	exit(1);
	}
	return 0;
}
