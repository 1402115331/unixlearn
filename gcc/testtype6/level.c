#include<stdio.h>
/*******
测试不同优化级别下代码的差异
注意观察的是user 因为sys real的时间是包含进程调度的时间的，这里包含的有别的进程执行的时间。。



gcc -Wall -O0 level.c
time ./a.out 
sum = 4e+43
real	0m38.143s
user	0m33.732s
sys	0m0.052s
file的大小是7317
好慢啊，还以为死机了那！！
---------------------
gcc -Wall -O1 level.c 
time ./a.out
sum = 4e+43
real	0m18.556s
user	0m16.508s
sys	0m0.020s
file大小是7325
明显比第一个快了很多，实际实际足足减少了10s
文件大小也没有变大多少
----------------------
gcc -Wall -O2 level.c 
time ./a.out
sum = 4e+43
real	0m5.467s
user	0m4.784s
sys	0m0.012s
file大小是7325
文件大小没变，速度也快了点，不是很明显
----------------------
gcc -Wall -O3 level.c
time ./a.out
sum = 4e+43
real	0m5.286s
user	0m4.668s
sys	0m0.004s
file大小是7325
文件大小没变，速度也快了，也是不明显，优化到一定程序
很难再有本质突破啦
-------------------------
gcc -Wall -O3 -funroll-loops  level.c 
time ./a.out
sum = 4e+43
real	0m5.709s
user	0m5.016s
sys	0m0.012s
文件大小没变，速度好像还变慢啦，如果不能透彻分析代码
类型也不能保证自定义的优化能快多少

****/
double
powern(double d,unsigned n){
	double x=1.0;
	unsigned j;
	for(j=1;j<=n;j++)
	x *=d;
	return x;
	
}

int main(){
	double sum=0.0;
	unsigned i;
	for(i=1;i<=1000000000;i++)//循环可以使用loop_unrolling优化，即展开：
	sum+=powern(i,i%5);//这种调用方式可以使用内联优化
	printf("sum = %g\n",sum);
	return 0;
}



