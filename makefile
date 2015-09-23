all: stest

stest: stest.o
	gcc -g stest.o -o stest

stest.o: stest.c struct.h
	gcc -g -c stest.c

stestdebug: stestdebug.o
	gcc -g stestdebug.o -o stestdebug

stestdebug.o: stest.c struct.h
	gcc -g -c stest.c -o stestdebug.o 

clean:
	rm -f *.o stest stestdebug

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig4

