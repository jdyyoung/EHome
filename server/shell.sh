#!/bin/sh

var=`ps | grep eh_server | grep -v grep`
if [ "$?" != "0" ];then
    /home/apptest/ledlib_test off 1
    killall -9 server_rs
fi

