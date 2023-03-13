#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char elements[MAX_LENGTH];
    int top;
} Stack;

bool is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char element) {
    if (stack->top == MAX_LENGTH - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    stack->elements[++stack->top] = element;
}

char pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack->elements[stack->top--];
}

bool is_valid_parentheses(const char *string) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; string[i] != '\0'; i++) {
        char c = string[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&stack, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (is_empty(&stack)) {
                return false;
            } else {
                char top = pop(&stack);
                if (c == ')' && top != '(') {
                    return false;
                } else if (c == ']' && top != '[') {
                    return false;
                } else if (c == '}' && top != '{') {
                    return false;
                }
            }
        }
    }
    return is_empty(&stack);
}

int main(void) {
    char string[MAX_LENGTH];
    printf("Enter a string of parentheses: ");
    scanf("%s", string);
    if (is_valid_parentheses(string)) {
        printf("The string of parentheses is valid.\n");
    } else {
        printf("The string of parentheses is not valid.\n");
    }
    return 0;
}
