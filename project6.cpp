#include <cctype>
#include <fstream>
#include <iostream>
 
enum class State {
    at_start_of_line,
    in_spaces,
    in_non_spaces
};
 
int count_words(std::istream& in) {
    int words = 0;
    State state = State::at_start_of_line;
    char c;
 
    while (in.get(c)) {
        if (c == '\n') {
            state = State::at_start_of_line;
            continue;
        }
 
        bool is_space = std::isspace(static_cast<unsigned char>(c));
 
        switch (state) {
        case State::at_start_of_line:
        case State::in_spaces:
            if (is_space) {
                state = State::in_spaces;
            }
            else {
                ++words;
                state = State::in_non_spaces;
            }
            break;
 
        case State::in_non_spaces:
            if (is_space)
                state = State::in_spaces; 
            break;
        }
    }
 
    return words;
}
 
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << count_words(std::cin) << '\n';
        return 0;
    }
 
    int status = 0;
    int total = 0;
 
    for (int i = 1; i < argc; ++i) {
        std::ifstream in(argv[i]);
        if (!in.is_open()) {
            std::cerr << "cannot open '" << argv[i] << "'\n";
            status = 1;
            continue;
        }
 
        int words = count_words(in);
        total += words;
        std::cout << words << ' ' << "words" << '\n';
    }
 
    if (argc > 2)
        std::cout << total << " words\n";
 
    return status;
}