#include<unistd.h>
#include<stdio.h>

void readfile(int fd){
	char buf[1024];
	read(fd,buf,sizeof(buf));
	printf("文件内容:\r\n%s",buf);
}
void wirtefile(int fd){
	char buf[]="This is the content I write!";
	write(fd,buf,sizeof(buf));
}
int main(){
	pid_t pb,pc;
	char *arg1[]={"/bin/wc",NULL};
	char *arg2[]={"/usr/bin/ls","-l",NULL};
	if(!(pb=fork())){
	
	execve("/usr/bin/ls",arg2,NULL);
	wirtefile(1);
	readfile(0);
	}


	return 0;
}

