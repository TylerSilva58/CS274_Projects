#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Push Function: 
void push(float value, Stack* stack) { 
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Could not allocate memory for Stack Node\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop Function: 
float pop(int* flag, Stack* stack) { 
    if (stack->top == NULL) {
        *flag = 0;
        return 0.0;
    }
    *flag = 1;
    Node* temp = stack->top;
    float value = temp->value;
    stack->top = temp->next;
    free(temp);
    return value;
}

// Create Stack Function:
Stack* createStack(void) { 
    Stack* newStack  = (Stack*)malloc(sizeof(Stack)); 
    if (newStack == NULL) { 
        fprintf(stderr, "Could not allocate memory for Stack\n"); 
        exit(EXIT_FAILURE);
    }
    newStack->top = NULL;
    return newStack;
}

// Free Stack Function:
void freeStack(Stack* stack) { 
    Node* current = stack->top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);    
}



