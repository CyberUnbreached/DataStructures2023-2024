#include <stdio.h>

int main() {
	// Created by Ian Rohan at 1/26/24
	// DS Assignment 1 - Question 4
	
	/* Read from the file you created <first_name>.txt
	As output display the content of the file you created and wrote in i.e. file of Q.3 */
	
	FILE* textFile;
	textFile = fopen("Ian.txt", "r");

	char myString[100];
	fgets(myString, 100, textFile);
	printf("%s", myString);

	fclose(textFile);
	return 0;
}