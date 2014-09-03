#include <stdio.h>

int main(int argc, char const *argv[])
{
	struct my
	{
		char a;
		int i;
		
	}__attribute__((packed));
	struct you
	{
		char a;
		int i;
		
	};
	/**
	这个实验证明，__attribute__((packed))语法的意思就是取消内存对齐
	**/
	printf("int的长度%d,  char的长度%d   my的长度%d \n  you的长度为%d",sizeof(int),sizeof(char),sizeof( struct my) ,sizeof(struct you));
	return 0;
}
