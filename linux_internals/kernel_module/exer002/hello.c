#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");

void func(void);


static int test_hello_init(void)
{
 printk(KERN_INFO"%s : IN INIT\n",__func__);
 func();
return 0;
}
static void test_hello_exit(void)
{
 printk(KERN_INFO"%s : IN EXIT\n",__func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

