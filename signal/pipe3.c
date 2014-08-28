#include<stdio.h>
#include<unistd.h>
/****
管道时候，你可以关闭或者不关闭，但是如果不关闭，肯定是漏洞，因为这样别的进程也可以写啦！
也就是说如果A中不关闭，A不主动放弃,那么B是不能写的。
**/
int main(){

	int pip[2];

	pipe(pip);
	
	pid_t b,c;
	char buf[]="我在A里写入的\r\n";
	write(pip[1],buf,sizeof(buf));	

	if(!(b=fork())){
	//这里负责写
	close(1);

	dup2(pip[1],1);

	close(pip[1]);
	char buf[]="管道的写段写数据。。。";
	write(1,buf,sizeof(buf));
	
	
	}

//	close(pip[1]);

	if(!(c=fork())){
	//这一端负责读
	close(0);
	dup2(pip[0],0);
	char buf[1023];
	close(pip[0]);
	close(pip[1]);
	read(0,buf,sizeof(buf));
	printf("读文件的内容:\r\n%s",buf);
	
	
	

	}
//close(pip[0]);



}
