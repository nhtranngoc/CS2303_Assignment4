all: stest mainmainmain

debug: stestdebug

stest: stest.o struct.o
	# gcc -g stest.o struct.o -o stest -lreadline 
	gcc -g stest.o struct.o -o stest 

stest.o: stest.c struct.h
	# gcc -g -c stest.c -lreadline 
	gcc -g -c stest.c 

stestdebug: stestdebug.o struct.o
	# gcc -g stestdebug.o struct.o -o stestdebug -lreadline 
	gcc -g stestdebug.o struct.o -o stestdebug

stestdebug.o: stest.c struct.h 
	# gcc -g -c stest.c -o stestdebug.o -DDEBUG -lreadline 
	gcc -g -c stest.c -o stestdebug.o -DDEBUG

struct.o: struct.c struct.h
	# gcc -g -c struct.c -o struct.o -lreadline 
	gcc -g -c struct.c -o struct.o

mainmainmain: struct.o mainmainmain.o
	# gcc -g struct.o mainmainmain.o -o mainmainmain -lreadline
	gcc -g struct.o mainmainmain.o -o mainmainmain

mainmainmain.o: mainmainmain.c struct.h
	# gcc -g -c mainmainmain.c -o mainmainmain.o -lreadline
	gcc -g -c mainmainmain.c -o mainmainmain.o

clean:
	rm -f *.o stest stestebug

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig4

