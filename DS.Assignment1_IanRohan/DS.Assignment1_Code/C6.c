#include <stdio.h>
#include <string.h>

int main() {
	// Created by Ian Rohan at 1/27/24
	// DS Assignment 1 - Question 6
	
	/* Computes string's length and copy one string into another string
	Use your first name as the string */
	
	char firstName[] = "Ian";
	printf("Name: %s \n", firstName);
	size_t nameLength = sizeof(firstName) - 1;
	printf("String Length: %lu \n", nameLength);

	char copyName[100];
	strcpy(copyName, firstName);
	printf("Copied Name: %s \n", copyName);

	return 0;
}