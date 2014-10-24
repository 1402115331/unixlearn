#include<linux/init.h>  //初始换函数
#include<linux/kernel.h>  //内核头文件
#include<linux/module.h>  //模块的头文件
MODULE_LICENSE("Dual BSD/GPL");

int day;
int num;
module_param(day,int,0);//引入参数后，内核中会增加一个optional的section
module_param(num,int ,0);
static int hello_init(void){
printk(KERN_ALERT "Hello World enter \n");
return 0;
}
static void hello_exit(void){
	printk(KERN_ALERT "Hello world exit \n");

}
EXPORT_SYMBOL(day);//通过管理员身份查看/proc/kallsyms(kernel all sym s)可以查看所有的导出符号使用导出和不适用导出，确实差异很明显的，并且section的数量也会变大。
EXPORT_SYMBOL(hello_init);
module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("zhanghaiyu");
MODULE_DESCRIPTION("a simple test");
MODULE_ALIAS(" a simple module");
