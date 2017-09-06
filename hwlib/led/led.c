#include "led.h"

int led_open(void)
{
	int fd = open(LED_DEVFILE_NAME, O_RDWR);
	if (fd < 0) {
		pr_debug("open led device failed.\n");
		return -1;	
	}
	pr_debug("open led device successfully!\n");
	return fd;
}

void led_close(int fd) 
{
	pr_debug("close led device...\n");
	close(fd);
}

int led_config(int fd, struct led_cmd *ledctrl) 
{
	int ret;

	if (fd < 0) {
		pr_debug("fd is invalid.\n");
		return -1;
	}

        if (ledctrl == NULL) {
            pr_debug("ledctrl is invalid.\n");
            return -1;
        }

        if (ledctrl->whichled != 1 && ledctrl->whichled != 2) {
		pr_debug("whichled is invalid.\n");
		pr_debug("whichled value must be 1 or 2\n");
		return -1;
	}

	if (ledctrl->cmd != 1 && ledctrl->cmd != 0) {
		pr_debug("cmd is invalid.\n");
		pr_debug("cmd value must be 1 or 0\n");
		return -1;
	}

	if (ledctrl->cmd == 1)	
		ret = ioctl(fd, LED_ON, &ledctrl->whichled);
	else 
		ret = ioctl(fd, LED_OFF, &ledctrl->whichled);
	if (ret == -1) {
		pr_debug("ioctl led device failed.\n");
	}
	pr_debug("ioctl led device successfully!\n");
	return ret;
}
