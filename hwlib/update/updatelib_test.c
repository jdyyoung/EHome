#include "update.h"

int main(int argc, char *argv[])
{
        if (argc != 2) {
                printf("usage:\n %s <zImage|rootfs|userdata>\n", argv[0]);
                return -1;
        }

        if (!strcmp(argv[1], "zImage")) 
                update_kernel(argv[1]);
        else if (!strcmp(argv[1], "rootfs"))
                update_rootfs(argv[1]);
        else if (!strcmp(argv[1], "userdata"))
                update_userdata(argv[1]);

        return 0;
}
