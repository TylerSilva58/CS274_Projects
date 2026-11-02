#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    Stack *stack = createStack();

    for (int i = 1; i < argc; i++) {
        const char *token = argv[i];
        if (strlen(token) == 1 && strchr("+-*/", token[0]) != NULL) {
            int ok;
            float right = pop(&ok, stack);
            if (!ok) {
                fprintf(stderr, "rpncalc: missing operand for '%s'\n", token);
                freeStack(stack);
                return EXIT_FAILURE;
            }
            float left = pop(&ok, stack);
            if (!ok) {
                fprintf(stderr, "rpncalc: missing operand for '%s'\n", token);
                freeStack(stack);
                return EXIT_FAILURE;
            }
            float result;
            switch (token[0]) {
            case '+': result = left + right; break;
            case '-': result = left - right; break;
            case '*': result = left * right; break;
            default:
                if (right == 0.0f) {
                    fprintf(stderr, "rpncalc: division by zero\n");
                    freeStack(stack);
                    return EXIT_FAILURE;
                }
                result = left / right;
                break;
            }
            push(result, stack);
        } else {
            char *end;
            float value = strtof(token, &end);
            if (end == token || *end != '\0') {
                fprintf(stderr, "rpncalc: error: %s\n", token);
                freeStack(stack);
                return EXIT_FAILURE;
            }
            push(value, stack);
        }
    }

    int ok;
    float result = pop(&ok, stack);
    if (!ok) {
        fprintf(stderr, "rpncalc: missing operand\n");
        freeStack(stack);
        return EXIT_FAILURE;
    }
    printf("%f\n", result);
    if (stack->top != NULL) {
        fprintf(stderr, "rpncalc: warning: extra items remaining on stack\n");
    }
    freeStack(stack);
    return EXIT_SUCCESS;
}
