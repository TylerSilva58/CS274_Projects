#include "stack.h"

typedef struct node { 
    float value; 
    struct node *next; 
} Node;

typedef struct stack { 
    struct node *top; 
} Stack;


