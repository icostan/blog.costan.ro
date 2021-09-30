KDIR ?= /lib/modules/`uname -r`/build

TOOLS = ioctl.o

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

tools: TOOLS
