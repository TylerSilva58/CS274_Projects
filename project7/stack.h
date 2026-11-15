#ifndef STACK_H
#define STACK_H

#include <stdexcept>

class Stack {
public:
    static const int CAPACITY = 1024;

    Stack() : top_(0) {}

    void push(int value) {
        if (top_ >= CAPACITY)
            throw std::runtime_error("Stack overflow");
        data_[top_++] = value;
    }

    int pop() {
        if (top_ == 0)
            throw std::runtime_error("Stack underflow");
        return data_[--top_];
    }

    int peek() const {
        if (top_ == 0)
            throw std::runtime_error("Peek on empty stack");
        return data_[top_ - 1];
    }

    bool empty() const { return top_ == 0; }
    int size() const { return top_; }

private:
    int data_[CAPACITY];
    int top_;
};

#endif
