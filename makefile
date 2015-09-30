all: stest mainmainmain

debug: stestdebug

stest: stest.o struct.o
	gcc -g stest.o struct.o -o stest -lreadline 

stest.o: stest.c struct.h
	gcc -g -c stest.c -lreadline 

stestdebug: stestdebug.o struct.o
	gcc -g stestdebug.o struct.o -o stestdebug -lreadline 

stestdebug.o: stest.c struct.h 
	gcc -g -c stest.c -o stestdebug.o -DDEBUG -lreadline 

struct.o: struct.c struct.h
	gcc -g -c struct.c -o struct.o -lreadline 

mainmainmain: struct.o mainmainmain.o
	gcc -g struct.o mainmainmain.o -o mainmainmain -lreadline

mainmainmain.o: mainmainmain.c struct.h
	gcc -g -c mainmainmain.c -o mainmainmain.o

clean:
	rm -f *.o stest stestebug

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig4

