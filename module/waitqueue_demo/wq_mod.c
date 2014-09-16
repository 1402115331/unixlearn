/*a simple wait_queue demo
 *task_1,task_2 added into the wait_queue, if condition is 0.
 *task_3 change condition to 1, and task_1 task_2 will be wake up
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("cengku@gmail.com");

static int condition;
static struct task_struct *task_1;
static struct task_struct *task_2;
static struct task_struct *task_3;

/*** 声明一个等待队列**/
DECLARE_WAIT_QUEUE_HEAD(wq);


static int thread_func_1(void *data)
{
    int i = 0;
    while (i++ < 100) {
        wait_event(wq, condition == 1);
        msleep(1000);
        printk(">>>>>this task 1\n");
    }
    return 0;
}

static int thread_func_2(void *data)
{
    int i = 0;
    while (i++ < 100) {
        wait_event(wq, condition == 1);
        msleep(1000);
        printk(">>>>>this task 2\n");
    }
    return 0;
}
static int thread_func_3(void *data)
{
    int i = 0;
    while (i++ < 10) {
        condition = 0;
        msleep(2000);
        printk(">>>>>this task 3\n");
        condition = 1;
        wake_up(&wq);
        msleep(2000);
    }
    return 0;
}



static int __init mod_init(void)
{
    printk("=====mod set up===\n");
    condition = 0;

    task_1 = kthread_run(thread_func_1, NULL, "thread%d", 1);
    if (IS_ERR(task_1))
        printk("**********create thread 1 failed\n");
    else
        printk("======success create thread 1\n");

    task_2 = kthread_run(thread_func_2, NULL, "thread%d", 2);
    if (IS_ERR(task_2))
        printk("**********create thread 2 failed\n");
    else
        printk("======success create thread 2\n");

    task_3 = kthread_run(thread_func_3, NULL, "thread%d", 3);
    if (IS_ERR(task_3))
        printk("**********create thread 3 failed\n");
    else
        printk("======success create thread 3\n");
    return 0;
}

static void __exit mod_exit(void)
{
    int ret;
    if (!IS_ERR(task_1)) {
        ret = kthread_stop(task_1);
        if (ret > 0)
            printk("<<<<<<<<<thread 1 has run %ds\n", ret);
    }
        
    if (!IS_ERR(task_2)) {
        ret = kthread_stop(task_2);
        if (ret > 0)
            printk("<<<<<<<<<thread 2 has run %ds\n", ret);
    }

    if (!IS_ERR(task_3)) {
        ret = kthread_stop(task_3);
        if (ret > 0)
            printk("<<<<<<<<<thread 3 has run %ds\n", ret);
    }
}
module_init(mod_init);
module_exit(mod_exit);