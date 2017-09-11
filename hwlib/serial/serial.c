#include "serial.h"

int serial_open(void)
{
	int fd = open(SERIAL_DEVFILE_NAME, O_RDWR|O_NOCTTY);
	if (fd < 0) {
		pr_debug("open serial device failed.\n");
        perror("open");
		return -1;	
	}
	pr_debug("open serial device successfully!\n");
        if(isatty(STDIN_FILENO)==0)
        {
                pr_debug("standard input is not a terminal device\n");
        }
        return fd;
}

void serial_close(int fd) 
{
	pr_debug("close serial device...\n");
	close(fd);
}


/*Linux内核中,struct ktermios结构的c_cflags共有5个位用来标注波特率,其中位CBAUDEX表明使用的是POSIX标准波特率还是扩展波特率,
    POSIX规定了16个标准波特率,为B0,B50,B75,B110,B134,B150,B200,B300,B600,B1200,B1800,B2400,B4800,B9600,B19200,B38400*/
static int speed_arr[] = {B115200,B38400,B19200,B9600,B4800,B2400,B1200,B300};
static int bps_arr[]  = {115200,38400,19200,9600,4800,2400,1200,300};

int serial_config(int fd, struct serial_cmd *serialctrl) 
{
        int i;
        int ret;
        int status;
        struct termios opt;

        if (fd < 0) {
                pr_debug("fd is invalid.\n");
                return -1;
        }

        if (serialctrl == NULL) {
                pr_debug("serialctrl is invalid.\n");
                return -1;
        }

        /*配置波特率*/
        if (tcgetattr(fd,&opt) != 0) //获取串口默认属性 
        {
                pr_debug("Get Serial Options Error");
                return(-1);
        }
        for(i=0;i<sizeof(speed_arr)/sizeof(int);i++) {
                if(serialctrl->bps==bps_arr[i])
                {
                        tcflush(fd,TCIOFLUSH);
                        cfsetispeed(&opt,speed_arr[i]); //配置输入波特率
                        cfsetospeed(&opt,speed_arr[i]); //配置输出波特率
                        status = tcsetattr(fd,TCSANOW,&opt); //设置到硬件寄存器上
                        if(status != 0)
                        {
                                pr_debug("Set Serial Bps Error");
                                return -1;
                        }
                }
                tcflush(fd,TCIOFLUSH); //刷新
        }
        pr_debug("config serial %d bps successfully!\n", serialctrl->bps);
        /*配置数据位，停止位，奇偶校验位*/
        if(tcgetattr(fd,&opt) != 0)
        {
                pr_debug("Get Serial Options Error");
                return(-1);
        }
        opt.c_cflag &= ~CSIZE;
        //set data bit length
        switch (serialctrl->databits) /*设置数据位数*/
        {
                case 7:
                        opt.c_cflag |= CS7;
                        break;
                case 8:
                        opt.c_cflag |= CS8;
                        break;
                default:
                        pr_debug("Unsupported data size!\n");
                        return (-1);
        }
        pr_debug("config serial %d databits successfully!\n", serialctrl->databits);
        //set parity bit mode
        switch (serialctrl->parity)
        {
                case 'n':
                case 'N':
                        opt.c_cflag &= ~PARENB;		/* Clear parity enable */
                        opt.c_iflag &= ~INPCK;			/* Disable parity checking */
                        break;
                case 'o':
                case 'O':
                        opt.c_cflag |= (PARODD|PARENB);	/* 设置为奇效验*/ 
                        opt.c_iflag |= INPCK;			/* Enable parity checking */
                        break;
                case 'e':
                case 'E':
                        opt.c_cflag |= PARENB;     		/* Enable parity */
                        opt.c_cflag &= ~PARODD;   		/* 转换为偶效验*/  
                        opt.c_iflag |= INPCK;      		/* Enable parity checking */ 
                        break; 
                case 's': 
                case 'S':  				/*as no parity*/
                        opt.c_cflag &= ~PARENB;
                        opt.c_cflag &= ~CSTOPB;
                        break;
                default:
                        pr_debug("Unsupported parity\n");
                        return (-1);
        }
        pr_debug("config serial %c databits successfully!\n", serialctrl->parity);
        //set stop bit length
        switch (serialctrl->stopbits)
        {
                case 1:
                        opt.c_cflag &= ~CSTOPB;
                        break;
                case 2:
                        opt.c_cflag |= CSTOPB;
                        break;
                default:
                        pr_debug("Unsupported stop bits\n");
                        return (-1);
        }
        pr_debug("config serial %d stopbits successfully!\n", serialctrl->stopbits);
        //set input parity option
        //if (parity != 'n')
        //{
        //opt.c_iflag |= INPCK;
        //}

        opt.c_lflag &= ~(ICANON|ECHO|ECHOE|ISIG);
        opt.c_oflag &= ~OPOST;
        opt.c_cflag |= (CLOCAL | CREAD);   

        opt.c_cc[VTIME] = 0; 
        opt.c_cc[VMIN] = 0;

        tcflush(fd,TCIFLUSH);			//Update the options and do it NOW
        if (tcsetattr(fd,TCSANOW,&opt) != 0)
        {
                pr_debug("Set Serial Options Error");
                return (-1);
        }

        pr_debug("config serial device successfully!\n");
        return 0;
}

int serial_read(int fd, char *buf, int size)
{
        int ret;
        unsigned long data;

	if (fd < 0) {
		pr_debug("fd is invalid.\n");
		return -1;
	}

        if (buf == NULL) {
            pr_debug("buf is invalid.\n");
            return -1;
        }
        
        if (size < 0) {
            pr_debug("size is invalid.\n");
            return -1;
        }

        ret = read(fd, buf, size);
        if (ret == -1) {
                pr_debug("read serial device failed.\n");
                return -1;
        }

        return 0;
}

int serial_write(int fd, char *buf, int size)
{
        int ret;
        unsigned long data;

	if (fd < 0) {
		pr_debug("fd is invalid.\n");
		return -1;
	}

        if (buf == NULL) {
            pr_debug("buf is invalid.\n");
            return -1;
        }
        
        if (size < 0) {
            pr_debug("size is invalid.\n");
            return -1;
        }

        ret = write(fd, buf, size);
        if (ret == -1) {
                pr_debug("write serial device failed.\n");
                return -1;
        }

        return 0;
}

