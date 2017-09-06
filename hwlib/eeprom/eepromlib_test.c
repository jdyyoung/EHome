#include "eeprom.h"
#include <string.h>

int main(int argc, char *argv[])
{
	int fd;
        struct eeprom_cmd versioninfo;

	fd = eeprom_open();
	if (fd < 0) 
		return -1;

        //写入软件版本
        strcpy(versioninfo.version, "S17090300");
        versioninfo.cmd = SVERSION;

        if (eeprom_write(fd, &versioninfo) == -1)
            return -1;
        
        //写入硬件件版本
        strcpy(versioninfo.version, "H17090300");
        versioninfo.cmd = HVERSION;

        if (eeprom_write(fd, &versioninfo) == -1)
            return -1;

        bzero(&versioninfo, sizeof(versioninfo));

        //读取软件版本信息
        versioninfo.cmd = SVERSION;
        if (eeprom_read(fd, &versioninfo) == -1)
                return -1;
        printf("sversion = %s\n", versioninfo.version);
        
        //读取硬件版本信息
        versioninfo.cmd = HVERSION;
        if (eeprom_read(fd, &versioninfo) == -1)
                return -1;
        printf("hversion = %s\n", versioninfo.version);
        eeprom_close(fd);
	return 0;
}

