#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <asm/uaccess.h>
#include <linux/miscdevice.h>
#include <asm/gpio.h>
#include <plat/gpio-cfg.h>
#include <linux/sched.h>

#define SKIP_ROM        0xcc
#define COVERTT         0x44
#define READ_MEM        0xbe

/* 参看文档P16,注意写1和0的时隙要求*/
/*11001100*/
static void ds18b20_write8(unsigned char data)
{
        int i;

        local_irq_disable();
       for (i = 0; i < 8; i++) {
                if ((data & 0x1) == 1) {
                        gpio_direction_output(S5PV210_GPH1(0), 0);
                        udelay(3);
                        gpio_direction_output(S5PV210_GPH1(0), 1);
                        udelay(80);
                } else {
                        gpio_direction_output(S5PV210_GPH1(0), 0);
                        udelay(80);
                        gpio_direction_output(S5PV210_GPH1(0), 1);
                        udelay(3);
                }
                data >>= 1;
       }
    local_irq_enable();
}

/* 参看文档P16,注意读1和0的时隙要求*/
static unsigned char ds18b20_read8(void)
{
        int i;
        unsigned char bit;
        unsigned char data = 0;

        local_irq_disable();
        for (i = 0; i < 8; i++) {
                gpio_direction_output(S5PV210_GPH1(0), 0);
                udelay(2);
                gpio_direction_input(S5PV210_GPH1(0));
                bit = gpio_get_value(S5PV210_GPH1(0));
                data |= (bit << i);
                udelay(60);
        }
    local_irq_enable();
        return data;
}

/* 参看文档P15*/
static void ds18b20_reset(void)
{
        unsigned char ret;

        gpio_direction_output(S5PV210_GPH1(0), 0);
        udelay(500);
        gpio_direction_output(S5PV210_GPH1(0), 1);
        udelay(30);
        gpio_direction_input(S5PV210_GPH1(0));
        ret = gpio_get_value(S5PV210_GPH1(0));
        udelay(500);
        if (ret == 0) {
                printk("reset ok.\n");
        } else {
                printk("reset failed.\n");
        }
}

static ssize_t ds18b20_read(struct file *file, char *buf, size_t count, loff_t *pos)
{
        unsigned char h8, l8;
        int temp = 0;

        ds18b20_reset();
        ds18b20_write8(SKIP_ROM);
        ds18b20_write8(COVERTT);

        //msleep(750);
        mdelay(750);

        ds18b20_reset();
        ds18b20_write8(SKIP_ROM);
        ds18b20_write8(READ_MEM);
        
        l8 = ds18b20_read8();
        h8 = ds18b20_read8();

        temp = (h8 << 8) | l8; //0x191

        temp *= 625; //扩大10000倍

        if(copy_to_user(buf, &temp, 4))
		return -EFAULT;
        return count;
}

static struct file_operations ds18b20_fops = {
        .owner  = THIS_MODULE,
        .read    = ds18b20_read,
};

static struct miscdevice ds18b20_miscdev = {
        .minor  = MISC_DYNAMIC_MINOR,       
        .name   = "ds18b20",
        .fops   = &ds18b20_fops,
};

static int ds18b20_init(void)
{
        gpio_request(S5PV210_GPH1(0), "GPH1_0");
        misc_register(&ds18b20_miscdev);
        return 0;
}

static void ds18b20_exit(void)
{
        misc_deregister(&ds18b20_miscdev);
        gpio_free(S5PV210_GPH1(0));
}

module_init(ds18b20_init);
module_exit(ds18b20_exit);
MODULE_LICENSE("GPL");
