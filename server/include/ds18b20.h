#ifndef __DS18B20_H
#define __DS18B20_H

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
#define DS18B20_DEVFILE_NAME	"/dev/ds18b20"

/*DS18B20数据结构*/
struct ds18b20_cmd {
    float   temperature; //温度值
};

/*DS18B20控制命令宏*/
#define DS18B20_CONFIG_REL	        0x100007

/*
 	函数功能:打开DS18B20设备
	参数：无
	返回值：打开设备成功，返回设备文件描述符fd;失败返回-1 
*/
extern int ds18b20_open(void);

/*
	函数功能:关闭DS18B20设备
	参数：
		@fd:设备文件描述符
	返回值：无
*/
extern void ds18b20_close(int fd);


/*
        函数功能：获取DS18B20转换温度值
	参数：
		@fd:设备文件描述符;
	        @ds18b20data:获取DS18B20转换的温度值,保存在temperature字段中
        返回值：操作成功，返回0，否则返回-1
 */
extern int ds18b20_read(int fd, struct ds18b20_cmd *ds18b20data);

#ifdef __cplusplus
}
#endif

#endif
