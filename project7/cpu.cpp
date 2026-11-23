#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include "cpu.h"

CPU::CPU() : program_size(0), pc(0) {
    for (int i = 0; i < MEMORY_SIZE; i++)
        memory[i] = 0;
}

int CPU::parse_line(const std::string &line) {
    if (line == "PUSH") return PUSH;
    if (line == "POP")  return POP;
    if (line == "DUP")  return DUP;
    if (line == "ADD")  return ADD;
    if (line == "SUB")  return SUB;
    if (line == "JZ")   return JZ;
    if (line == "JNZ")  return JNZ;
    if (line == "PRT")  return PRT;
    if (line == "END")  return END;
    if (line == "SWAP") return SWAP;
    if (line == "OVER") return OVER;

    return std::stoi(line);
}

void CPU::load(const std::string &filename) {
    std::ifstream infile(filename);

    if (!infile.is_open())
        throw std::runtime_error("Failed to open file");

    std::string line;
    program_size = 0;

    while (std::getline(infile, line)) {
        while (!line.empty() && isspace((unsigned char)line.back()))
            line.pop_back();

        if (line.empty())
            continue;

        if (program_size >= MEMORY_SIZE)
            throw std::runtime_error("Program too large");

        memory[program_size++] = parse_line(line);
    }
}

void CPU::dump() const {
    for (int i = 0; i < program_size; i++)
        std::cout << i << ": " << memory[i] << '\n';
}

void CPU::run() {
    pc = 0;

    while (true) {
        int a, b;

        switch (memory[pc]) {
        case PUSH:
            stack.push(memory[pc + 1]);
            pc += 2;
            break;

        case POP:
            stack.pop();
            pc++;
            break;

        case DUP:
            stack.push(stack.peek());
            pc++;
            break;

        case ADD:
            a = stack.pop();
            b = stack.pop();
            stack.push(b + a);
            pc++;
            break;

        case SUB:
            a = stack.pop(); 
            b = stack.pop();   
            stack.push(b - a);
            pc++;
            break;

        case JZ:
            if (stack.pop() == 0)
                pc = memory[pc + 1];
            else
                pc += 2;
            break;

        case JNZ:
            if (stack.pop() != 0)
                pc = memory[pc + 1];
            else
                pc += 2;
            break;

        case PRT:
            std::cout << stack.peek() << '\n';
            pc++;
            break;

        case END:
            return;

        case SWAP:
            a = stack.pop();
            b = stack.pop();
            stack.push(a);
            stack.push(b);
            pc++;
            break;

        case OVER:
            a = stack.pop();
            b = stack.peek();
            stack.push(a);
            stack.push(b);
            pc++;
            break;

        default:
            throw std::runtime_error("Invalid instruction at address" +
                                     std::to_string(pc));
        }
    }
}
