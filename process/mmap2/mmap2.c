#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdio.h>
/****
可以用这个实验完成打开文件
实验说明:打开的内容是不知道类型的，具体什么类型，需要自己确定。。。
****/
int main(){
	int fd;
	void *start;
	struct stat sb;
	fd=open("/etc/passwd",O_RDONLY);//取得文件的索引号
	fstat(fd,&sb);//取得文件的大小
	start=mmap(NULL,sb.st_size,PROT_READ,MAP_PRIVATE,fd,0);
	if(start==MAP_FAILED){
	printf("文件映射失败!/n");
	return;
	}
printf("%s",(char *)start);
//munma(start,sb.st_size);
close(fd);

return 0;
}
