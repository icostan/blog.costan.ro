#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

#define WORLD_MAJOR 6
#define WORLD_MINOR 0
#define WORLD_NAME "world"
#define WORLD_WHOM "World"
#define WORLD_IOC_MAGIC 'w'
#define WORLD_IOCRESET _IO(WORLD_IOC_MAGIC, 0)
#define WORLD_IOCSWHOM _IOW(WORLD_IOC_MAGIC, 1, int)
#define WORLD_IOCGWHOM _IOR(WORLD_IOC_MAGIC, 2, int)

static char *whom = WORLD_WHOM;
module_param(whom, charp, S_IRUGO|S_IWUSR);

long world_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    int retval = 0;
    switch (cmd) {
    case WORLD_IOCRESET:
        whom = WORLD_WHOM;
        break;
    case WORLD_IOCSWHOM: /* Set: arg points to the value */
        retval = __get_user(whom, (char* __user *)arg);
        break;
    case WORLD_IOCGWHOM: /* Get: arg is pointer to result */
        retval = __put_user(whom, (char* __user *)arg);
        break;
    default:
        return -ENOTTY;
    }
    return retval;
}

struct file_operations world_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = world_ioctl,
};

static int __init world_init(void)
{
    int err;
    err = register_chrdev(WORLD_MAJOR, WORLD_NAME, &world_fops);
    printk(KERN_INFO "Init, %s\n", whom);
    return err;
}
module_init(world_init);

static void __exit world_exit(void)
{
    unregister_chrdev(WORLD_MAJOR, WORLD_NAME);
    printk(KERN_INFO "Exit, %s\n", whom);
}
module_exit(world_exit);

MODULE_AUTHOR("Iulian Costan <blog@costan.ro>");
MODULE_DESCRIPTION("World module that exports a symbol");
MODULE_LICENSE("Dual BSD/GPL");
