#include<stdio.h>
/**
  gcc -DINT="2+3" macros.c -o macros
  gcc -DSTRING="\"Hello World"\" macros.c -o macros

  gcc -DINT macros.c -o macros
  gcc -DINT="" macros.c -o macros
  gcc -DTEST="" macros.c -o macros
  gcc -DINT="0" macros.c -o macros

宏定义可以定义数字和字符串，但是定义数组使用双引号括起来时候表示计算内容，也可以直接定义数字不括起来
INT宏即是数字宏，如果不赋值，默认值为1，如果给一个"" 是编译不通过的，宏变量赋值为""基本上用于ifdef判断的时候


***/
int
main(){
	#ifdef TEST
	printf("测试宏定义\n");
	#endif
	printf("Running...\n");
	#ifdef STRING
	printf("----str:%s\n",STRING);
	#endif
	#ifdef INT
	printf("---int%d\n",INT);
	#endif

	
	return 0;

}
