CC = gcc
CFLAGS = -shared -O3 -fPIC

all: libkernel.so

libkernel.so: kernel.c
	$(CC) $(CFLAGS) -o libkernel.so kernel.c -lm

clean:
	rm -f libkernel.so