/* Challenge 9.2: Exceptions */

#include <iostream>
#include <stdexcept>    

class Holder { 
    private:
        int arr[50];
    public: 
        Holder() {
            for (int i = 0; i < 50; ++i) {
                arr[i] = i * 10;
            }
        }

        int get(int i) {
            if (i < 0 || i >= 50) {
                throw std::out_of_range("invalid Index");
            }
            return arr[i];
        }
};
int main(int argc, char* argv[]) {
    Holder h;
    if (argc != 2) {
        std::cerr << "usage: ./main index\n";
        return 1;
    }
    try {
        int index = std::stoi(argv[1]);
        int value = h.get(index);
        std::cout << "The value at index " << index << " is " << value << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid integer: " << e.what() << "\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << "\n";
    }
    return 0;
}