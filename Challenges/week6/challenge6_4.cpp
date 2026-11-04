/* Challenge 6.4 Writing file */

#include <iostream>
#include <fstream>

int main() {    
    std::ofstream outfile("outfile.txt");
    for (int i = 1; i <= 10; i++) { 
        outfile << "Line " << i << "/10\n";
        std::cout << "Line" << i << "/10" << std::endl;
    }
    outfile.close();
}