#include "ds18b20.h"

int main(int argc, char *argv[])
{
	int fd;
        struct ds18b20_cmd ds18b20ctrl;

	
	fd = ds18b20_open();
	if (fd < 0) 
		return -1;

        while (1) {
                if (ds18b20_read(fd, &ds18b20ctrl) == -1)
                        return -1;
                printf("current temperature is %.3f\n", ds18b20ctrl.temperature);
                sleep(1);
        }
        
        ds18b20_close(fd);
	return 0;
}

