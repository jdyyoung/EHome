#include "eeprom.h"

struct eeprom_data {
        unsigned char addr;
        unsigned char data;
        unsigned char reserved[2];
};

int eeprom_open(void)
{
	int fd = open(EEPROM_DEVFILE_NAME, O_RDWR);
	if (fd < 0) {
		pr_debug("open eeprom device failed.\n");
		return -1;	
	}
	pr_debug("open eeprom device successfully!\n");
	return fd;
}

void eeprom_close(int fd) 
{
	pr_debug("close eeprom device...\n");
	close(fd);
}

int eeprom_write(int fd, struct eeprom_cmd *pv) 
{
	int ret;
        int i;
        struct eeprom_data eeprominfo;

	if (fd < 0) {
		pr_debug("fd is invalid.\n");
		return -1;
	}

        if (pv == NULL) {
            pr_debug("version is invalid.\n");
            return -1;
        }

        if (pv->cmd != SVERSION && pv->cmd != HVERSION) {
                pr_debug("version cmd is invalid\n");
                return -1;
        }
        
        //写入软件版本
        if (pv->cmd == SVERSION) {
                for (i = 0; i < VERSION_LEN; i++) 
                {
                        eeprominfo.addr = i + EEPROM_SVERSION_OFFSET;
                        eeprominfo.data = pv->version[i];
                        ret = ioctl(fd, EEPROM_WRITE_VERSION, &eeprominfo);
                        if (ret == -1) {
                                perror("ioctl");
                                pr_debug("write software version failed.\n");
                                return -1;
                        }
                        usleep(8000);
                }
        }
        
        //写入硬件版本
        if (pv->cmd == HVERSION) {
                for (i = 0; i < VERSION_LEN; i++) 
                {
                        eeprominfo.addr = i + EEPROM_HVERSION_OFFFSET;
                        eeprominfo.data = pv->version[i];
                        ret = ioctl(fd, EEPROM_WRITE_VERSION, &eeprominfo);
                        if (ret == -1) {
                                pr_debug("write hardware version failed.\n");
                                return -1;
                        }
                        usleep(5000);
                }
        }
	pr_debug("write %s version successfully!\n", 
                        pv->cmd == SVERSION ? "software":"hardware");
	return ret;
}

int eeprom_read(int fd, struct eeprom_cmd *pv)
{
	int ret;
        int i;
        struct eeprom_data eeprominfo;

	if (fd < 0) {
		pr_debug("fd is invalid.\n");
		return -1;
	}

        if (pv == NULL) {
            pr_debug("version is invalid.\n");
            return -1;
        }

        if (pv->cmd != SVERSION && pv->cmd != HVERSION) {
                pr_debug("version cmd is invalid\n");
                return -1;
        }
        
        //读取软件版本
        if (pv->cmd == SVERSION) {
                for (i = 0; i < VERSION_LEN; i++) {
                        eeprominfo.addr = i + EEPROM_SVERSION_OFFSET;
                        ret = ioctl(fd, EEPROM_READ_VERSION, &eeprominfo);
                        if (ret == -1) {
                                pr_debug("read software version failed.\n");
                                return -1;
                        }
                        pv->version[i] = eeprominfo.data;
                }
        }
        
        //读取硬件版本
        if (pv->cmd == HVERSION) {
                for (i = 0; i < VERSION_LEN; i++) {
                        eeprominfo.addr = i + EEPROM_HVERSION_OFFFSET;
                        ret = ioctl(fd, EEPROM_READ_VERSION, &eeprominfo);
                        if (ret == -1) {
                                pr_debug("read hardware version failed.\n");
                                return -1;
                        }
                        pv->version[i] = eeprominfo.data;
                }
        }
	pr_debug("read %s version successfully!\n", 
                        pv->cmd == SVERSION ? "software":"hardware");

        return ret;
}
