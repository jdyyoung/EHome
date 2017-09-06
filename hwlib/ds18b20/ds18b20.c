#include "ds18b20.h"

int ds18b20_open(void)
{
	int fd = open(DS18B20_DEVFILE_NAME, O_RDWR);
	if (fd < 0) {
		pr_debug("open ds18b20 device failed.\n");
		return -1;	
	}
	pr_debug("open ds18b20 device successfully!\n");
	return fd;
}

void ds18b20_close(int fd) 
{
	pr_debug("close ds18b20 device...\n");
	close(fd);
}


int ds18b20_read(int fd, struct ds18b20_cmd *ds18b20data)
{
        int ret;
        int data;

	if (fd < 0) {
		pr_debug("fd is invalid.\n");
		return -1;
	}

        if (ds18b20data == NULL) {
            pr_debug("ds18b20data is invalid.\n");
            return -1;
        }

        ret = read(fd, &data, sizeof(data));
        if (ret == -1) {
                pr_debug("read ds18b20 device failed.\n");
                return -1;
        }

        ds18b20data->temperature = (float)data / 10000; 
        return 0;
}
