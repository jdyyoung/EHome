#include "udp.h"

int main(void)
{
        char *buf = "hello,world";
        char buf1[1024] = {0};
        int ret;

        ret = udp_init(SERVER, "192.168.1.110", 8888);
        if (ret == -1)
                return -1;

        ret = udp_read(SERVER, buf1, 1024);
        if (ret == -1)
                return -1;
        printf("read %d bytes, msg is %s\n", ret, buf1);
        
        udp_write(SERVER, buf, strlen(buf));
        if (ret == -1)
                return -1;
        printf("write %d bytes\n", ret);
        
        udp_exit();

        return 0;
}
