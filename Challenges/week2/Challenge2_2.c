/*  Challenge 2.2 Functions*/
/* Tyler Silva */

#include <stdio.h>
#include <math.h>

// TODO: write the functions
char hello(void) {
    printf("Hello World!\n");
}

int adder(int a, int b) { 
    return a + b;
}

float quadratic_formula(float a, float b, float c) { 
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

int print_num(char str[], int num) {
    printf("%s: %d\n", str, num);
}

int main(void) {
    hello();

    printf("2 + 4 = %d\n", adder(2, 4));
    printf("2 - 4 = %d\n", adder(2, -4));

    printf("x^2 + 3x - 2.5 = 0 => x = %f\n", quadratic_formula(1.0, 3, -2.5));
    printf("3x^2 - 7.2x + 1 = 0 => x = %f\n", quadratic_formula(3, -7.2, 1));

    print_num("This is probably two", 2);
}
