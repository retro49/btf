CC=GCC
BOPTIONS=-g -Wall

util.o:
	gcc -c util.c -o util.o

btf.o:
	gcc -c btf.c -o btf.o

btf: btf.o util.o
	gcc main.c -o btf btf.o util.o

clean:
	rm -rf *.o
	rm -rf test
	rm -rf btf
