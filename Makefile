cc=tcc
rm=del
ar=tiny_libmaker
objs=main.o list.o

all: list.exe liblist.a

list.exe: $(objs)	
	$(cc) $(objs) -o list.exe -Wall -g
	
main.o: main.c 
	$(cc) -c main.c -o main.o -Wall -g
	
list.o: list.c list.h
	$(cc) -c -o list.o list.c -Wall -g

liblist.a: list.o
	$(ar) liblist.a list.o

.PHONY: clean
	
clean:
	$(rm) $(objs) liblist.a list.exe 
