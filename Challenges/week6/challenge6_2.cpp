/* Challenge 6.2: Multiplication table 12x12 Row-wise Output */

#include <iostream>
#include <string> 
#include <format>

int main() { 
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 12; j++) { 
            std::cout << std::format("{:4}", i * j);
            if (!(i == 12 && j == 12)) std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}