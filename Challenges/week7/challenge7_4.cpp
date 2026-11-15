#include "stack.h"
#include <iostream>

enum Day : int {
    Monday = 10, 
    Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

enum class Month : int {
    January, February, March, April
};

int main() {
    Stack s;
    s.push(Monday); 
    s.push(Wednesday);
    s.push(Friday);
    std::cout << "Days (last in, first out):\n";
    for (int i = 0; i < 3; ++i)
        std::cout << s.pop() << '\n';

    s.push(static_cast<int>(Month::January));
    s.push(static_cast<int>(Month::February));
    s.push(static_cast<int>(Month::April));
    std::cout << "Months (last in, first out):\n";
    for (int i = 0; i < 3; ++i)
        std::cout << s.pop() << '\n';
}
