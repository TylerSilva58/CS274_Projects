/* Types Challenge*/

#include <stdio.h>

int main(void) {

    int x = 4; 
    float f = 0.0;

    f = 3+4/(2*3*4)-4/(4*5*6)+4/(6*7*8)-4/(8*9*10)+4/(10*11*12);

    printf("x = %d\n", x);
    printf("f = %f\n", f);

    float g = 0.0;

    // converts g to a float to avoid integer division
    g = 3.0+4.0/(2.0*3.0*4.0)-4.0/(4.0*5.0*6.0)+4.0/(6.0*7.0*8.0)-4.0/(8.0*9.0*10.0)+4.0/(10.0*11.0*12.0);

    printf("g = %f\n", g);

    g = 3+4/(2*3*4)-4/(4*5*6)+4/(6*7*8)-4/(8*9*10)+4/(10*11*12);

    printf("g = %d\n", (int)g);

    char s[20];
    g = 3.142713;
    sprintf(s, "%f", g);
    printf("%s\n", s);

    printf("%f\n", 22.0/7.0);
 
    printf("The string is:%s\n", "This is a test");

    return 0;
}

