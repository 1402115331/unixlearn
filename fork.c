#include<stdio.h>
#include<unistd.h>

int main(int argc,char ** argv,char ** env){

	pid_t p=fork();
	
	if(p<0){
	puts("程序创建出错啦！！！\r\n");
	}else if(p==0){
	puts("我是子进程，我比vfork独立，父进程可以不去睡眠！！！\r\n");
	}else{
	puts("i am father ,my son dependent ,I am happy!!!\r\n");
	
	}
	return 0;
}
