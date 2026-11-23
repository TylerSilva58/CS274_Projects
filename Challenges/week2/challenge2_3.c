/* Challenge 2.3 Passing Arrays to Functions */
/* Tyler Silva */

#include <stdio.h>

int arraySum(int arr[], int arr_size) {
    
    int sum = 0; 

    for (int i = 0; i < arr_size; i++) { 
        sum += arr[i]; 
    }
    printf("First Sum: %d\n", sum);
}


int arraySum2(int arr[], int arr_size) { 
    
    int sum = 0;

    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];
    }
    printf("Second Sum: %d\n", sum);
}

void arrayPrint(int arr[], int arr_size) { 

    for (int i = 0; i < arr_size; i++) { 
        printf("%3d", arr[i]); 
    }
    printf("\n");
}

int arrayReverse(int arr[], int arr_size) { 
    
    for (int i = arr_size - 1; i >= 0; i--) { 
        printf("%3d", arr[i]); 
    }
    printf("\n");
}

int main() { 


    int x[5] = {1,2,3,4,5};
    int y[6] = {5,6,7,8,9,0};
    int z[7] = {1,2,3,4,5,6,7};
    int w[8] = {2,4,6,8,10,12,14,16};

    arraySum(x, 5);
    arraySum2(y, 6);
    arrayReverse(z, 7);
    arrayReverse(w, 8);

}