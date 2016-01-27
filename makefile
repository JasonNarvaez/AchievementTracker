# makefile

all: main

main.o: main.cpp
	g++-4.7 -std=c++11 -c -g main.cpp
	
player.o: player.cpp player.h
	g++-4.7 -std=c++11 -c -g player.cpp
	
main: main.o player.o
	g++-4.7 -std=c++11 -g -o main main.o player.o
	
run:
	./main
	
r:
	./main <commands.txt
	
c:
	rm *.o main