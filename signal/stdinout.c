#include<stdio.h>

int main(){

int in=0,ou=1;

/*****
无论想想标准输入写内容还是向标准输出写内容，最终的结果，都会定位到标准输出上来
******/
char info[]="This is the content!!\r\n";
write(in,info,sizeof(info));
write(ou,info,sizeof(info));

/***
如果直接读标准输入内容是读不出来的。
***/
char rd[1024];

read(ou,rd,sizeof(rd));
printf("ou 1:%s\r\n",rd);

read(in,rd,sizeof(rd));
printf("in 0 :%s",rd);



return 0;
}
