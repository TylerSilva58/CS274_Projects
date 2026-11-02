#ifndef STACK_H
#define STACK_H

typedef struct node { 
    float value; 
    struct node *next; 
} Node;

typedef struct stack { 
    Node *top; 
} Stack;
 
void push(float value, Stack* stack); 

float pop(int* flag, Stack* stack);

Stack* createStack(void); 

void freeStack(Stack* stack);

#endif

