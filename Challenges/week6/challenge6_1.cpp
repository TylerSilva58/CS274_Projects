/* Challenge 6.1: Formating */

#include <iostream>
#include <string>
#include <format>

int main() {
    
    for (int i = 0; i < 16; i++) { 
        for (int j = 0; j < 4; j++) { 
            std::cout << std::format("{}x{}={}", i / 4 + 1, j + 1, (i / 4 + 1) * (j + 1));
            if (!(i == 15 && j == 3)) std::cout << ", ";
        }
    }
    std::cout << std::endl;
}