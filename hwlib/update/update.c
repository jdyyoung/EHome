#include "update.h"

int update_kernel(char *name)
{

        char update_cmd[100] = {0};
        int ret;

        //擦出 flash_erase /dev/mtd2 0 0
        sprintf(update_cmd, "%s %s 0 0", 
                        ERASE_CMD, ZIMAGE_MTD_PART);
        pr_debug("erase cmd: %s\n", update_cmd);
        ret=system(update_cmd);
        if(ret)
        {
            return UPDATE_FAILED;
        }
       
        //写入镜像 nandwrite -p /dev/mtd2 /mnt/usb/zImage
        bzero(update_cmd, 100);
        sprintf(update_cmd, "%s -p %s %s\n", 
                        WRITE_CMD, ZIMAGE_MTD_PART, name);
        pr_debug("write cmd: %s\n", update_cmd);
        ret=system(update_cmd);
        if(ret)
        {
            return UPDATE_FAILED;
        }
        else
        {
            return UPDATE_SUCCESS;
        }
}

int update_rootfs(char *name)
{
        char update_cmd[100] = {0};
        int ret;

        //擦出 flash_erase /dev/mtd3 0 0
        sprintf(update_cmd, "%s %s 0 0", 
                        ERASE_CMD, ROOTFS_MTD_PART);
        pr_debug("erase cmd: %s\n", update_cmd);
        ret=system(update_cmd);
        if(ret)
        {
            return UPDATE_FAILED;
        }
       
        //写入镜像 nandwrite -p /dev/mtd3 /mnt/usb/rootfs.img
        bzero(update_cmd, 100);
        sprintf(update_cmd, "%s -p %s %s\n", 
                        WRITE_CMD, ROOTFS_MTD_PART, name);
        pr_debug("write cmd: %s\n", update_cmd);
        ret=system(update_cmd);
        if(ret)
        {
            return UPDATE_FAILED;
        }
        else
        {
            return UPDATE_SUCCESS;
        }
}

int  update_userdata(char *name)
{
        char update_cmd[100] = {0};
        int ret;

        //擦出 flash_erase /dev/mtd4 0 0
        sprintf(update_cmd, "%s %s 0 0", 
                        ERASE_CMD, USERDATA_MTD_PART);
        pr_debug("erase cmd: %s\n", update_cmd);
        ret=system(update_cmd);
        if(ret)
        {
            return UPDATE_FAILED;
        }
       
        //写入镜像 nandwrite -a -o /dev/mtd4 /mnt/usb/userdata.img 
        bzero(update_cmd, 100);
        sprintf(update_cmd, "%s -a -o %s %s\n", 
                        WRITE_CMD, USERDATA_MTD_PART, name);
        pr_debug("write cmd: %s\n", update_cmd);
        ret=system(update_cmd);
        if(ret)
        {
            return UPDATE_FAILED;
        }
        else
        {
            return UPDATE_SUCCESS;
        }
}
