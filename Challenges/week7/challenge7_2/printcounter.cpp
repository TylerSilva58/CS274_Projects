#include "printcounter.h"
#include <iostream>

void PrintCounter::print(std::string text) {
    std::cout << text << '\n';
    ++count;
}
