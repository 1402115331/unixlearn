#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv,char ** env){
	FILE *p;	
	FILE *f=fopen("~/c/a.txt","rw");
	if(f==NULL){
	perror("fopen还挺现金的嘛");
	}else{
	puts("文件打开成功!");
	}
	char *ch;
//	fgets(ch,10,p);
	perror("fgets");
	return 0;
}
