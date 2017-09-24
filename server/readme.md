device.c      eh_server.c  lib         makefile   readme.md~   shell.sh
ehome_run.sh  include      login_test  readme.md  server_rs.c  usb

device.c:生成开发板服务器可执行文件的子程序

eh_server.c:生成开发板服务器可执行文件的主程序

include:文件夹下存放生成开发板服务器可执行文件的头文件

lib：文件夹下存放生成开发板服务器可执行文件需要调用的动态库

login_test：文件夹下存放用于创建passwd文件的源程序与测试脚本，passwd文件用于测试时，PC客户端账户登录信息的验证，如同数据库的账户登录验证文件

server_rs.c与shell.sh:两个文件配合实现服务器进程的运行状态指示，服务器进程一运行led灯亮，服务器进程终止led灯灭；server running status 

ehome_run.sh：服务器运行的脚本

makefile:生成可执行文件eh_server与server_rs,并把它们复制到根文件系统相关位置，同时也把ehome_run.sh复制过去


