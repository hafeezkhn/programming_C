#include<linux/kernel.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
char *name ="EMBEDDED";
int loop_count=1;

module_param(name,charp,S_IRUGO);
module_param(loop_count,int,S_IRUGO);

static int test_arguments_init(void)
{
  int i;
  printk(KERN_INFO"%s: IN init\n",__func__);
  printk(KERN_INFO"%s: loop count: %d\n",__func__,loop_count);

  for(i=0;i<loop_count;i++)
	  printk(KERN_INFO"%s : HI %s\n",__func__,name);
  return 0;
}

static void test_arguments_exit(void)
{
 printk(KERN_INFO"%s: In exit\n",__func__);
}

module_init(test_arguments_init);
module_exit(test_arguments_exit);

/* for passing parameters
 * sudo insmod ./passing_param.ko loop_count=5
 *
 * sudo insmod ./passing_param.ko loop_count=5 name="LINUX WORLD"
 *
 * '"LINUX WORLD"' 
 * modinfo ./passing_param.ko
 *  
 */

