/* Challenge 4.1 sizeof */

#include <stdio.h>

struct vars { 
    char c; 
    short s; 
    int i; 
    long l; 
};

void print_sizes() { 
    printf("sizeof c = %zu\n", sizeof(((struct vars *)0) -> c )); 
    printf("sizeof s = %zu\n", sizeof(((struct vars *)0) -> s )); 
    printf("sizeof i = %zu\n", sizeof(((struct vars *)0) -> i )); 
    printf("sizeof l = %zu\n", sizeof(((struct vars *)0) -> l )); 
}

int main() { 

    struct vars toPrint; 
        toPrint.c = 'a'; 
        toPrint.s = 1; 
        toPrint.i = 2; 
        toPrint.l = 3; 

    print_sizes();

    printf("sizeof (l + i) = %zu\n", sizeof(toPrint.l + toPrint.i));

    printf("sizeof 12 = %zu\n", sizeof(12)); 
    printf("sizeof 20 = %zu\n", sizeof(20)); 
    printf("sizeof 3.14 = %zu\n", sizeof(3.14));

    printf("sizeof char = %zu\n", sizeof(char));
    printf("sizeof int = %zu\n", sizeof(int));
    printf("sizeof long = %zu\n", sizeof(long));
    printf("sizeof float = %zu\n", sizeof(float));
    printf("sizeof double = %zu\n", sizeof(double));

    int *p = &toPrint.i;
    long *q = &toPrint.l;
    printf("sizeof *p = %zu\n", sizeof(*p));
    printf("sizeof *q = %zu\n", sizeof(*q));

    printf("sizeof char* = %zu\n", sizeof(char*));
    printf("sizeof int* = %zu\n", sizeof(int*));
    printf("sizeof long* = %zu\n", sizeof(long*));
    printf("sizeof double* = %zu\n", sizeof(double*));

    //Question 1:  3.14's type is a double 
    //Question 2: 12's type is an int
    //Question 3: All of the pointer types are the same size because they store memory addresses. It doesnt matter the type of the pointer. 

}