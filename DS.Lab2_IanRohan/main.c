#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "stack_linkedlist.h"

// Ian Rohan
// usm404
// 2/8/2024

// Function to check if parentheses are balanced
bool areParenthesesBalanced(char* exp) {
    Stack* stack = createStack();
    char ch;
    for (int i = 0; exp[i] != '\0'; i++) {  // '/0' is Null
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(stack, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(stack)) {
                return false;
            }
            ch = pop(stack);
            if ((ch == '(' && exp[i] != ')') ||
                (ch == '{' && exp[i] != '}') ||
                (ch == '[' && exp[i] != ']')) {
                return false;
            }
        }
    }
    return isEmpty(stack);
}

int main() {
    char exp[101]; // 0 to 100
    printf("Enter a string of parentheses: ");
    scanf("%s", exp);
    if (areParenthesesBalanced(exp)) {
        printf("Given sequence of parenthesis is balanced\n");
    }
    else {
        printf("Given sequence of parenthesis is unbalanced\n");
    }
    return 0;
}
