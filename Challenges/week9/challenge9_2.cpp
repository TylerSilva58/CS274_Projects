/* Challenge 9.2: Exceptions */

/* 
INTRO TO SYSTEMS PROGRAMMING (CS_274_501_F2026)
Challenge 9.2: Exceptions

Challenge 9.2: Exceptions 
Due Monday by 11:59pm Points 10 Submitting a text entry box, a website url, or a file upload
Introduction
Let's mess with exceptions!

In this challenge, we want to make a class that stores 50 numbers in an array and allows users to look up the values by specifying an index on the command line.

Here are some sample runs:

$ ./main
usage: ./main index

$ ./main 2
The value at index 2 is 20

$ ./main 3
The value at index 3 is 30

$ ./main 70
Out of range: invalid index

$ ./main -2
Out of range: invalid index

$ ./main foo
Invalid integer: stoi
What To Do
Part 1: Make a Class
Make a class called Holder that has:

A private array of 50 ints.
A constructor that initializes the integers to 0, 10, 20, 30, 40, etc.
A method int get(int i) that returns the value in the array at the given index i. Importantly: if the passed-in i is an invalid index, the function must throw a std::out_of_range exception with an appropriate message.
Part 2: Make a main to exercise it
Your main() should do several things:

Make a new Holder object.
If the user didn't specify a valid number of command line arguments, exit with an error message.
Convert argv[1] to an int with std::stoi().
Be advised this might throw std::invalid_argument or std::out_of_range!
Attempt to call .get() on your Holder instance with the index.
Be advised this might throw std::out_of_range!
Print the result from .get().
And you must catch those exceptions and print appropriate messages.

Consider: Both .get() and std::stoi() can throw std::out_of_range. How many try blocks do you need? How few can you get away with? (There's no single right answer to this one.)

Hint: You can look at the .what() method on the exception to get the message the exception was created with. In the examples at the top, this is what's giving invalid index or stoi in the output.

What To Turn In
A copy of your code or a link to your repo. (If a repo link, please deep-link to the page that shows the source.)

*/


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