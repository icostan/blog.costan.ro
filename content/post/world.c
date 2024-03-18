#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include "world.h"

static char *whom = NULL;
module_param(whom, charp, S_IRUGO|S_IWUSR);

long world_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    int retval = 0;

    switch (cmd) {
    case WORLD_IOCRESET:
        strncpy(whom, WORLD_WHOM, WORLD_SIZE);
        printk(KERN_INFO "Reset: %s\n", whom);
        break;
    case WORLD_IOCSWHOM: /* Set: arg points to the value */
        retval = copy_from_user(whom, (char __user *)arg, WORLD_SIZE);
        printk(KERN_INFO "Set: %s\n", whom);
        break;
    case WORLD_IOCGWHOM: /* Get: arg is pointer to result */
        retval = copy_to_user((char __user *)arg, whom, WORLD_SIZE);
        printk(KERN_INFO "Get: %s, %d\n", whom, retval);
        break;
    default:
        printk(KERN_INFO "Default: %s\n", whom);
        return -ENOTTY;
    }
    return retval;
}

void world_print(char* greet)
{
    printk(KERN_INFO "%s, %s\n", greet, whom);
}
EXPORT_SYMBOL(world_print);

struct file_operations world_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = world_ioctl,
};

static int __init world_init(void)
{
    int err;
    err = register_chrdev(WORLD_MAJOR, WORLD_NAME, &world_fops);
    if(!whom) {
        whom = kmalloc(WORLD_SIZE, GFP_KERNEL);
        strncpy(whom, WORLD_WHOM, WORLD_SIZE);
    }
    printk(KERN_INFO "Init, %s\n", whom);
    return err;
}
module_init(world_init);

static void __exit world_exit(void)
{
    printk(KERN_INFO "Exit, %s\n", whom);
    if(whom)
        kfree(whom);
    unregister_chrdev(WORLD_MAJOR, WORLD_NAME);
}
module_exit(world_exit);

MODULE_AUTHOR("Iulian Costan <kernel@costan.ro>");
MODULE_DESCRIPTION("World module that exports a symbol");
MODULE_LICENSE("Dual BSD/GPL");
