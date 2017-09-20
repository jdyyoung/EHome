
crt_user_info.c源文件创建了一个测试账户信息的验证文件passwd，保存路径为：/opt/rootfs/home/ehome/etc/passwd；此验证文件类似一个数据库，包含登录帐号名，密码，AES-128加密算法的密钥，密码加密后密文;验证文件passwd为了之后PC端登录服务器运行测试所用的。

login_varify_test.c源文件为模拟登录，测试验证文件passwd的有效性。

makefile:编译crt_user_info.c与login_varify_test.c生成对应可执行文件

login_test.sh：最终的运行脚本，在该文件夹目录下运行该脚本就可完成测试,当终端打印“LOGIN_SUCCESS!”表明验证文件passwd有效，否则无效。


