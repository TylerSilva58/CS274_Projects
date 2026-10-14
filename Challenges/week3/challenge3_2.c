/* Challenge 3.2 Passing pointers to functions */

#include <stdio.h>

// Compiler might warn on a being unused, but ignore it.
void bad_increment(int a)
{
    a++;
}

void good_increment(int *a) {
    
    (*a)++;
}

int main(void)
{
    int x = 12;

    bad_increment(x);
    printf("%d\n", x);  // 12, boo

    // Uncomment and fix the following:
    
    good_increment(&x);
    printf("%d\n", x);  // 13, yay!
    
}



// STATE MACHINE FOR PROJECT 
