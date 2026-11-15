#include "stack.h"
#include <cassert>
#include <iostream>

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    assert(s.peek() == 20);
    assert(s.peek() == 20); 
    assert(s.pop() == 20);
    s.push(-7);
    assert(s.pop() == -7);
    assert(s.pop() == 10);

    for (int i = 0; i < 128; ++i)
        s.push(i);
    for (int i = 127; i >= 0; --i) {
        assert(s.peek() == i);
        assert(s.pop() == i);
    }

    Stack other;
    s.push(0);
    other.push(42);
    assert(s.pop() == 0);
    assert(other.pop() == 42);
    std::cout << "All stack checks passed.\n";
}
