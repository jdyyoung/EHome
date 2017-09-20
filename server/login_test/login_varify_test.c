#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<crypt.h>
#include<stdlib.h>

#define _XOPEN_SOURCE

 void login_verify(void);

#define PASSWD_FILE "/opt/rootfs/home/ehome/etc/passwd"

int main()
{
    login_verify();
    return 0;
}

void login_verify()
{
    char nm[64];
    char salt[17];
    char dcrypt[128];
    int size;
    int i=0;
    char tmp;

    int fd=open(PASSWD_FILE,O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        exit(-1);
    }

    /*read username*/
    while((size=read(fd,&tmp,1))>0)
    {
        if(tmp == '\0')
        {
            nm[i]=tmp;
            break;
        }
        else
        {
            nm[i++]=tmp;
        }
    }
    printf("nm=%s\n",nm);

    /*read salt*/
    i=0;
    while((size=read(fd,&tmp,1))>0)
    {
        if(tmp == '\0')
        {
            salt[i]=tmp;
            break;
        }
        else
        {
            salt[i++]=tmp;

        }
    }
    printf("salt=%s\n",salt);

    i=0;
    while((size=read(fd,&tmp,1))>0)
    {
        if(tmp == '\0')
        {
            dcrypt[i]=tmp;
            break;
        }
        else
        {
            dcrypt[i++]=tmp;
        }
    }
    printf("dcrypt=%s\n",dcrypt);
    close(fd);

    /*encrypt info->pwd with salt ->c*/
    char* c=crypt("ehome123456",salt);

    if(strncmp(c,dcrypt,98))
    {
        printf("LOGIN_FAILD!\n");
        return;
    }
    else
    {
        printf("LOGIN_SUCCESS!\n");
    }
    return;
}


