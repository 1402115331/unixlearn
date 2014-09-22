#include<stdio.h>
#include<math.h>
/****
gcc -Wall -ansi -D_GNU_SOURCE  pi.c
gcc -Wall -ansi pi.c 
gcc pi.c 
用gnu的标准可以编译，ansi的不可以编译，ansi加了-D_GUN_SOURCE就又可以编译啦
说明，gnu时间上相当于当ansi是打了补丁的升级版本，所以可以直接用打好补丁的升级版gnu，也可以自己给ansi打补丁使用ansi


****/
int main(){
printf("pi:%f\n",M_PI);
return 0;
}
