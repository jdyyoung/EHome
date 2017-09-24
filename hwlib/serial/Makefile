LIBTARGET=libserial.so
#READAPPTARGET=seriallib_test_read
#WRITEAPPTARGET=seriallib_test_write
ZIGBEEAPPTARGET=seriallib_test_zigbee

LIBOBJ=serial.o
#READAPPOBJ=seriallib_test_read.o
#WRITEAPPOBJ=seriallib_test_write.o
ZIGBEEAPPOBJ=seriallib_test_zigbee.o

CC=arm-linux-gcc
CP=cp
CFLAGS=-shared -fpic  
LDFLAGS=-L. -lserial

LIBINSTALLPATH=/opt/rootfs/home/applib
APPINSTALLPATH=/opt/rootfs/home/apptest/

all: $(LIBTARGET) $(ZIGBEEAPPTARGET) 

$(LIBTARGET) : $(LIBOBJ) 
	$(CC) $(CFLAGS) -o $(LIBTARGET) $(LIBOBJ) 
	$(CP) $(LIBTARGET) $(LIBINSTALLPATH)
$(ZIGBEEAPPTARGET) : $(ZIGBEEAPPOBJ)
	$(CC) -o $(ZIGBEEAPPTARGET) $(ZIGBEEAPPOBJ) $(LDFLAGS)
	$(CP) $(ZIGBEEAPPTARGET) $(APPINSTALLPATH)

clean:
	rm $(ZIGBEEAPPTARGET)  $(LIBTARGET) $(ZIGBEEAPPOBJ) $(LIBOBJ)

