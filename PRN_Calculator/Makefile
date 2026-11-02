.PHONY: all clean
all: rpncalc

rpncalc: rpncalc.o stack.o
	$(CC) $(CFLAGS) -o $@ $^

rpncalc.o: rpncalc.c stack.h
	$(CC) $(CFLAGS) -c -o $@ $<

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f rpncalc.o stack.o rpncalc
