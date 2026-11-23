/* Challenge9_3: Destructors */

#include <iostream>
// no private size field, will use dynamic allocation only
class MyData { 
    private: 
        int* data;
    public: 
        MyData(int size) { 
            data = new int[size]; 
            std::cout << "=== CTOR: size " << size << "\n";
            for (int i = 0; i < size; i++) { 
                data[i] = i * 10;
            }
        }
        ~MyData() { 
            delete[] data; 
            std::cout << "=== DTOR\n";
            data = nullptr;
        }
        int& at(int i) { 
            if(i < 0 || i >= sizeof(data)/sizeof(data[0])) { 
                throw std::out_of_range("Index out of range");
            }
            return data[i];
        }
};

int main(int argc, char* argv[]) { 
    MyData d1(5);
    MyData d2 = d1;
    d2.at(3) = 999;
    std::cout << d2.at(3) << '\n';
}