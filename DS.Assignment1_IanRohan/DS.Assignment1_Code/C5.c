#include <stdio.h>

int main() {
	// Created by Ian Rohan at 1/26/24
	// DS Assignment 1 - Question 5
	
	/* Use the file <first_name>.txt which already have the three digits in it.
	As output the program should print the position of the pointer. */
	
	FILE* textFile;
	textFile = fopen("Ian.txt", "r");

	fseek(textFile, 0, SEEK_END);
	printf("%ld", ftell(textFile));
	
	fclose(textFile);
	return 0;
}