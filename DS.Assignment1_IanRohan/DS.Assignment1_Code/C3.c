#include <stdio.h>

int main() {
	// Created by Ian Rohan at 1/25/24
	// DS Assignment 1 - Question 3
	
	/* Write the three digits of your abc in the file you created <first_name>.txt
	(i.e. abc123, you should write ‘123’ in the file) As output display the location of the file*/
	
	FILE* textFile;
	textFile = fopen("Ian.txt", "w");
	fprintf(textFile, "404");
	printf("Text File \"Ian.txt\" edited at C:\\Users\\usm404\\source\\repos\\DS_Assigment1\\DS_Assigment1\n");
	fclose(textFile);
	return 0;
}