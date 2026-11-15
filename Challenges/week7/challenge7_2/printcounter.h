#pragma once

#include <string>

class PrintCounter {
private:
    int count;

public:
    PrintCounter() : count{0} {}
    void print(std::string text);
    int get_count() { return count; } 
};
