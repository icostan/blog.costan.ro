#define WORLD_MAJOR 6
#define WORLD_MINOR 0
#define WORLD_NAME "world"
#define WORLD_WHOM "World"
#define WORLD_SIZE 8
#define WORLD_IOC_MAGIC 'w'
#define WORLD_IOCRESET _IO(WORLD_IOC_MAGIC, 0)
#define WORLD_IOCSWHOM _IOW(WORLD_IOC_MAGIC, 1, char)
#define WORLD_IOCGWHOM _IOR(WORLD_IOC_MAGIC, 2, char)
