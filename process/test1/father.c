#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
/***
实验证明：
1.父进程可以在wait4里获得子进程在用户空间的运行时间，在系统空间的运行时间，使用的分页数量，内存数量，发送的信息数量
等信息
2.如果父进程不主动调用wait4回收子进程的资源，那么子进程就成为僵死进程，具体的回收由内核负责，但是父进程可以获得一份回收报告
3.实验现象是：
父子进程同时运行，kill 子进程，如果父进程不调用wait4那么ps -el|grep childre 还可以看到子进程
如果调用了wait4就看不到子进程啦。

但是当kill父进程后init会负责清楚父进程以下所有节点的资源信息，即kill 父进程后ps -el|grep childre 和ps -el|grep father都看不到信息啦

**/

int main(int argc, char const *argv[])
{
	pid_t child ;//子进程的进程号
	int *status;//子进程的返回状态
	struct rusage *rus;//子进程被回收的资源
	if(!(child=fork())){
		char *argu[]={"./children",NULL};
		execve("./children",argu,NULL);

	}else{

		// wait4(child,status,WUNTRACED,rus);
        // printf("The son's pid:%d, status:%d, 回收的页面数量is:%d\n", child, WIFEXITED(status),rus->ru_minflt);
     	while(1){
     		printf("%s,%d\n","父进程",getpid());
     	}
	}
//	exit(0);
	return 0;
}