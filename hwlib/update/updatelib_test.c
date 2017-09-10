#include "update.h"

int main(int argc, char *argv[])
{
        if (argc != 2) {
                printf("usage:\n %s <zImage|rootfs|userdata>\n", argv[0]);
                return -1;
        }

        if (!strcmp(argv[1], "zImage")) 
                update_kernel(ZIMAGE_PATH);
                //update_kernel("/mnt/usb/zImage");
        else if (!strcmp(argv[1], "rootfs"))
                update_rootfs(ROOTFS_PATH);
        else if (!strcmp(argv[1], "userdata"))
                update_userdata(USERDATA_PATH);

        return 0;
}
