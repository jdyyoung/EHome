#include "udp.h"

int main(void)
{
        char *buf = "why not?";
        char buf1[1024] = {0};
        int ret;

        ret = udp_init(CLIENT, "192.168.1.6", 8888);
        if (ret == -1)
                return -1;
 
        udp_write(CLIENT, buf, strlen(buf));
        if (ret == -1)
                return -1;
        printf("write %d bytes\n", ret);
        
        ret = udp_read(CLIENT, buf1, 1024);
        if (ret == -1)
                return -1;
        printf("read %d bytes, msg is %s\n", ret, buf1);

        udp_exit();

        return 0;
}
