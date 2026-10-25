/* Challenge 4.2 sizeof and Arrays */

#include <stdio.h>

void f1(int *x)
{
    printf("f1: sizeof x = %zu\n", sizeof x);
}

void f2(int x[])
{
    printf("f2: sizeof x = %zu\n", sizeof x);
}

void f3(int x[5])
{
    printf("f3: sizeof x = %zu\n", sizeof x);
}

int main() {
    char a[12]; // #1
    int b[4];   // #2

    printf("sizeof char = %zu\n", sizeof(char)); // #3
    printf("sizeof int = %zu\n", sizeof(int));   // #3

    printf("sizeof a = %zu\n", sizeof(a)); // #4
    printf("sizeof b = %zu\n", sizeof(b)); // #4

    printf("elements in b = %zu\n", sizeof(b) / sizeof(int));    // #5 (uses a type name)
    printf("elements in b = %zu\n", sizeof(b) / sizeof(b[0]));   // #6 (no type name)

    char *p = a; // #7
    int *q = b;  // #8

    printf("sizeof p = %zu\n", sizeof(p)); // #9
    printf("sizeof q = %zu\n", sizeof(q)); // #9

    f1(b); 
    f2(b);
    f3(b);

    return 0;

    //sizeof a measures the array and sizeof b measures the pointer variable.
    //it works beause the array decays the pointer to the first element, they all all integer pointers.
}