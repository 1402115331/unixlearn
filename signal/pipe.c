//#include<unistd.h>
#include<stdio.h>
#include<unistd.h>
int main(){
/******
注意调用管道的时候，pipe一定要在fork();之前，这是因为fork()的时候会复制当前线程的文件描述符，
当然也包括pipe的文件描述符。pipe会在task_struct里对应的位置设置好管道描述符标记，如果在fork
完成后再去pipe这个时候已经没有多大意义啦！
*****/
	int filedes[2];
	// pid_t pt=fork();
	char buf[80];
	pipe(filedes);

	 pid_t pt=fork();
	if(pt>0){
	puts("父进程\r\n");
	char father[5] ="1234";
	write(filedes[1],father,sizeof(father));
//	close(filed[1]);
//	close(filed[0]);
//	pause();
	}else if(pt==0){
	puts("子进程!!");
//	char buf[80];
	read(filedes[0],buf,sizeof(buf));
	printf("子进程:\r\n%s",buf);

//	close(filed[0]);
//	close(filed[1]);
	}
//	waitpid(pt,NULL,0);		

	return 0;
}
