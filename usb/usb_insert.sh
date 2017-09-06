#!/bin/sh
echo $1 > /dev/console

mount -t vfat -o utf8=1 $1 /mnt/usb
