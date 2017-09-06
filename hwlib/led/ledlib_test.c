#include "led.h"

int main(int argc, char *argv[])
{
	int fd;
        struct led_cmd ledctrl;

	if (argc != 3) {
		printf("usage:\n %s <on|off> <1|2>\n", argv[0]);
		return -1;
	}
	
	fd = led_open();
	if (fd < 0) 
		return -1;

	ledctrl.whichled = strtoul(argv[2], NULL, 0);
	
	if (!strcmp(argv[1], "on")) { 
	    ledctrl.cmd = 1;	
        } else {
	    ledctrl.cmd = 0;	
        }
       
        if (led_config(fd, &ledctrl) == -1)
            return -1;
	
        led_close(fd);

	return 0;
}

