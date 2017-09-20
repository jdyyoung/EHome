#ifndef _LOG_H
#define _LOG_H

#define LOGIN_SUCCESS 1
#define LOGIN_FAILD   0

struct passwd_info
{
    char user[64];
    char oldpwd[64];
    char pwd[64];
};

#endif
