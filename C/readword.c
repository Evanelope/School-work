//Evan Meyerhoff
//CS306 Assignment 3 Question 2
// 04-16-2019
//wc copy.


#include <stdio.h>
#include <stdlib.h>

void upper(char *);
void gettoken(FILE *, char * word);

int main(int argc, char* argv[]){
	char word[50]; // Word read.
	int count = 0; // Word count Variable.
	if(argc != 2){ // Test is right number is inputs.
		printf("Incorrect input.. readword.c  FILENAME");
	}
	
	FILE *fd = fopen(argv[1], "r"); //Create file descriptor.
	
	if(fd == NULL){// Test for successful opening.
		 printf("Unable to open the file\nExiting...");
		 exit(EXIT_FAILURE);
	 }
	
	while(feof(fd) == 0){// tests to see if end of file.		
		gettoken(fd, &word[0]);		
		if(
			!(word[0] =='\n' ||// checking to see if token read is empty space.
			word[0] == '\t' ||
			word[0] == ' ' ||
			word[0] == '\0')){
				
				count++;
				printf("%d Raw token = %s\n",count, word);
				upper(word);
				printf("%d Token: %s\n",count, word);
			}				
		}	
	printf("Total tokens found = %d\n", count); // print the amount of total numbers.
	fclose(fd);		
	return 0;
}
	
	
void gettoken(FILE * fd, char * word){
	int i = 0;		
	char temp;
	while((temp = fgetc(fd)) != EOF &&//seeing if letter read is empty space.
			temp !='\n' &&
			temp != '\t' &&
			temp != ' '){
		*(word + i) = temp;
		i++;
	}

	*(word + i) = '\0';		
}


void upper(char * word){
	int count = 0;
	while(*(word + count) !='\0'){
		if(*(word + count) < 122 && *(word + count) > 96){
			*(word + count) -= 32;
		}
		count++;
	}	
}
