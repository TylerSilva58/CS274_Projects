// Draws box with width and hieght
#include <stdio.h>
#include <stdlib.h>
#include "boxer.h"

void draw_box(int input, char *input1[2]) { 
    int width = atoi(input1[1]); 
    int height = atoi(input1[2]); 
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("*");
        }
        printf("\n");
    }
}
   
