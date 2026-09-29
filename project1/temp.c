/* Temperature Converter */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("usage: temp value\n");
        return 1;
    }
    char *end; 
    float temp = strtof(argv[1], &end);

    if (end == argv[1] || *end != '\0') {
        printf("Enter valid number\n");
        return 1; 
    }

   float c = (temp - 32) * 5 / 9; 
   float f = (temp * 9/5 + 32); 
   printf("%.6f F is %.6f C\n", temp, c ); 
   printf("%.6f C is %.6f F\n", temp, f );
   return 0;

}