#include "stack_linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// Ian Rohan
// usm404
// 2/20/2024

// Function to create a new node
Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, char data) {
    Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    char data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}
