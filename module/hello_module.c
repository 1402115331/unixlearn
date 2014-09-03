#include<linux/init.h>  //初始换函数
#include<linux/kernel.h>  //内核头文件
#include<linux/module.h>  //模块的头文件
MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void){
printk(KERN_ALERT "Hello World enter \n");
return 0;
}
static void hello_exit(void){
	printk(KERN_ALERT "Hello world exit \n");

}
module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Song Baohua");
MODULE_DESCRIPTION("A simple hello world test");
MODULE_ALIAS(" a simple module");