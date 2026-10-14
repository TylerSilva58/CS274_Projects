/* Challenge 3.3 Array Pointer Equivalence */

#include <stdio.h>

void printstr(char *s) {
    char *beg = s;

    while (*s != '\0') {
        putchar(*s);
        s++;
    }
    s = beg;
    int i = 0;
    while (s[i] != '\0') {
        putchar(s[i]);
        i++;
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
