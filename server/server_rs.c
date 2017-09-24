#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    //int res = system("ls -l");
    //int res = system("cal");
    while(1)
    {
        int res = system("./shell.sh");
        if(-1 == res)
        {
            perror("system"),exit(-1);
        }
    }
    printf("程序执行完毕\n");
    return 0;
}
