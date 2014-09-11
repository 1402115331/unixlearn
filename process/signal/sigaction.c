#include<unistd.h>
#include<signal.h>
#include<stdio.h>
void show(struct sigaction *act){

	switch(act->sa_flags){
	case SIG_DFL:puts("默认的信号处理\r\n");break;
	case SIG_IGN:puts("忽略的信号\r\n");break;
	default:printf("0x%x\n,act->sa_handler");
	}
}
int main(){
	struct sigaction act,oldact;
	act.sa_handler=show;
	act.sa_flags=SA_ONESHOT|SA_NOMASK;
	sigaction(SIGUSR1,&act,&oldact);
	for(int i=5;i<15;i++){
	printf("action的信号值%2d/n/r",i);
	sigaction(i,NULL,&oldact);
	}

}
