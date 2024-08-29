#include <stdio.h>

int main() {
	// Created by Ian Rohan at 1/25/24
	// DS Assignment 1 - Question 2
	
	/* Open and close the file you created <first_name>.txt
	As output display the location of the file opened and closed*/
	FILE* textFile;
	textFile = fopen("Ian.txt", "r");
	printf("Text File \"Ian.txt\" opened at C:\\Users\\usm404\\source\\repos\\DS_Assigment1\\DS_Assigment1\n");
	fclose(textFile);
	printf("Text File \"Ian.txt\" closed at C:\\Users\\usm404\\source\\repos\\DS_Assigment1\\DS_Assigment1\n");

	return 0;
}