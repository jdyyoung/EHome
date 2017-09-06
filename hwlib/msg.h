#ifndef __MSG_H
#define __MSG_H

#define INFO(X...) fprintf(stdout,"%s %s %s:",__DATE__,__TIME__,__func__);fprintf(stdout,X)
#define LOG(X...) fprintf(stdout,"%s %s %s:",__DATE__,__TIME__,__func__);fprintf(stdout,X)
#define ERR(X...) fprintf(stderr,"%s %s %s:",__DATE__,__TIME__,__func__);fprintf(stderr,X)

//消息类型编号
//系统登陆
#define LOGIN_EHOME     1000
//ZIGBEE控制命令
#define ZIGBEE_SCAN_MAC 2000
#define ZIGBEE_SET_MAC  2001
#define ZIGBEE_LED_ON   2002
#define ZIGBEE_LED_OFF  2003


//系统信息显示
//#define GET_MEMINFO     3001
//#define GET_CPUINFO     3002
//#define GET_DISKINFO    3003
#define GET_HARDWARE_INFO 3000

//升级
#define USERDATA_UPDATE   4000
#define KERNEL_UPDATE     4001
#define ROOTFS_UPDATE     4002

//获取温度
#define GET_TEMPERATURE   5000

//返回错误消息
#define RETURN_ERROR    -1

#endif
