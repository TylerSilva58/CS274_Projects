/* Challenge8_2 References 2 */

#include <iostream>

class Animal {
public:
    void sound() { std::cout << "Generic animal sound\n"; }
    ~Animal() = default;
};

class Cat : public Animal { 
public:
    void sound() { std::cout << "Meow\n"; }
    ~Cat() = default;
};

class Dog : public Animal { 
public:
    void sound() { std::cout << "Woof\n"; }
    ~Dog() = default;
}; 

void make_sound(Animal &a)
{
    a.sound();
}

int main()
{
    Animal a;
    Cat c; 
    Dog d; 

    make_sound(a);
    make_sound(c); 
    make_sound(d); 
}
