#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<crypt.h>
#include<stdio.h>

#define _XOPEN_SOURCE

#define PASSWD_FILE "/opt/rootfs/home/ehome/etc/passwd"
//#define PASSWD_FILE "/home/ehome/etc/passwd"

//
int main()
{
    char username[]="jdyyoung";
    char password[]="ehome123456";//关于字符串赋值？
    char salt[]="1234567890qazwsx";
    char *dcrypt;
    dcrypt = crypt(password,salt);

    //打开文件,文件存在则打开，文件不存在则创建
    int fd = open(PASSWD_FILE,O_RDWR | O_CREAT,0644);
    if(fd == -1)
    {
        perror("open");
        exit(-1);
    }
    //向文件写入用户名
    int ret = write(fd,username,sizeof(username));//函数strlen
    if(ret == -1)
    {
        perror("write");
        exit(-1);
    }

    //向文件写入salt
    ret=write(fd,salt,sizeof(salt));
    if(ret == -1)
    {
        perror("write");
        exit(-1);
    }

    //向文件写入加密后密文
    ret=write(fd,dcrypt,strlen(dcrypt)+1);

    if(ret == -1)
    {
        perror("write");
        exit(-1);
    }
    
    close(fd);
    return 0;
}


