#include <stdio.h>
#include <stdlib.h>

int main() {
	// Created by Ian Rohan at 1/28/24
	// DS Assignment 1 - Question 11
	
	/*  Memory allocation, malloc()
	The programs will take the last 3 digits of your abc as input.
	Assign the 3 digits memory and print the input numbers and memory as output. */
	
	int* ptr;
	int amountElements;
	printf("Enter number of elements(Malloc): ");
	scanf("%d", &amountElements);
	
	ptr = (int*)malloc(amountElements * sizeof(int));

	printf("Enter Elements:\n");
	for (int i = 0; i < amountElements; ++i) {
		scanf("%d", &ptr[i]);
	}
	
	
	for (int i = 0; i < amountElements; ++i) {
		printf("\nMemory Address of %d is %p", ptr[i], (void*)(ptr + i));
	}

	free(ptr);
	
	return 0;
}