/* challenge 6.3: My cat */

#include <iostream>
#include <string> 
#include <fstream>

int main(int argc, char* argv[]) { 
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " file file ...\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::ifstream f(argv[i]);

        if (!f.is_open()) {
            std::cerr << "Error opening file " << argv[i] << "\n";
            return 1;
        }

    std::string line;

    while (std::getline(f, line))
        std::cout << line << '\n';

    f.close();

    }
    return 0;

}