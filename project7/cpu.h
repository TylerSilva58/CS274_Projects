#ifndef CPU_H
#define CPU_H

#include <string>
#include "stack.h"

enum Instruction {
    PUSH,
    POP,
    DUP,
    ADD,
    SUB,
    JZ,
    JNZ,
    PRT,
    END,
    SWAP,   // extra credit
    OVER    // extra credit
};

class CPU {
public:
    static const int MEMORY_SIZE = 1024;

    CPU();

    void load(const std::string &filename);
    void run();
    void dump() const;   // debugging: print loaded memory

private:
    int memory[MEMORY_SIZE];
    int program_size;
    int pc;
    Stack stack;

    static int parse_line(const std::string &line);
};

#endif
