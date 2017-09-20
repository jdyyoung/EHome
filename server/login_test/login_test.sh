#!/bin/bash

#如果/opt/rootfs/home/ehome/etc/passwd 文件存在则删除该文件
#执行make clean
#执行make c，生成创建/opt/rootfs/home/ehome/etc/passwd文件的可执行文件
testfile=/opt/rootfs/home/ehome/etc/passwd
a="make clean"
if [ -f "$testfile" ];then
    rm $testfile
fi
make clean
make c
sleep 1s
user_info
make l
sleep 1s
login_varify_test
