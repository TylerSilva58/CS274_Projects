/* challenge 6.5 Reverse a string */

#include <iostream>
#include <string>
#include <sstream>

// reverese a multiple strings 

int main(int argc, char* argv[]) { 
    std::string str;
    for (int i = 1; i < argc; ++i) {
        str += argv[i];
        if (i < argc - 1) {
            str += " ";
        }
    }
    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;

    return 0;
}