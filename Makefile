cc=tcc
rm=del
objs=main.o list.o

list.exe: $(objs)	
	$(cc) $(objs) -o list.exe -Wall -g
	
main.o: main.c 
	$(cc) -c main.c -o main.o -Wall -g
	
list.o: list.c list.h
	$(cc) -c -o list.o list.c -Wall -g

.PHONY: clean
	
clean:
	$(rm) $(objs) list.exe
