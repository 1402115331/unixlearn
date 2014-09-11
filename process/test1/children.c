#include <stdio.h>
int main(int argc, char const *argv[])
{
	int i;
	for( i=0;i<400;i++){
	//while(1){
		printf("%s，%d\n","Hello,你好我是子进程 pid",getpid());
	}
	//}
exit(0);
	return 0;
}