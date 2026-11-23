/*  Challenge 2.1 ARRAY SIZE */
/* Tyler Silva */

#include <stdio.h>
#define ARRAY_SIZE 15

int main(void) { 
    int a[ARRAY_SIZE];
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        a[i] = (14 - i) * 10;
        printf("a[%d] = %d\n", i, a[i]);

    }
}