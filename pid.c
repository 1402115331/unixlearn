#include <stdio.h>
#include <unistd.h>
int main(int arg,char **argv[]){

	printf("当前进程的pid是%d---\r\n",getpid());
	char *args[]={"/bin/echo","hello","world!!",NULL};
	pid_t p=fork();
	if(p<0){
	puts("进程创建失败\r\n");
	}else if(p==0){

	printf("我是子进程我的id是%d,我的父进程id是%d\r\n",getpid(),getppid());
	execve("/bin/echo",args,NULL);
	printf("我单独执行回来了pid:%d,ppid:%d",getpid(),getppid());

	}else{

	printf("我是父进程我的id是%d,我的父进程id是%d\r\n",getpid(),getppid());
/***
不调用wait4的时候发现，父进程会先结束，所以子进程打印的时候，说我的父进程id是1，就是因为当时父进程已经丢失啦。
当用wait4的时候就可以发现，子进程不会另外开始一行输出信息，就是因为，此时父进程还在，并且子进程会说我的父进程id的时候，说的就是创建他的id
***/
	wait4(p,NULL,0,NULL);
	}	
	return 0;
}
