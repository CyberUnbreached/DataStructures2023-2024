#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H

#include <stdbool.h>

// Ian Rohan
// usm404
// 2/8/2024

// Define Node structure
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Define Stack structure
typedef struct {
    Node* top;
} Stack;

// Function prototypes
Stack* createStack();
bool isEmpty(Stack* stack);
void push(Stack* stack, char data);
char pop(Stack* stack);
int precedence(char ch);
char peek(Stack* stack);

#endif
