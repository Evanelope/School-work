/*
* Evan Meyerhoff
* Assignment 3 Question 1
* Palindrome question 
* 4/15/19
* CS 306
*/
#include <stdio.h>
#include <stdlib.h>
int string_length(char *input); //Needed string length so I had to make it.



int main(int argc, char *argv[]){
	if(argc !=2){
		printf("Correct command line is palindrome.c STRING \n exiting...");
		exit(EXIT_FAILURE);
	}
	
	int size = string_length(argv[1]);
	
	//compares the the front and back of the string.
	
	for(int i = 0; i < (size/2); i ++){ //If uneven numbers doesn't compare the middle letter.
		// if the numbers don't match just exit the program.
		if(*(argv[1] + i) != *(argv[1] +(size - 1 - i))){			
			printf("This is not a palindrome exiting\n"); exit(EXIT_SUCCESS);
		}
	}
	printf("%s is a palindrome\n", argv[1]);
	
	return 0;
	
}

// goes through string looking for the null character to determine the length.
int string_length(char* input){
	int j = 0;
	for(int i =0; *(input + i) != '\0'; i++){
		j++;
	}
	return j;
}
	

			
