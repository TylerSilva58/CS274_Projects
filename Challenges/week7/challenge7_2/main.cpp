#include "printcounter.h"
#include <iostream>

int main() {
    PrintCounter p1, p2;

    auto show_counts = [&] {
        std::cout << "p1's count: " << p1.get_count() << '\n'
                  << "p2's count: " << p2.get_count() << '\n';
    };

    p1.print("Hello from p1!");
    p1.print("This is a test from p1!");
    show_counts();

    p2.print("And this is p2");
    p2.print("And this is p2 printing more");
    p2.print("And this is p2 printing still more");
    show_counts();
}
