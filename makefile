# makefile

all: main

main.o: main.cpp
	g++-4.7 -c -g main.cpp
	
main: main.o
	g++-4.7 -g -o main main.o
	
run:
	./main
	
r:
	./main <commands.txt
	
c:
	rm *.o main