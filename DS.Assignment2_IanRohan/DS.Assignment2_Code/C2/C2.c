#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "stack_linkedlist.h"

// Ian Rohan
// usm404
// 2/8/2024

// Take input (Infix expression) from user and converts the expression
// to Postfix expression (using stacks)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "stack_linkedlist.h"

// Function to convert infix expression to postfix expression
void conversion(char* infix, char* postfix) {
    Stack* stack = createStack();
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                fprintf(stderr, "Invalid expression\n");
                exit(EXIT_FAILURE);
            }
            else {
                pop(stack); // Discard '('
            }
        }
        else {
            while (!isEmpty(stack) && precedence(ch) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, ch);
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
}

int main() {
    printf("Ian Rohan, usm404 <Spring 2024>\n");
    char infix[101], postfix[101]; // Stack for infix and postfix, 0 - 100
    printf("Enter the Infix expression: \n");
    scanf("%s", infix);
    conversion(infix, postfix);
    printf("The Postfix expression: %s\n", postfix);
    printf("End of program");
    return 0;
}
