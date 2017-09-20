#ifndef __EEPROM_H
#define __EEPROM_H

#ifdef __cplusplus
extern "C" {
#endif

/*头文件*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
/*调试宏*/
#define DEBUG

#ifdef DEBUG
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define pr_debug(fmt, ...) 
#endif

/*设备文件名*/
#define EEPROM_DEVFILE_NAME	"/dev/myeeprom"
//#define EEPROM_DEVFILE_NAME	"/dev/at24c02"

#define SVERSION                1       //软件
#define HVERSION                0       //硬件
#define VERSION_LEN             10

/*EEPROM数据结构*/
struct eeprom_cmd {
        unsigned char cmd;      //cmd=SVERSION:获取软件版本信息;cmd=HVERSION:获取硬件版本信息
        unsigned char version[10]; //版本信息
        unsigned char reserved; //4字节对齐,保留
};

/*EEPROM控制命令宏*/
#define EEPROM_READ_VERSION	    0x100008
#define EEPROM_WRITE_VERSION	0x100009

/*EEPROM地址信息*/
#define EEPROM_SVERSION_OFFSET  (0) //软件版本起始地址
#define EEPROM_HVERSION_OFFFSET (EEPROM_SVERSION_OFFSET + 10) //硬件版本起始地址       

/*
 	函数功能:打开EEPROM设备
	参数：无
	返回值：打开设备成功，返回设备文件描述符fd;失败返回-1 
*/
extern int eeprom_open(void);

/*
	函数功能:关闭EEPROM设备
	参数：
		@fd:设备文件描述符
	返回值：无
*/
extern void eeprom_close(int fd);

/*
	函数功能：写入版本信息
	参数：
		@fd:设备文件描述符;
	        @version:版本信息
        返回值：操作成功，返回0，否则返回-1
*/
extern int eeprom_write(int fd, struct eeprom_cmd *version);

/*
        函数功能：获取版本信息
	参数：
		@fd:设备文件描述符;
	        @version:获取EEPROM版本信息
        返回值：操作成功，返回0，否则返回-1
 */
extern int eeprom_read(int fd, struct eeprom_cmd *version);

#ifdef __cplusplus
}
#endif

#endif
