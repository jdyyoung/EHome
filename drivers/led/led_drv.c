#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include<linux/miscdevice.h>

#define LED_ON  0x100001
#define LED_OFF 0x100002
/*
static int major;
static struct cdev led_cdev;
static struct class *cls;
*/
static void *gpio_base; //gpio寄存器的虚拟起始地址
static unsigned long *gpiocon; //配置寄存器的虚拟地址，
static unsigned long *gpiodata;//数据寄存器的虚拟地址

static int led_ioctl(struct file *file,
                        unsigned int cmd,
                        unsigned long arg)
{
    unsigned char index; 
    //1.获取用户操作的灯的编号
    copy_from_user(&index, (int *)arg, 1);

    //2.解析命令
    switch(cmd) {
        case LED_ON:
                    if (index == 1) 
                        *gpiodata |= (1 << 3);
                    else if (index == 2)
                        *gpiodata |= (1 << 4);
                break;
        case LED_OFF:
                    if (index == 1) 
                        *gpiodata &= ~(1 << 3);
                    else if (index == 2)
                        *gpiodata &= ~(1 << 4);
                break;
        default:
                return -1;
    }
    //添加打印调试信息
    printk("GPIOCON = %#x, GPIODATA = %#x\n", 
                        *gpiocon, *gpiodata);
    return 0;
}

static struct file_operations led_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = led_ioctl
};

static struct miscdevice led_misc={
    .minor=MISC_DYNAMIC_MINOR,
    .name="myled",
    .fops=&led_fops
};

static int led_init(void)
{
    misc_register(&led_misc);
    /*
    dev_t dev;

    //1.申请设备号
    alloc_chrdev_region(&dev, 0, 1, "leds");
    major = MAJOR(dev);

    //2.初始化注册cdev
    cdev_init(&led_cdev, &led_fops);
    cdev_add(&led_cdev, dev, 1);

    //3.自动创建设备节点
    cls = class_create(THIS_MODULE, "leds");
    device_create(cls, NULL, dev, NULL, "myled");
    printk("chuangjian mylecd success");
*/
    //4.地址映射
    gpio_base = ioremap(0xe0200060, 8); 
    //4.1获取配置寄存器和数据寄存器对应的虚拟地址
    gpiocon = (unsigned long *)gpio_base;
    gpiodata = (unsigned long *)(gpio_base + 0x04);

    //5.配置GPIO为输出口，并且输出0
    *gpiocon &= ~((0xf << 12) | (0xf << 16));
    *gpiocon |= ((1 << 12) | (1 << 16));

    *gpiodata &= ~((1 << 3) | (1 << 4));
    return 0;
}

static void led_exit(void)
{
    misc_deregister(&led_misc);
   // dev_t dev = MKDEV(major, 0);

    //1.配置GPIO输出为0
    *gpiodata &= ~((1 << 3) | (1 << 4));
    
    //2.解除地址映射
    iounmap(gpio_base);
/*
    //3.删除设备节点
    device_destroy(cls, dev);
    class_destroy(cls);

    //4.删除cdev
    cdev_del(&led_cdev);

    //5.释放设备号
    unregister_chrdev_region(dev, 1);
    */
}
module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");

