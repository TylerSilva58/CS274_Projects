/* Challenge 8.1: References 1 */

#include <iostream>

void increment(int &x)
{
    x++;
}

int main()
{
    int a = 10;

    increment(a);

    std::cout << a << '\n';
}


