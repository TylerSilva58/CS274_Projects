/* Challenge 4.3 Structs */

#include <stdio.h>
#include <string.h>

struct llm { 
    char name[32]; 
    unsigned long long parameters; 
    unsigned int context; 
};

void struct_printer(struct llm p){ 
    printf("Name: %s\n", p.name);
    printf("Parameters: %llu\n", p.parameters);
    printf("Context: %u\n", p.context);
    printf("\n");
}

int main() { 
    struct llm opus; 
    strcpy(opus.name, "opus");
    opus.parameters = 700000000000;
    opus.context = 2000000;

    struct llm qwen;
    strcpy(qwen.name, "qwen");
    qwen.parameters = 24000000000;
    qwen.context = 262000;

    /*
    struct llm kimi;
    strcpy(kimi.name, "kimi");
    kimi.parameters = 1000000000000;
    kimi.context = 4000000;
    */

    struct llm kimi = {"kimi", 1000000000000, 4000000};

    struct_printer(opus);
    struct_printer(qwen);
    struct_printer(kimi);
}

