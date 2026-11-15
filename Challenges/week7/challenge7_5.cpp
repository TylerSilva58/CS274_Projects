#include "stack7_5.h"
#include <cassert>
#include <iostream>

int main() {
    mylib::Stack s;
    s.push(10);
    s.push(20);
    assert(s.peek() == 20);
    assert(s.pop() == 20);
    assert(s.pop() == 10);

    {
        using mylib::Stack;
        Stack s;
        s.push(30);
        assert(s.pop() == 30);
    }

    {
        using namespace mylib;
        Stack s;
        s.push(40);
        assert(s.pop() == 40);
    }
    std::cout << "namespace approaches passed.\n";
}
