#include "update.h"

int main(int argc, char *argv[])
{
        if (argc != 2) {
                printf("usage:\n %s <zImage|rootfs|userdata>\n", argv[0]);
                return -1;
        }

        if (!strcmp(argv[1], "zImage")) 
        {
            update_sw("/mnt/usb/zImage");
            printf("update success!\n");
        }

        return 0;
}
