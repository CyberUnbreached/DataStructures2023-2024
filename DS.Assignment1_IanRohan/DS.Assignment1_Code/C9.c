#include <stdio.h>
#include <string.h>

int main() {
	// Created by Ian Rohan at 1/28/24
	// DS Assignment 1 - Question 9
	
	/* Converts string to lowercase
	Use your last name as string */
	
	char lastName[] = "Rohan";
	printf("Last Name: %s\n", lastName);

	printf("Converted Name: %s", _strlwr(lastName));

	return 0;
}