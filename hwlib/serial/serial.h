#ifndef __SERIAL_H
#define __SERIAL_H

#ifdef __cplusplus
extern "C" {
#endif

/*头文件*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

/*调试宏*/
//#define DEBUG

#ifdef DEBUG
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define pr_debug(fmt, ...) 
#endif

/*设备文件名*/
//#define SERIAL_DEVFILE_NAME	"/dev/ttySAC1"
#define SERIAL_DEVFILE_NAME	"/dev/ttyUSB0"
//#define SERIAL_DEVFILE_NAME  	"/dev/s3c2410_serial1"
//#define SERIAL_DEVFILE_NAME	"/dev/ttySAC2"

/*SERIAL数据结构*/
struct serial_cmd {
    unsigned int bps; //波特率
    unsigned char databits; //数据位
    unsigned char stopbits; //停止位
    unsigned char parity; //奇偶校验位
    unsigned char reserved;
};

/*
 	函数功能:打开SERIAL设备
	参数：无
	返回值：打开设备成功，返回设备文件描述符fd;失败返回-1 
*/
extern int serial_open(void);

/*
	函数功能:关闭SERIAL设备
	参数：
		@fd:设备文件描述符
	返回值：无
*/
extern void serial_close(int fd);

/*
	函数功能：配置SERIAL的工作参数
	参数：
		@fd:设备文件描述符;
	        @serialctrl:控制SERIAL命令
        返回值：操作成功，返回0，否则返回-1
*/
extern int serial_config(int fd, struct serial_cmd *serialctrl);

/*
        函数功能：读取串口
	参数：
		@fd:设备文件描述符;
        返回值：操作成功，返回0，否则返回-1
 */
extern int serial_read(int fd, char *buf, int size);

/*
        函数功能：写串口
	参数：
		@fd:设备文件描述符;
        返回值：操作成功，返回0，否则返回-1
 */
extern int serial_write(int fd, char *buf, int size);

#ifdef __cplusplus
}
#endif

#endif
