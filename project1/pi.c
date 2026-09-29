/* Compute Pi with Lebnitz Series */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if (argc != 2) {
        printf("Usage: ./pi pi iterations\n");
        return 1;
    }

    int iterations =  atoi(argv[1]);
	double sum = 0.0; 

    for (int i = 0; i < iterations; i++) {
    	double denominator = (i * 2) + 1; 
    	if (i % 2 == 0) { 
    		sum += 1.0 / denominator;
    	} else {
    			sum -= 1.0 / denominator;  
      	}
    }

    double pi = 4.0 * sum; 
    printf("%.6f\n", pi);
}
