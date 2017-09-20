CC=arm-linux-gcc
BIN=eh_server
CFLAGS= -Wall
LDFLAGS=-I ./include -L ./lib
LIBS=-ludp -lcrypt -lserial -lds18b20 -leeprom -lupdate
SOURCE=*.c

$(BIN):$(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) $(LIBS) $(LDFLAGS) -o $(BIN)

clean:
	rm -rf $(BIN)
