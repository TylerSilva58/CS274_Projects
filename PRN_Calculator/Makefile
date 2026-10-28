.PHONY: all
.PHONY: clean

stack.o: stack.c stack.h
	gcc -Wall -o $@ -c $<

rpncalc.o: rpncalc.c stack.h
	gcc -Wall -o $@ -c $<

rpncalc: rpncalc.o stack.o
	gcc -Wall -o $@ $^

all: rpncalc

clean:
	rm -f rpncalc.o stack.o rpncalc