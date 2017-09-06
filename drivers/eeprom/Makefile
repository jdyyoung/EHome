ifneq ($(KERNELRELEASE),)
    obj-m += at24c02_drv.o
else
    KERNELDIR=/opt/opt/EmbedSky/TQ210/Kernel_3.0.8_TQ210_for_Linux_v2.1/
all:
	PWD=$(shell pwd)  
	$(MAKE) -C $(KERNELDIR) M=$(PWD)
clean:
	rm -rf .*.cmd *.o *.mod.c *.ko .tmp_versions module* Module*
endif

