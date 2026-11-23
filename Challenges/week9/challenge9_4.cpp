/* Challenge9_4: Virtual Destructors */

#include <iostream>
#include <string>

class Animal {
public:
    Animal() { std::cout << "=== Animal CTOR\n"; }
    virtual ~Animal() { std::cout << "=== Animal DTOR\n"; }
};

class Cat : public Animal {
public:
    Cat() { std::cout << "=== Cat CTOR\n"; }
    ~Cat() { std::cout << "=== Cat DTOR\n"; }
};

int main() { 
    Animal *a = new Cat();
    delete a;
}

/*Part 3 Output:
=== Animal CTOR
=== Cat CTOR
=== Animal DTOR
*/
