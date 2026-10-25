/* Challenge 4.4 Arrays of Structs */

#include <stdio.h>

struct llm { 
    char name[32]; 
    unsigned long long parameters; 
    unsigned int context; 
};

int main() { 
    struct llm models[3] = { 
        {"opus", 700000000000, 2000000},
        {"qwen", 24000000000, 262000},
        {"kimi", 1000000000000, 4000000}
    };

    for(int i = 0; i < 3; i++) { 
        printf("Name: %s\n", models[i].name);
        printf("Parameters: %llu\n", models[i].parameters);
        printf("Context: %u\n", models[i].context);
        printf("\n");
    }
}