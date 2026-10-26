mather.o: mather.c mather.h
	gcc -Wall -o $@ -c $<

boxer.o: boxer.c boxer.h
	gcc -Wall -o $@ -c $<

main.o: main.c mather.h boxer.h
	gcc -Wall -o $@ -c $<

main: main.o mather.o boxer.o
	gcc -Wall -o $@ $^

clean:
	rm -f main.o mather.o boxer.o main