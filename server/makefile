CC=arm-linux-gcc
BIN1=eh_server
BIN2=server_rs
CFLAGS= -Wall
LDFLAGS=-I ./include -L ./lib
LIBS=-ludp -lcrypt -lserial -lds18b20 -leeprom -lupdate
SERVER_SOURCE=device.c eh_server.c
STATUS_SOURCE=server_rs.c

$(BIN1):$(SERVER_SOURCE)
	$(CC) $(CFLAGS) $(SERVER_SOURCE) $(LIBS) $(LDFLAGS) -o $(BIN1)
	$(CC) $(CFLAGS) $(STATUS_SOURCE) -o $(BIN2)
	cp $(BIN1) /opt/rootfs/home/
	cp $(BIN2) /opt/rootfs/home/

.PHONY :clean
clean:
	rm -rf $(BIN1) $(BIN2)
