#include <stdio.h>

int main(void) {
    int value1 = 37; //#1
    int value2 = 3490; //#1

    int *p; //#2
    int *q; //#2

    p = &value1; //#3

    printf("%d\n", value1); //#4

    printf("%p\n", (void*)&value1); // #5

    printf("%p\n", (void*)p); //#6

    printf("%d\n", *p); //#7

    q = &value2; //#8

    printf("%d\n", value2); //#9

    printf("%p\n", (void*)&value2); // #10

    printf("%p\n", (void*)q); //#11

    printf("%d\n", *q); //#12

    int temp = *p; //#13
    *p = *q; //#13
    *q = temp; //#13

    printf("%d\n %d\n", value1, value2); //#14

    p = q; //#15

    printf("%d\n %d\n", *p, *q); //#16 

    return 0;
}