/* Compare Square Roots with Heron's Method */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){ 
	if (argc < 2 || argc > 3){ 
		printf("Usage: ./sqrt number [iterations]\n");
		return 1; 
	}
	int iterations = 20; 
	double number = atof(argv[1]);

	if (argc == 3) {
		iterations = atoi(argv[2]);

	}

	if (number <= 0) {
		printf("Must be positive!\n");
		return 1;
	}
	double guess = number / 2.0; 

	for (int i = 0; i < iterations; i++){ 
		guess = (guess + number / guess) / 2.0;

	}
	printf("%.6f\n", guess);

}