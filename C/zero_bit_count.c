//Evan Meyerhoff
//CS 306
//Midterm Q1 zero_bit_count.c
//04/18/19
#include <stdio.h>
#include <stdlib.h>

int getzeros(int argv);

int main(int argc, char * argv[]){
	if(argc != 2){
		printf("Nothing to evaluate. Add a value in the command line interface.");
		exit(EXIT_FAILURE);
	}
	// convert string to a decimel. 
	 int output = strtod(argv[1], NULL);
	
	output = getzeros(output);
	printf("The number of zeros is: %d\n", output);
	
}
//getting the from an integer.
int getzeros(int input){
	int count;
	while(input != 0){
	if((input & 1) == 0){
		count++;
		input = (input >>1);	
		}else input = (input >> 1);
	}
	return count;
}
	
