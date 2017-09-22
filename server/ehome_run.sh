#如果没加载模块，执行加载
var=`lsmod | grep at24c02_drv`
#echo $var
if [ "$var" == ''  ];then
    insmod /home/drivers/at24c02_drv.ko
else
    echo "at24c02_drv.ko is inserted!"
fi

var=`lsmod | grep ds18b20_drv`
#echo $var
if [ "$var" == '' ];then
    insmod /home/drivers/ds18b20_drv.ko 
else
    echo "ds18b20_drv.ko is inserted!"
fi
var=`ps | grep eh_server | grep -v grep`
if [ "$var" == '' ];then
    /home/eh_server&
else
    echo "eh_server is running!"
fi
