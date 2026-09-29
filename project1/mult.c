/* Multiplication Table*/

#include <stdio.h>

int main(void) {
	for (int r = 1; r <= 12 ; r++) {
		for (int c = 1; c <= 12; c++) { 
			printf("%4d", r * c); 
		}
		printf("\n");
	}

}
