//Evan Meyerhoff
//Program that prints the Fibonacci numbers up until the number given.
//3/22/2019
//CS306

#include <stdio.h>

int main(){
	int input;
	int prior = 0;
	int current = 1;
	int temp;
	
	printf("How many Finbonacci numbers do you want?");
	scanf("%d", &input);
	
	for(int i = 0; i < input; i++){
		printf("%d \n", current);
		temp = current;
		current += prior;
		prior = temp;
	}
}
		
	
