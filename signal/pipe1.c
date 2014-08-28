#include<stdio.h>
#include<unistd.h>
/***
可以实现父亲写入儿子读
也可以儿子写入父亲读
**/
int main(){
	int filedes[2];
	char buf[80];
	pid_t pid;
	pipe(filedes);
	pid=fork();
	if(pid>0){
	puts("father!!\r\n");
//	char s[]="hellow ";
//	write(filedes[0],s,sizeof(s));
	
	read(filedes[0],buf,sizeof(buf));
	printf(".....%s\r\n",buf);
	}else if(pid==0){
	puts("son!!\r\n");
//	read(filedes[1],buf,sizeof(buf));
//	printf(".....%s\r\n",buf);
	char wr[]="son write ,father read!";
	write(filedes[1],wr,sizeof(wr));
	}
//	wait4(pid,NULL,0,NULL);
	return 0;
}
