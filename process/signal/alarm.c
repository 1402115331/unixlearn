#include<unistd.h>
#include<signal.h>
#include<stdio.h>
void handler(){
	puts("调用信号alarm!!!\r\n");
}
int main(int argc,char **argv,char **env){
	
	signal(SIGALRM,handler);
	puts("5秒后开始调用定时信号。。。\r\n");
	alarm(5);
	pause();
	/***
	信号调用应该和pause一起调用，就是虽然设置信号成功了，但是如果程序已经返回，那么信号还是不会别调用。信号应该是用来唤醒进程的。
也就是说，我们可以让进程pause，也可以让进程运行。。。
	***/
	puts("信号处理完成!\r\n");
	return 0;
}
