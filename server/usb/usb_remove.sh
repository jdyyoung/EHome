#!/bin/sh
echo $1 > /dev/console
sync
umount  /mnt/usb
