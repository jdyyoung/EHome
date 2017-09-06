#include "udp.h"
static struct sockaddr_in srcaddr; //源地址
static struct sockaddr_in destaddr; //目标地址
static int sfd; //套接字文件描述符
static int size;

int udp_init(unsigned char isserver, char *destip, int port)
{

        if (destip == NULL) {
                pr_debug("dest ip is invalid\n");
                return -1;
        }
        
        if ((sfd = socket(PF_INET,SOCK_DGRAM,0)) < 0) {
                pr_debug("create socket error\n");
                return -1;
        }

        size = sizeof(struct sockaddr_in);

        pr_debug("create socket successfully!\n");

        srcaddr.sin_family      = AF_INET;         
        srcaddr.sin_addr.s_addr = inet_addr(destip);       
        srcaddr.sin_port        = htons(port);

        if (isserver == SERVER) {
                if(bind(sfd, (struct sockaddr *)&srcaddr, sizeof(struct sockaddr)) < 0) {
                        pr_debug("bind error\n");
                        return -1;
                }
                pr_debug("server bind  successfully!\n");
        }
        return sfd;
}

void udp_exit(void)
{
        pr_debug("close socket!\n");
        close(sfd);
}

int udp_write(unsigned char isserver, char *buf, int len)
{
        int ret;

        if (buf == NULL) {
                pr_debug("msg buf is invalid.\n");
                return -1;
        }
        
        if (len < 0) {
                pr_debug("msg led is invalid.\n");
                return -1;
        }

        if (isserver == CLIENT) { //客户端发送
                if ((ret = sendto(sfd, buf, len, 0, 
                                (struct sockaddr*)&srcaddr, size)) < 0) {
                        pr_debug("send error!\n");
                        return -1;
                }
        } else { //服务器发送
                if ((ret = sendto(sfd, buf, len, 0, 
                                (struct sockaddr*)&destaddr, size)) < 0) {
                        pr_debug("send error!\n");
                        return -1;
                }
        }
        pr_debug("write udp data successfully!\n");
        return ret;
}

int udp_read(unsigned char isserver, char *buf, int len)
{
        int ret;

        if (buf == NULL) {
                pr_debug("msg buf is invalid.\n");
                return -1;
        }
        
        if (len < 0) {
                pr_debug("msg led is invalid.\n");
                return -1;
        }
        
        if ((ret = recvfrom(sfd, buf, len, 0, 
                        (struct sockaddr *)&destaddr, &size)) < 0) {
                pr_debug("recvfrom error!~\n");
                return -1;
        }

        pr_debug("udp read data successfully!\n");
        return ret;
}

