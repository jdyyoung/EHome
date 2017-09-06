#include "update.h"

void update_sw(char *name)
{

        char update_cmd[100] = {0};

        if (!strcmp(name, "/mnt/usb/zImage")) {
                //擦出 flash_erase /dev/mtd2 0 0
                sprintf(update_cmd, "%s %s 0 0", 
                                "flash_erase", "/dev/mtd2");
                system(update_cmd);

                //写入镜像 nandwrite -p /dev/mtd1 zImage
                /*
                	bzero(void *s,int n);
                	 置字节字符串s的前n个字节为零且包括'\0'
                */
                bzero(update_cmd, 100);
                sprintf(update_cmd, "%s -p %s %s\n", 
                                "nandwrite", "/dev/mtd2", name);
                system(update_cmd);
        }
}
