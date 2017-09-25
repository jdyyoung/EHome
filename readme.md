这是一个智能家居的项目，项目综合利用了C语言、C++、zigbee、Qt、shell脚本、makefile、Linux驱动开发、Linux系统编程等嵌入式技术，实现了智能家居的雏形，项目以Cortex-A8开发板作为整个系统的核心模块，控制整个系统的运行。

### **主要功能为：**

​	1.开发本服务器端的实现，运行开发板服务器，服务器运行指示的Led灯点亮

​	2.运行PC客户端软件，输入账号、密码、IP来登录已经在开发板运行服务器，验证通过则进入主界面；

​	3.进入主界面自动显示存储在EEPROM的软硬件版本信息

​	4.在主界面点击相关按钮，服务器利用ZigBee串口透传，实现远程无线开关灯

​	5.在主界面点击相关按钮可获取即时温度

​	6.插入有升级文件的U盘，在主界面点击相关镜像的升级按钮，升级相关系统

​	7.点击主界面相关按钮，获取显示硬件系统信息

### **硬件及开发环境相关**：

​	笔记本电脑，Cortex-A8的S5PV210开发板，CC2530的ZigBee模块一对，网线一条，USB转串口线，USB线若干

### **实现大致过程：**

​	1.搭建开发环境：在虚拟机下的Ubuntu 12.04建立交叉编译链，tftp服务器安装与测试，nfs服务器安装与测试，uboot移植及启动参数设置，内核配置裁剪编译镜像并移植，Busybox编译生成根文件系统。

​	2.编写硬件驱动模块，期间需要阅读芯片手册，阅读电气原理图。

​	3.编写硬件动态库及测试用例，动态库测试会调用底层驱动模块，期间还可能需要用到相关软件工具及脚本等

​	4.编写Zigbe模块的代码，实现串口透传功能，从而实现远程无线开关灯，并连接开发板进行测试

​	5.根据硬件动态库实现服务器的代码，并编写测试文件进行测试

​	6.使用Qt4编写客户端代码，会调用部分动态库，并与服务器联调

​	7.使用工具软件生成相关镜像文件，修改内核源码，实现软件部署

### **主要文件/夹介绍**：

​	**drivers文件夹**：放置驱动模块源码及makefile文件，可参考具体文件下readme.md的介绍

​	**hwlib文件夹**：放置生成硬件动态库源码，测试用例源码，及对应makefile文件，可参考具体文件下readme.md的介绍

​	**server文件**：服务器端的源码，生成服务器可执行文件所需动态库，头文件及makefile文件，可参考具体文件下readme.md的介绍

​	**client文件夹**：创建PC客户端的Qt源码，及界面所需动态库，头文件等可参考具体文件下readme.md的介绍

​	**tools文件夹**：存放着各种源码压缩包及软件，将会被裁剪、交叉编译、移植到开发板上，可阅读具体文件下readme.md;（文件有点大百度云盘下载）

​	**ehome_pc_win文件夹**:存放着项目在win系统的pc端用到的工具软件，驱动等，uboot的镜像放在此文件夹下，可阅读具体文件下readme.md；（文件有点大百度云盘下载）

​	**img文件夹**：调试时的zImage、rootfs压缩包、用户数据软件压缩包；内核修改后的平台源码，最后部署的镜像文件等

​	**file_tree.txt文件**: 项目的树状目录

**客户端界面截图：**

![ehome00.JPG](https://github.com/jdyyoung/EHome/blob/master/ui_screenshot/ehome00.JPG?raw=true)

![ehome01.JPG](https://github.com/jdyyoung/EHome/blob/master/ui_screenshot/ehome01.JPG?raw=true)

![ehome02.JPG](https://github.com/jdyyoung/EHome/blob/master/ui_screenshot/ehome02.JPG?raw=true)

![ehome03.JPG](https://github.com/jdyyoung/EHome/blob/master/ui_screenshot/ehome03.JPG?raw=true)

![ehome04.JPG](https://github.com/jdyyoung/EHome/blob/master/ui_screenshot/ehome04.JPG?raw=true)

![ehome05.JPG](https://github.com/jdyyoung/EHome/blob/master/ui_screenshot/ehome05.JPG?raw=true)

![ehome06.JPG](https://github.com/jdyyoung/EHome/blob/master/ui_screenshot/ehome06.JPG?raw=true)



***资源：***

ehome_pc_win百度云链接：链接：http://pan.baidu.com/s/1dE5M1KP 密码：k1sy

tools百度云链接：链接：http://pan.baidu.com/s/1kUNRg71 密码：gq4e

虚拟机VMware，Ubuntu12.04 百度云链接：链接：http://pan.baidu.com/s/1bp94kMj 密码：0jdv

ZigBee资料的百度云链接：链接：http://pan.baidu.com/s/1nv9POnB 密码：ge1c





