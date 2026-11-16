/*Challenge 8.3 Dynamic Arrays ( Dynamic Fibonacci Sequence)*/

#include <iostream>

int main(int argc, char *argv[]) { 
    if (argc < 2) { 
        std::cout << "Usage: " << argv[0] << " <number>\n";
        return 1;   
    }
    int n = std::stoi(argv[1]); 
    if (n <= 0) {
        std::cout << "Number greater than 0\n"; 
        return 1; 
    }
    int *fib = new int[n];
    fib[0] = 0; 
    std::cout << fib[0] << " \n";
    if (n > 1) { 
        fib[1] = 1; 
        std::cout << fib[1] << " \n";
        for (int i = 2; i < n; ++i) { 
            fib[i] = fib[i - 1] + fib[i - 2]; 
            std::cout << fib[i] << " \n"; 
            if (i == n - 1) std::cout << "\n";
        }
    }
    delete[] fib;
}