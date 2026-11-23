/* Challenge 1.4 Conditionals*/

#include <stdio.h>
#include <stdlib.h>

int main(int arg, char *argv[]) { 
    int v0 = atoi(argv[1]);
    int v1 = atoi(argv[2]);
    
    if (v0 > v1) { 
        printf("%d > %d\n", v0, v1);
    } else if (v0 < v1) { 
        printf("%d < %d\n", v0, v1);
    } else { 
        printf("%d == %d\n", v0, v1);
    }

}