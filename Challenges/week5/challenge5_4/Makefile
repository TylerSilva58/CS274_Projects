all: challenge5_4

llist.o: llist.c llist.h
	gcc -c llist.c -o llist.o

main.o: main.c llist.h
	gcc -c main.c -o main.o

challenge5_4: main.o llist.o
	gcc -o challenge5_4 main.o llist.o

clean:
	rm -f main.o llist.o challenge5_4
