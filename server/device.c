#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/vfs.h>

#include"device.h"
#include"udp.h"
#include"serial.h"
#include"msg.h"
#include"ds18b20.h"
#include"update.h"

char macs[8];
int zigbee_fd;

#define ZIGBEE_MAC_FILE "/home/ehome/etc/zigbee_mac"

int device_init()
{
    int ret = udp_init(SERVER,IP,PORT);
    if(ret == -1)
    {
        ERR("udp_init error!\n");
        return ERROR;
    }

    zigbee_fd = serial_open();
    if(zigbee_fd == -1)
    {
        ERR("serial_open fail!\n");
        return ERROR;
    }

    struct serial_cmd serialctrl;
    serialctrl.bps = 115200;
    serialctrl.stopbits = 1;
    serialctrl.databits = 8;
    serialctrl.parity = 'N';

    ret = serial_config(zigbee_fd,&serialctrl);
    if(ret == -1)
    {
        ERR("serial_config fail!\n");
        return ERROR;
    }
    return SUCCESS;
}

int zigbee_scan_mac()
{
    //发送获取命令 
    unsigned char cmd[5] = {0};
    cmd[0] = 0xFC;
    cmd[1] = 0x04;
    cmd[2] = 0xA1;
    cmd[3] = 0x01;
    cmd[4] = cmd[1]^cmd[2]^cmd[3];
    if(write(zigbee_fd,cmd,5) !=5)
    {
        ERR("write zigbeefd error.\n");
        return ERROR;
    }

    //获取设备返回
    unsigned char buf[14] = {0};
    if(read(zigbee_fd,buf,14) != 14)
    {
        ERR("read zigbeefd error.\n");
        //返回错误信息给终端
        int cmd = RETURN_ERROR;
        udp_write(SERVER,(char*)&cmd,4);
        return ERROR;
    }

    //保存8bit mac地址
    memcpy(macs,buf+5,8);
    int i;
    for(i=0;i<8;i++)
    {
        printf("%x ",macs[i]);
    }
    printf("\n");

    //发送macs到客户端 
    if(udp_write(SERVER,macs,8) == -1)
    {
        ERR("send mac to client error!\n");
        return ERROR;
    }

    return SUCCESS;

}

int zigbee_set_mac()
{
    int fd = open(ZIGBEE_MAC_FILE,O_RDWR|O_CREAT,0664);
    if(fd == -1)
    {
        ERR("write zigbee mac file error!\n");
        return ERROR;
    }
    char tmp[30] = {0};
    sprintf(tmp,"%02x %02x %02x %02x %02x %02x %02x %02x",macs[0],macs[1], macs[2],macs[3],macs[4],macs[5], macs[6],macs[7]);

    int ret = write(fd,tmp,strlen(tmp));
    if(ret == -1)
    {
        ERR("write zigbee mac file error!\n");
        return ERROR;
    }
    //if(buf[4]==1)
    //{
      //  return SUCCESS;
    //}
    return SUCCESS;
}

int zigbee_led_on()
{
    LOG("zigbee led on\n");
    unsigned char cmd[6],rbuf[7];
    //led_on cmd;
    cmd[0] = 0xFC;
    cmd[1] = 0x05;
    cmd[2] = 0xa1;
    cmd[3] = 0x03;
    cmd[4] = 0x01;//将灯的状态设置为0或者1
    cmd[5] = 0x5a;

    //zigbee发送点灯命令
    if(serial_write(zigbee_fd,(char*)cmd,6)!=6)
    {    
        ERR("write zigbee cmd:led on!\n");
        return ERROR;
    }

   //zigbee接收返回指令 
   if(serial_read(zigbee_fd,(char*)rbuf,7)==-1)
   {
        return ERROR;
   }
/*
    int i;
    unsigned char cmd[100] = {0};
    cmd[0] = 0xFC;
    cmd[1] = 0x0d;
    cmd[2] = 0xa1;
    cmd[3] = 0x03;
    cmd[4] = 0x01;//将灯的状态设置为0或者1
    //mac地址 bit5
    memcpy(&cmd[5],macs,8);

    //异或校验 bit13
    for(i=1;i<13;i++)
    {
        cmd[13] ^= cmd[i];
    }

    //zigbee发送点灯命令
    if(write(zigbee_fd,cmd,14)!=14)
    {
        ERR("write zigbee cmd:led on!\n");
        return ERROR;
    }
    //zigbee返回数据 
    unsigned char buf[6]={};
    if(read(zigbee_fd,buf,6)==-1)
    {
        return ERROR;
    }

    for(i=0;i<6;i++)
    {
        printf("%x ",buf[i]);
    }
    printf("\n");
*/

    return SUCCESS;
}

int zigbee_led_off()
{
    LOG("zigbee led off.\n");
    unsigned char cmd[6],rbuf[7];
    //led_off cmd;
    cmd[0] = 0xFC;
    cmd[1] = 0x05;
    cmd[2] = 0xa1;
    cmd[3] = 0x03;
    cmd[4] = 0x00;//将灯的状态设置为0或者1
    cmd[5] = 0x5b;

    //zigbee发送关灯命令
    if(serial_write(zigbee_fd,(char*)cmd,6)!=6)
    {    
        ERR("write zigbee cmd:led off!\n");
        return ERROR;
    }

   //zigbee接收返回指令 
   if(serial_read(zigbee_fd,(char*)rbuf,7)==-1)
   {
       ERR("serial_read zigbee ruturned cmd fail!\n");
       return ERROR;
   }
    /*
    int i;
    unsigned char cmd[100] = {};
    cmd[0] = 0xFC;
    cmd[1] = 0x0d;
    cmd[2] = 0xa1;
    cmd[3] = 0x03;
    cmd[4] = 0x00;//将灯的状态设置为0或者1
    //mac地址 bit5
    memcpy(&cmd[5],macs,8);

    //异或校验 bit13
    for(i=1;i<13;i++)
    {
        cmd[13] ^= cmd[i];
    }

    //zigbee发送灭灯命令
    if(write(zigbee_fd,cmd,14)!=14)
    {
        ERR("write zigbee cmd:led off!\n");
        return ERROR;
    }
    //zigbee返回数据
    char buf[6]={};
    if(read(zigbee_fd,buf,6)==-1)
    {
        return ERROR;
    }
    for(i=0;i<6;i++)
    {
        printf("%x ",buf[i]);
    }
    printf("\n");

    if(buf[4] == 1)
    {
        return SUCCESS;
    }
    return ERROR;
    */
   return SUCCESS;
}

/*获取温度*/
int get_temperature(void)
{
    int fd,result;
    struct ds18b20_cmd ds18b20ctrl;
    fd = ds18b20_open();
    if (fd < 0) 
    {
        ERR("ds18b20_open fail!\n");
        return ERROR;
    }
    if (ds18b20_read(fd, &ds18b20ctrl) == -1)
    {
        ERR("ds18b20_read fail!\n");
        return ERROR;
    }
    ds18b20_close(fd);
    pr_debug("current temperature is %.3f\n", ds18b20ctrl.temperature);
    result = SUCCESS;
    udp_write(SERVER,(char*)&ds18b20ctrl.temperature,sizeof(float));
    //再传送温度值
    return SUCCESS;
}


/*字符串解析*/
char* parse_string(char* file,char* string)
{
    int size=16384;
    char pbuf[size];

    char* ptmp;
    char* ptmp1;
    int fd;
    int nread;

    if(!file || !string)
    {
        return NULL;
    }

    /*打开文件*/
    fd = open(file,O_RDONLY);
    if(fd<0)
    {
        ERR("open %s file error!\n",file);
        return NULL;
    }
    nread=read(fd,pbuf,size);
    if(nread<0)
    {
        ERR("read %s file error!",file);
        return NULL;
    }

    /*解析字符串*/
    ptmp = strstr(pbuf,string);
    if(ptmp==NULL)
    {
        return NULL;
    }
    ptmp += strlen(string);

    while(1)
    {
        if((*ptmp == ' ') || (*ptmp == ':') || (*ptmp == '\t'))
        {
            /*nothing*/
        }
        else
        {
            ptmp1 = strchr(ptmp,'\n');
            *ptmp1 = '\0';
            break;
        }
        ptmp++;
    }
    return ptmp;
}

void get_cpu_freq(int* cpufreq)
{
    char* file = "/proc/cpuinfo";
    char* pstr = "BogoMIPS";
    char* ptmp;

    ptmp = parse_string(file,pstr);
    if(ptmp == NULL)
    {
        *cpufreq =0;
        return;
    }
    *cpufreq = strtol(ptmp,NULL,10);

}

/*获取当前剩余内存*/
void get_freemem_space(int *freemem)
{
    char* file = "/proc/meminfo";
    char* pstr = "MemFree:";
    char* ptmp;

    ptmp = parse_string(file,pstr);

    *freemem = strtol(ptmp,NULL,10);
}

/*获取当前剩余磁盘空间*/
void get_freedisk_space(int* freedisk)
{
    long long free;
    long long blocks;
    struct statfs stat;
    char* dev = "/home/";

    statfs(dev,&stat);

    blocks = stat.f_blocks;
    free =stat.f_bfree;
    *freedisk = free * stat.f_bsize / (1024.00 * 1024.00);
}

int get_hardware_infomation()
{
    int result;
    struct hardware_info
    {
        int cpu_freq;
        int free_mem;
        int free_disk;
    }hw_info;

    get_cpu_freq(&(hw_info.cpu_freq));
    get_freemem_space(&(hw_info.free_mem));
    get_freedisk_space(&(hw_info.free_disk));
    pr_debug("cpu=%d,mem=%d,disk=%d\n",hw_info.cpu_freq,hw_info.free_mem,hw_info.free_disk);
    result = SUCCESS;
    //udp_write(SERVER,(char*)&result,sizeof(int));
    udp_write(SERVER,(char*)&hw_info,sizeof(struct hardware_info));
    return SUCCESS;
}

int kernel_update()
{
    int result;
    result=update_kernel("/mnt/usb/zImage");
    udp_write(SERVER,(char*)&result,sizeof(int));
    return result;

}
int rootfs_update()
{
    pr_debug("test\n");
    return SUCCESS;
}

int userdata_update()
{
    pr_debug("test!\n");
    return SUCCESS;
}



