//Evan Meyerhoff
//CS 306
//Question 2 string_insert.c
//4/18/19

#include <stdio.h>
#include <stdlib.h>

int string_length(char* input);



int main(int argc, char * argv[]){
	// main variables.
	int location, strOnelen, strTwolen;
	
	//testing for failure conditions.
	if(argc != 4){
		printf("Incorrect number of arguements\n");
		exit(EXIT_FAILURE);
	}
	
	//initializing variables.
	location = strtod(argv[2], NULL);	
	strOnelen = string_length(argv[1]);
	strTwolen = string_length(argv[3]);
		
	//Testing if string 1 is long enough for injection.
	if(strOnelen < location){
		printf("The first string is shorter than %d\n", location);
		exit(EXIT_FAILURE);
	}
	
	//initialize output variable
	char * output =  (char *)malloc(((strOnelen) * sizeof(char) + (strTwolen) * sizeof(char)));	
	
	//New string creation
	//assigns values up to location from first string.
	for(int i = 0; i < location; i++){
		*(output + i) = *(argv[1] + i);
	}
	
	//adds second string.
	int strloc = 0;//variable to keep track within string.
	for(int i = location; i < (location + strTwolen); i++){
		
		*(output + i) =  *(argv[3] + strloc);
		strloc++;
	}
	
	//finishes the first string.
	strloc = 0;
	for(int i = location + strTwolen; i<= (strOnelen + strTwolen) ; i++){
		*(output + i) =  *(argv[1] + location + strloc);
		strloc++;
	}
	printf("The new word is: %s\n", output);
	
}	
	
int string_length(char* input){
	int j = 0;
	for(int i =0; *(input + i) != '\0'; i++){
		j++;
	}
	return j;
}
