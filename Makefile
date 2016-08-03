all: list.exe

list.exe: main.o list.o
	gcc -o list.exe main.o list.o -Wall -g
	
main.o: main.c 
	gcc -c -o main.o main.c -Wall -g
	
list.o: list.c list.h
	gcc -c -o list.o list.c -Wall -g

.PHONY: clean
	
clean:
	rm list.o main.o list.exe
