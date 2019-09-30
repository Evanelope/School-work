//Evan Meyerhoff
//Prints all Natural numbers until the number inputted is reached.
//CS306 3/22/2019


#include <stdio.h>

void natural_numbers(int, int);

int main(){
	int input;
	printf("What number do you want to use?");
	scanf("%d", &input);
	natural_numbers(input, 0);
}
//recursive function to meet requirements.
void natural_numbers(int input, int number){
	if(number != input){
		++number;
		printf("%d\n", number);
		natural_numbers(input, number);
	}
}
	
	
