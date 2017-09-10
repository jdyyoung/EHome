#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<crypt.h>

#include"log.h"
#include"udp.h"
#include"device.h"
#include"msg.h"
#include"eeprom.h"

#define _XOPEN_SOURCE

extern void recvcmd(void);
extern void login_verify(void);

#define PASSWD_FILE "/home/ehome/etc/passwd"

int main()
{
    int ret=device_init();
    if(ret == ERROR)
    {
        ERR("device_init\n");
    }
    else
    {
        LOG("init success\n");
    }
    recvcmd();
    return 0;
}

void recvcmd(void)
{
    int cmd;
    while(1)
    {
        int ret =udp_read(SERVER,(char*)&cmd,sizeof(cmd));
        if(ret == -1)
        {
            ERR("udp_read!");
        }
        pr_debug("read cmd success\n");
        pr_debug("cmd=%d\n",cmd);
        ret=GET_HARDWARE_INFO;
        pr_debug("GET_HARDWARE_INFO=%d\n",ret);
        switch(cmd)
        {
            case LOGIN_EHOME:
                login_verify();
                break;
            case ZIGBEE_SCAN_MAC:
                zigbee_scan_mac();
                break;
            case ZIGBEE_SET_MAC:
                zigbee_set_mac();
                break;
            case ZIGBEE_LED_ON:
                ret=zigbee_led_on();
                if(ret == ERROR)
                {
                    pr_debug("set zigbee led on failed!\n");
                }
                break;

            case ZIGBEE_LED_OFF:
                pr_debug("test!\n");
                ret = zigbee_led_off();
                if(ret == ERROR)
                {
                    pr_debug("set zigbee led off failed!\n");
                }
                break;
            case GET_TEMPERATURE:
                ret =get_temperature();
                if(ret == ERROR)
                {
                    pr_debug("get tempature faild!\n");
                }
                break;
           case GET_HARDWARE_INFO:
                ret=get_hardware_infomation();
                if(ret == ERROR)
                {
                    pr_debug("get hardware infomation failed!\n");
                }
                break;
            case KERNEL_UPDATE:
                ret=kernel_update();
                if(ret == ERROR)
                {
                    pr_debug("kernel_update failed!\n");
                }
                break;
            case USERDATA_UPDATE:
                ret=rootfs_update();
                if(ret == ERROR)
                {
                    pr_debug("rootfs_update failed!\n");
                }
                break;
            case ROOTFS_UPDATE:
                ret=userdata_update();
                if(ret == ERROR)
                {
                    pr_debug("userdata_update failed!\n");
                }
                break;
            default:
                LOG("cmd is not defined!\n");
                break;
        }
    }
}

void login_verify()
{
    char nm[64];
    char salt[17];
    char dcrypt[128];
    int size;
    int i=0;
    char tmp;
    int result;
    struct passwd_info info={};
    int ret=udp_read(SERVER,(char*)&info,sizeof(info));
    if(ret == -1)
    {
        perror("udp_read");
        return;
    }
    else
    {
        pr_debug("name:%s,passwd:%s\n",info.user,info.pwd);
    }

    int fd=open(PASSWD_FILE,O_RDONLY);
    if(fd == -1)
    {
        ERR("open");
    }

    /*read username*/
    while((size=read(fd,&tmp,1))>0)
    {
        if(tmp == '\0')
        {
            nm[i]=tmp;
            break;
        }
        else
        {
            nm[i++]=tmp;
        }
    }
    pr_debug("nm=%s\n",nm);
    /*compare username with info->name*/
    if(strcmp(nm,info.user))
    {
        close(fd);
        pr_debug("wrong username \n");
        return;
    }

    /*read salt*/
    i=0;
    while((size=read(fd,&tmp,1))>0)
    {
        if(tmp == '\0')
        {
            salt[i]=tmp;
            break;
        }
        else
        {
            salt[i++]=tmp;
        }
    }
    pr_debug("salt= %s\n",salt);
    /*read tarena(98) from passwd file*/
    i=0;
    while((size=read(fd,&tmp,1))>0)
    {
        if(tmp == '\0')
        {
            dcrypt[i]=tmp;
            break;
        }
        else
        {
            dcrypt[i++]=tmp;
        }
    }

    pr_debug("dcrypt=%s\n",dcrypt);
    close(fd);

    /*encrypt info->pwd with salt ->c*/
    char* c=crypt(info.pwd,salt);

    if(strncmp(c,dcrypt,98))
    {
        result=LOGIN_FAILD;
        udp_write(SERVER,(char*)&result,sizeof(int));
        return;
    }
    else
    {
        //认证通过
        result=LOGIN_SUCCESS;
        udp_write(SERVER,(char*)&result,sizeof(int));
        //并返回获取的版本号
        //获取版本号填到结构体，并发送返回
        int fd;
        struct eeprom_cmd versioninfo;
        fd = eeprom_open();
        if (fd < 0)
        {
            return;
        }

        //读取软件版本信息
        versioninfo.cmd = SVERSION;
        if (eeprom_read(fd, &versioninfo) == -1)
        {
            return;
        }
        pr_debug("sversion = %s\n", versioninfo.version); 
        udp_write(SERVER,(char*)versioninfo.version,VERSION_LEN );
        //读取硬件版本信息
        versioninfo.cmd = HVERSION;
        if (eeprom_read(fd, &versioninfo) == -1)
        {
            return;
        }
        pr_debug("hversion = %s\n", versioninfo.version);
        udp_write(SERVER,(char*)versioninfo.version,VERSION_LEN);
        eeprom_close(fd);    
    }
    return;
}


