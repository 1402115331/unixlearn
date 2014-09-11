#include<stdio.h>

int main(){
/**
popen会调用fork产生子进程，然后从子进程中执行bash命令,把结果缓存为文件，直接返回文件指针，
所以这种包装在形式上使得对内容的处理如同对文件的处理一样。
也正好和fopen相对应
**/
	FILE *f;
	char buf[1024];
	f=popen("cat /etc/passwd","r");
	fgets(buf,sizeof(buf),f);
	printf("内容：\r\n%s",buf);
	pclose(f);
	return 0;
}
