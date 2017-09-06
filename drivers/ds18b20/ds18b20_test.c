#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        int fd;
        int data;
        
        fd = open("/dev/ds18b20", O_RDWR);
        if (fd < 0) {
                printf("open ds18b20 failed.\n");
                exit(-1);
        }

        while (1) {
                read(fd, &data, sizeof(data));
                sleep(1);
                printf("%.3f\n", (float)data / 10000);        
        }
        close(fd);
        return 0;
}
