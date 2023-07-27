CC=GCC
BOPTIONS=-g -Wall

btf.o:
	gcc -c btf.c -o btf.o

main: btf.o
	gcc main.c -o btf btf.o

clean:
	rm -rf *.o
	rm -rf test
	rm -rf btf
