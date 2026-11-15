#include <cstring>
#include <iostream>
#include <stdexcept>
#include "cpu.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "usage: " << argv[0] << " [-d] programfile\n";
        return 1;
    }

    bool dump = false;
    const char *filename = argv[1];

    if (argc >= 3 && std::strcmp(argv[1], "-d") == 0) {
        dump = true;
        filename = argv[2];
    }

    CPU cpu;

    try {
        cpu.load(filename);

        if (dump) {
            cpu.dump();
            return 0;
        }

        cpu.run();
    } catch (const std::exception &e) {
        std::cerr << argv[0] << ": " << e.what() << '\n';
        return 1;
    }

    return 0;
}
