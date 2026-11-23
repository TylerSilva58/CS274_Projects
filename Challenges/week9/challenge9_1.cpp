/* Challenge9_1 OBject Slicing */
#include <iostream>
#include <vector>   


class Animal {
public:
    virtual ~Animal() = default;
    virtual void sound() { std::cout << "Generic animal sound\n"; }
};

class Cat : public Animal {
public:
    void sound() override { std::cout << "Meow\n"; }
};

class Dog : public Animal {
public:
    void sound() override { std::cout << "Arf!\n"; }
};

int main (){ 
    Animal a;
    Cat c; 
    Dog d; 

    // a.sound(); 
    // c.sound(); 
    // d.sound();

    std::vector<Animal*> animals;
    animals.push_back(&a);
    animals.push_back(&c);
    animals.push_back(&d);

    // The first non pointer vector 

    for (auto& animal : animals) {
        animal->sound();
    }
}