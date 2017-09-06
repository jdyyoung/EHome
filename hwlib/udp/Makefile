LIBTARGET=libudp.so
APPTARGET=udplib_test
APPCLIENT=udplib_client
PC=pc

SRC=udp.c
LIBOBJ=udp.o
PCLIBOBJ=udp.o
APPSRC=udplib_test.c
APPSRCCLIENT=udplib_client.c
APPOBJ=udplib_test.o

CC=arm-linux-gcc
CP=cp
CFLAGS=-shared -fpic  
LDFLAGS=-L. -ludp

LIBINSTALLPATH=/opt/rootfs/home/applib
APPINSTALLPATH=/opt/rootfs/home/apptest/

all: $(LIBTARGET) $(APPTARGET)

$(LIBTARGET) : $(LIBOBJ) 
	$(CC) $(CFLAGS) -o $(LIBTARGET) $(LIBOBJ) 
	$(CP) $(LIBTARGET) $(LIBINSTALLPATH)
$(APPTARGET) : $(APPOBJ)
	$(CC) -o $(APPTARGET) $(APPOBJ) $(LDFLAGS)
	$(CP) $(APPTARGET) $(APPINSTALLPATH)

$(PC):$(SRC)
	gcc $(CFLAGS) $(SRC) -o $(LIBTARGET)
	gcc $(APPSRCCLIENT) -o $(APPCLIENT) $(LDFLAGS)
clean:
	rm $(APPTARGET) $(LIBTARGET) $(APPOBJ) $(LIBOBJ) 
