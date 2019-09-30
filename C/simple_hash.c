#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void getword(FILE * fd, char * word);
void string_n_copy(char * original, char * copy);
void clearmem(char ** alpha, int * amounts);

void printhash(char *** alpha, int * amounts);
int main (int argc, char * argv[]){
	//main variables
	int pos;
	int amounts[26];
	char this[] = "Hello";
	char * alpha[26][100];
	
	if(argc != 2){ // Test for right number is inputs.
		printf("Incorrect input.. executable  textfile.txt\n EXITING");
		exit(EXIT_FAILURE);
	}
	
	FILE *fd = fopen(argv[1], "r"); //Create file descriptor.
	if(fd == NULL){// Test for successful opening.
		 printf("Unable to open the file\nExiting...");
		 exit(EXIT_FAILURE);
	 }	
	 
	 
	 
	 
	 //reading words into the hash table
	 while(feof(fd) ==0){
		getword(fd, this);
		if(this[0] != '\0'){
			pos = this[0] - 65;
			if(amounts[pos] != 100){
			alpha[pos][amounts[pos]] = (char*)malloc(sizeof(this)+1); 
			string_n_copy(this, alpha[pos][amounts[pos]]);
			amounts[pos]++;
		}else printf("You have maxed out the letter %c =(", pos + 65); 
			
		}
	}
	
	
	
	//printing off the hash table
	/*for(int i = 0; i < 26; i++){
		printf("%c ", i+65);
		for(int j = 0; j < amounts[i]; j++){
			printf("-> %s ", alpha[i][j]);
		}		
		printf("\n");
	}*/
	printhash(*alpha, amounts);
	//clearing the dynamic memory.
	clearmem(*alpha, amounts);
	fclose(fd);
	return 0;
}

void printhash(char *** alpha, int * amounts){
	/*for(int i = 0; i < 26; i++){
		printf("%c ", i+65);
		for(int j = 0; j < amounts[i]; j++){
			printf("-> %s ", alpha[i][j]);
		}		
		printf("\n");
	}*/
	for(int i = 0; i < 26; i++){
		printf("%c ", i+65);
		for(int j = 0; j < amounts[i]; j++){
			printf("-> %s ", alpha[i][j]);
		}
		printf("\n");
	}
}

void clearmem(char ** alpha, int* amounts){
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < amounts[i]; j++){
			free(&alpha[i][j]);
		}
	}
}

//function to get individual words from file.
void getword(FILE * fd, char * word){
	int i = 0;		
	char temp;
	while((temp = fgetc(fd)) != EOF &&
			temp !='\n'){

		if(temp >= 96  && temp <= 123){
			temp -= 32;
		}	
		*(word + i) = temp;
		
		i++;
	}
	*(word + i) = '\0';
}
//string copy method.
void string_n_copy(char * original, char * copy){
	int i = 0;		
	char temp;
	while((temp = *(original + i)) != '\0'){
		*(copy + i) = temp;
		i++;
	}
	*(copy + i) = '\0';
}

		
