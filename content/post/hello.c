#include <linux/init.h>
#include <linux/module.h>

static int howmany = 1;
module_param(howmany, int, S_IRUGO);
static char *greet = "Hello";
module_param(greet, charp, S_IRUGO);

extern void world_print(char* greet);

static int __init hello_init(void)
{
	printk(KERN_INFO "Init, Hello\n");
	int i;
	for (i = 0; i < howmany; i++) {
		world_print(greet);
	}
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Exit, Hello\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Iulian Costan <kernel@costan.ro");
MODULE_DESCRIPTION("Hello module that depends on World module");
MODULE_LICENSE("Dual BSD/GPL");
