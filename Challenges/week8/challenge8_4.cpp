/* Challenge8_4 Fib with vectors */

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) { 
    std::vector<int> fib;
    if (argc < 2) { 
        std::cout << "Usage: " << argv[0] << " <number>\n";
        return 1;   
    }
    int n = std::stoi(argv[1]); 
    if (n <= 0) {
        std::cout << "Number greater than 0\n"; 
        return 1; 
    }

    fib.push_back(0);
    if (n > 1) {
        fib.push_back(1);
        for (int i = 2; i < n; ++i) {
            fib.push_back(fib[i - 1] + fib[i - 2]);
        }
    }
    for (int num : fib) {
        std::cout << num << " \n";
    }
    return 0;
}