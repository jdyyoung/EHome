LIBTARGET=libds18b20.so
APPTARGET=ds18b20lib_test

LIBOBJ=ds18b20.o
APPOBJ=ds18b20lib_test.o

CC=arm-linux-gcc
CP=cp
CFLAGS=-shared -fpic  
LDFLAGS=-L. -lds18b20

LIBINSTALLPATH=/opt/rootfs/home/applib
APPINSTALLPATH=/opt/rootfs/home/apptest/

all: $(LIBTARGET) $(APPTARGET)

$(LIBTARGET) : $(LIBOBJ) 
	$(CC) $(CFLAGS) -o $(LIBTARGET) $(LIBOBJ) 
	$(CP) $(LIBTARGET) $(LIBINSTALLPATH)
$(APPTARGET) : $(APPOBJ)
	$(CC) -o $(APPTARGET) $(APPOBJ) $(LDFLAGS)
	$(CP) $(APPTARGET) $(APPINSTALLPATH)
clean:
	rm $(APPTARGET) $(LIBTARGET) $(APPOBJ) $(LIBOBJ)
