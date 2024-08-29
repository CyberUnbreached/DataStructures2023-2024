#include <stdio.h>

int main() {
	// Created by Ian Rohan at 1/25/24
	// DS Assignment 1 - Question 1
	
	/* Create <first_name>.txt file of your name
	As output display the file name and location of the file created */
	FILE* textFile;
	textFile = fopen("Ian.txt", "w");
	printf("Text File \"Ian.txt\" created at C:\\Users\\usm404\\source\\repos\\DS_Assigment1\\DS_Assigment1\n");
	fclose(textFile);

	return 0;
}