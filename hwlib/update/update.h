#ifndef __UPDATE_H
#define __UPDATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*头文件*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>

/*调试宏*/
#define DEBUG

#ifdef DEBUG
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define pr_debug(fmt, ...) 
#endif

#define ERASE_CMD       "flash_erase"
#define WRITE_CMD       "nandwrite"

#define ZIMAGE_MTD_PART "/dev/mtd1"
#define ROOTFS_MTD_PART "/dev/mtd2"
#define USERDATA_MTD_PART       "/dev/mtd3"

#define ZIMAGE_PATH     "/mnt/usb/zImage"
#define ROOTFS_PATH     "/mnt/usb/rootfs.img"
#define USERDATA_PATH   "/mnt/usb/userdata.img"

/*升级内核*/
extern void update_kernel(char *name);
/*升级根文件系统*/
extern void update_rootfs(char *name);
/*升级用户软件*/
extern void update_userdata(char *name);

#ifdef __cplusplus
}
#endif

#endif
