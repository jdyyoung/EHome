#include "serial.h"

int main(int argc, char *argv[])
{
	int fd,i;
        struct serial_cmd serialctrl;
        char rbuf[1024] = {0};
        //char rbuf;
        //char tmp;
	
	fd = serial_open();
	if (fd < 0) 
		return -1;

        serialctrl.bps = 115200;
        serialctrl.stopbits = 1;
        serialctrl.databits = 8;
        serialctrl.parity = 'N';

        if (serial_config(fd, &serialctrl) == -1)
            return -1;
       // if (serial_write(fd, "hello,world", strlen("hello,world")) == -1)
         //               return -1;

        //sleep(1);
        while (1) {
                if (serial_read(fd, rbuf, 1024) == -1)
                        return -1;
                sleep(2);
                printf("receive data is %s\n", rbuf);
                //break;
        }
 
/*       if (serial_read(fd, rbuf, 1024) == -1)
             return -1;
        i=0;
       while(rbuf[i]!='\0')
       {
            printf("%02 ",rbuf[i]);
            i++;
       }
        printf("\n");
        
        while(1)
        {
            if(serial_read(fd,&tmp,1)==-1)
                return -1;
            if(tmp==0x0A)
            {
                printf("\n");
                break;
            }
            else
            {
                printf("%02x ",tmp);
            }
        }*/
        serial_close(fd);
	return 0;
}

