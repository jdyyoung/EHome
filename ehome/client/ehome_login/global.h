#ifndef _GLOBAL_H
#define _GLOBAL_H

struct version_info
{
    unsigned char s_version[10];
    unsigned char h_version[10];
};

extern struct version_info v_info;
extern char ip_addr[64];

#endif //_GLOBAL_H
