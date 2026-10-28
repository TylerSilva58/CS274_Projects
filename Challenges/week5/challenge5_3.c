//STACK
// stack holds the return address for the fuction
// stack also holds all the loacal variables for the function
// *Stack Frame*: locals and the return address for a particular call into a function
// Locals in C are called *automatic variables* automatic de-allocated when the function returns
// HEAP
// If you want soething that lives longer than a function call, this is the heap
// This is long lived storage of whatever you want
// All allocations and deallocations are manual
// HAZARDS
// malloc() '\' free()
// Memory leaks: forget to free allocated memory
// usa-after-free: accessing memory after it has been freed
// double free: calling free() on the same memory twice

/*Challenge 5.3 Dynamic Memory Allocation */
#include <stdio.h>
#include <stdlib.h>

char *my_strdup(char *src)
{
    int len = 0; 
    while (src[len] != '\0')
        len++;
    char *dup = malloc(len + 1); 
    if (dup == NULL){ 
        return NULL;
    }
    for (int i = 0; i < len; i++){ 
        dup[i] = src[i]; 

    }
    dup[len] = '\0'; 
    return dup;
    // You may *not* use the built-in strdup() for this challenge.
}

void upper_string(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) { 
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
    }
}

int main(void)
{
    char *orig = "And the flowers are still standing!";
    char *s = my_strdup(orig);

    printf("Original : \"%s\"\n", orig);
    printf("Duplicate: \"%s\"\n", s);

    upper_string(s);

    printf("Original : \"%s\"\n", orig);
    printf("Uppercase: \"%s\"\n", s);

    free(s);
}

