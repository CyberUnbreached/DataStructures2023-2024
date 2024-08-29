#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack_linkedlist.h"


// Ian Rohan
// usm404
// 2/20/2024

// Function to insert an element at the bottom of a stack
void insertAtBottom(Stack* stack, int data) {
    if (isEmpty(stack)) {
        push(stack, data);
    }
    else {
        int temp = pop(stack);
        insertAtBottom(stack, data);
        push(stack, temp);
    }
}

// Function to reverse a stack using recursion
void reverseStack(Stack* stack) {
    if (!isEmpty(stack)) {
        int temp = pop(stack);
        reverseStack(stack);
        insertAtBottom(stack, temp);
    }
}

// Function to display the elements of the stack
void displayReverse(Stack* stack) {
    if (!isEmpty(stack)) {
        int temp = pop(stack);
        displayReverse(stack);
        printf("%d ", temp);
        push(stack, temp);
    }
}

int main() {
    Stack* stack = createStack();

    int n, data;
    printf("Enter the number of elements to insert into the stack: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        push(stack, data);
    }

    reverseStack(stack);

    printf("\nReversed stack: ");
    displayReverse(stack);
    printf("\n");

    return 0;
}
