uboot_TQ210_1.3.4_V2.0.bin TQ210的uboot镜像默认为七寸屏（可设置使其支持其它类型的LCD），支持WinCE的烧写。
20150716：全面支持SD卡、SDHC卡自动烧写。添加tfyaffs功能，突破内存限制，可通过tftp下载并烧写大于内存容量的yaffs文件系统（上限为nand的文件系统分区大小）。
