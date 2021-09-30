#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "world.h"

int main(int argc, char **argv)
{
    int retval = 0;

    int fd = open("/dev/world0", O_WRONLY);
    if (argc > 1) {
        retval = ioctl(fd, WORLD_IOCSWHOM, argv[1]);
        fprintf(stdout, "IOCTL write: %s\n", argv[1]);
    } else {
        char* result = malloc(5);
        retval = ioctl(fd, WORLD_IOCGWHOM, result);
        fprintf(stdout, "IOCTL read: %s\n", result);
        free(result);
    }
    if (retval < 0) {
        fprintf(stderr, "IOCTL: %s, %d\n", strerror(errno), retval);
        exit(1);
    } else {
        fprintf(stdout, "IOCTL: %s\n", strerror(errno));
        exit(0);
    }
}
