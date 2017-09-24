logo1.bin     rootfs.img  u-boot.bin    zImage
mach-tq210.c  rootfs.zip  userdata.img


logo1.bin:开机画面图片，后续开发板带屏扩展功能需要

rootfs.img:最终烧录的根文件系统镜像

u-boot.bin:备份的bootloader

zImage：最终烧录的内核镜像

mach-tq210.c:最终的内核的平台文件，可直接替换"Kernel"/arch/arm/mach-s5pv210/mach-tq210.c

rootfs.zip:根文件系统的备份zip包

userdata.img:最终的用户软件镜像

