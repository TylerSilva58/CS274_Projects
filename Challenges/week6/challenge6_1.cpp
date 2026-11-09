/* Challenge 6.1: Formating */

#include <iostream>
#include <format>

int main() {
    
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            std::cout << std::format("{} x {} = {}\n", i, j, i * j);
        }
    }
    return 0;
}