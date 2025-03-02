CC = gcc
CFLAGS = -shared -O3 -fPIC -lm

all: libkernel.so

libkernel.so: kernel.c
	$(CC) $(CFLAGS) -o libkernel.so kernel.c

clean:
	rm -f libkernel.so