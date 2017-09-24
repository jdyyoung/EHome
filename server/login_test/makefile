#1.交叉编译器
#CC=arm-linux-gcc
CC=gcc

#2.最终生成的可执行文件
BIN1=user_info
BIN2=login_varify_test

#3.编译参数
CFLAGS=-Wall
#LDFLAGS=-I ./include -L ./lib
LIBS=-lcrypt

#4.源文件
SOURCE1=crt_user_info.c
SOURCE2=login_varify_test.c

c:$(BIN1)
$(BIN1):$(SOURCE1)
	$(CC) $(CFLAGS) $(SOURCE1) $(LIBS) -o $(BIN1)

l:$(BIN2)
$(BIN2):$(SOURCE2)
	$(CC) $(CFLAGS) $(SOURCE2) $(LIBS) -o $(BIN2)

clean:
	rm -rf $(BIN1) $(BIN2)
