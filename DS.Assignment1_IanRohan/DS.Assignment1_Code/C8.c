#include <stdio.h>
#include <string.h>

int main() {
	// Created by Ian Rohan at 1/27/24
	// DS Assignment 1 - Question 8
	
	/* Compares two strings
	Use your last name to compare */
	
	char firstName[] = "Ian";
	char lastName[] = "Rohan";
	printf("Name: %s %s\n", firstName, lastName);

	int compareName = strcmp(firstName, lastName);
	printf("Compared: %d\n", compareName);

	return 0;
}