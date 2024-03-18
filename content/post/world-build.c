#include <linux/init.h>
#include <linux/module.h>

static char *whom = "World";
module_param(whom, charp, S_IRUGO|S_IWUSR);

void world_print(char* greet)
{
	printk(KERN_INFO "%s, %s\n", greet, whom);
}
EXPORT_SYMBOL(world_print);

static int __init world_init(void)
{
	printk(KERN_INFO "Init, %s\n", whom);
	return 0;
}
module_init(world_init);

static void __exit world_exit(void)
{
	printk(KERN_INFO "Exit, %s\n", whom);
}
module_exit(world_exit);

MODULE_AUTHOR("Iulian Costan <kernel@costan.ro>");
MODULE_DESCRIPTION("World module that exports a symbol");
MODULE_LICENSE("Dual BSD/GPL");
