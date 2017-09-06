#include "serial.h"

int main(int argc, char *argv[])
{
	int fd;
    struct serial_cmd serialctrl;
    char rbuf[7] = {};
    unsigned char cmd[6]={0};
    char tmp;
	int size,i;
	fd = serial_open();
	if (fd < 0) 
		return -1;

        serialctrl.bps = 115200;
        serialctrl.stopbits = 1;
        serialctrl.databits = 8;
        serialctrl.parity = 'N';

        if (serial_config(fd, &serialctrl) == -1)
            return -1;
        //led_on cmd
        cmd[0]=0xFC;
        cmd[1]=0x05;
        cmd[2]=0xa1;
        cmd[3]=0x03;
        cmd[4]=0x01;
        cmd[5]=0x5a;
        //cmd[6]=0x0A;
        
        if(write(fd,cmd,6)!=6)
        {
            pr_debug("write fail!\n");
            return -1;
        }
        
       // serial_write(fd,cmd,6);
        pr_debug("write success!\n");
        sleep(1);
        
        //接收返回数据，并打印
       /* while((size=serial_read(fd,&tmp,1))>0)
        {
            if(tmp=='\0')
            {
                printf("\n");
                break;
            }
            else
            {
                printf("%02x ",tmp);
            }
        }*/

        if(read(fd,rbuf,7)==-1)
        {
            return -1;
        }
        /*for(i=0;i<5;i++)
        {
            tmp ^=rbuf[i];
        }
        if(tmp!=0 && tmp == rbuf[5])
        {
            break;
        }
        */
        //sleep(10);
        
        for(i=0;i<6;i++)
        {
            printf("%02x ",rbuf[i]);
        }
    

       /* for(i=0;i<6;i++)
        {
            printf("%02x ",rbuf[i]);
        }
       */
        printf("\n");
        

        sleep(1);
        //led_off cmd
        cmd[0]=0xFC;
        cmd[1]=0x05;
        cmd[2]=0xa1;
        cmd[3]=0x03;
        cmd[4]=0x00;
        cmd[5]=0x5b;
        //cmd[6]=0x0A;
        if(write(fd,cmd,6)!=6)
        {
            return -1;
        }

        sleep(1);
        
        //接收返回数据，并打印
        if(read(fd,rbuf,7)==-1)
        {
            return -1;
        }
        for(i=0;i<6;i++)
        {
            printf("%02x ",rbuf[i]);
        }
        printf("\n");
    
        serial_close(fd);
	return 0;
}

