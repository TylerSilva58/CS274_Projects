#pragma once

namespace mylib {

class Stack {
private:
    int values[128]{};
    int next = 0; 

public:
    void push(int value) { values[next++] = value; }
    int pop() { return values[--next]; }
    int peek() { return values[next - 1]; }
};

} 