/* Challenge 3.3 Array Pointer Equivalence */

#include <stdio.h>

void printstr(char *s)
{
    for (int i = 0; i < 2; i++) {
        char *p = s;
        while (*p != '\0') {
            putchar(*p);
            p++;
        }
    }
}

int main(void)
{
    char *a = "Hello, world!\n";
    char b[128] = "The Magic Words are Squeamish Ossifrage\n";

    printstr(a);
    printstr(b);
    printstr("String literal!\n");
}
