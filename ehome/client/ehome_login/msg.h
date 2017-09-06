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
#define GET_VERSIONS    3000
#define GET_MEMINFO     3001
#define GET_CPUINFO     3002
#define GET_DISKINFO    3003

//返回错误消息
#define RERURN_ERROR    -1

#endif
