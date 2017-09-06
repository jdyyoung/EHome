LIBTARGET=libled.so
APPTARGET=ledlib_test

LIBOBJ=led.o
APPOBJ=ledlib_test.o

CC=arm-linux-gcc
CP=cp
CFLAGS=-shared -fpic  
LDFLAGS=-L. -lled

LIBINSTALLPATH=/opt/rootfs/home/applib/
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
