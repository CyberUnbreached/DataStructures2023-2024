#include <stdio.h>
#include <string.h>

int main() {
	// Created by Ian Rohan at 1/27/24
	// DS Assignment 1 - Question 7
	
	/* Concatenates(joins) two strings
	Use your first and last name as strings */
	
	char firstName[] = "Ian ";
	char lastName[] = "Rohan";
	char combinedName[50] = "";

	strcat(combinedName, firstName);
	strcat(combinedName, lastName);
	printf("Name: %s", combinedName);

	return 0;
}