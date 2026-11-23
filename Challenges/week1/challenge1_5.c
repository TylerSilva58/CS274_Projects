/* Challenge 1.5: For Loops */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    for (int i = 0; i < 10; i++) { 
        printf("%2d", i);
    }
    printf("\n");

    for (int i = 0; i <= 8; i += 2) { 
        printf("%2d", i);
    }
    printf("\n");

    for (int i = 9; i >= 0; i--) { 
        printf("%2d", i);
    }
    printf("\n");

    for (int i = 20; i >= 0; i -= 4) { 
        printf("%3d", i);
    }
    printf("\n");

}