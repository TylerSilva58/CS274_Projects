/* Compute Pi with Leibniz Series */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if (argc != 2) {
        printf("usage: pi iterations\n");
        return 1;
    }

    int iterations =  atoi(argv[1]);
	float sum = 0.0; 

    for (int i = 0; i < iterations; i++) {
    	float denominator = (i * 2) + 1; 
    	if (i % 2 == 0) { 
    		sum += 1 / denominator;
    	} else {
    			sum -= 1 / denominator;  
      	}
    }

    float pi = 4 * sum; 
    printf("%.6f\n", pi);
}
