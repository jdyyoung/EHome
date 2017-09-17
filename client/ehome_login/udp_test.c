#include "udp.h"
#include "msg.h"
#include "log.h"
#include <string.h>

char ip_addr[64];
void on_connect_btn_clicked()
{
    struct passwd_info info={ };
    int ret;
    int cmd = LOGIN_EHOME;

    //info.user[]="jdyyoung";
    //info.pwd="ehome123456";
    //ip_addr="192.168.1.8";
    strcpy(info.user,"jdyyoung");
    strcpy(info.pwd,"ehome123456");
    strcpy(ip_addr,"192.168.1.6");



    ret=udp_init(CLIENT,ip_addr,8888);
    if(ret == -1)
    {
        printf("init socket error!\n");
    }

    ret=udp_write(CLIENT,(char *)&cmd,sizeof(int));
    if(ret==-1)
    {
        printf("udp_write cmd error!\n");
        return;
    }

    ret=udp_write(CLIENT,(char *)&info,sizeof(struct passwd_info));
    if(ret==-1)
    {
        printf("udp_write passwd_info error!\n");
        return;
    }

    //读取返回的登录结果
    int result = 0;
    ret = udp_read(CLIENT,(char*)&result,sizeof(char));
    if(ret == -1)
    {
        printf("udp_read error!\n");
    }
    else
    {
        if(result == LOGIN_SUCCESS)
        {
            printf("login success!\n");
        }
        else
        {
            printf("login failed:user or password error!\n");
        }
    }

    udp_exit();
}

int main()
{
    on_connect_btn_clicked();
    return 0;
}
