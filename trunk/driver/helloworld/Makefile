ifneq ($(KERNELRELEASE),)
obj-m := helloworld.o
else
KERNELSRC := /lib/modules/`uname -r`/build

modules:
	make -C $(KERNELSRC) SUBDIRS=$(PWD) $@

clean:
	rm -f *.o *.ko *.mod.c *~ *.order *.symvers
endif
