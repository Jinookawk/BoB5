subtarget: hell.c hell.h
	gcc -c hell.c

hello: hello.c subtarget
	gcc -o hello hell.o hello.c -I.

all: hello

clean:
	rm -rf hell.o hello

.PHONY: all clean subtarget

