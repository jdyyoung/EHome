#include "serial.h"

int main(int argc, char *argv[])
{
	int fd;
        struct serial_cmd serialctrl;
        char rbuf[1024] = {0};
	
	fd = serial_open();
	if (fd < 0) 
		return -1;

        serialctrl.bps = 115200;
        serialctrl.stopbits = 1;
        serialctrl.databits = 8;
        serialctrl.parity = 'N';

        if (serial_config(fd, &serialctrl) == -1)
            return -1;

        while (1) {
                if (serial_write(fd, "hello,world", strlen("hello,world")) == -1)
                        return -1;
                sleep(1);
        }
        
        serial_close(fd);
	return 0;
}

