#ifndef __UDP_H
#define __UDP_H

#ifdef __cplusplus
extern "C" {
#endif

/*头文件*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

/*调试宏*/
//#define DEBUG
#ifdef DEBUG
#define pr_debug(fmt,...) printf(fmt,##__VARGS__)
#else
#define pr_debug(fmt,...)
#endif

#define SERVER 1
#define CLIENT 0

/*
    函数功能：创建socket
    参数：@isserver:区分是服务器还是客户端，destip：目标IP地址，port:端口号
    返回值：创建成功返回0，否则返回-1
*/
extern int udp_init(unsigned char isserver,char *destip,int port);

/*
    函数功能：关闭socket
    参数：无
    返回值：无
*/
extern void udp_exit(void);

/*
    函数功能：UDP发送函数
    参数：
            @buf：发送数据缓冲区起始地址
            @len：数据长度
    返回值：发送成功返回发送的字节数，失败返回-1
 */
extern int udp_write(unsigned char isserver,char *buf,int len);

/*
    函数功能：UDP读取数据包
    参数：
            @buf：接收数据缓冲区首地址
            @len：数据长度
    返回值：读取成功返回读取的字节数，失败返回-1
 * */
extern int udp_read(unsigned char isserver,char *buf,int len);

#ifdef __cplusplus
}
#endif

#endif
