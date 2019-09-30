//Evan Meyerhoff
//Calculates the Factorial of the number given.
//CS306 3/22/2019
#include <stdio.h>
int factorial(int, int);

int main(){
	 int input;
	 printf("What is the number you want to factorial?");
	 scanf("%d", &input);
	 printf("%d", factorial(input,1));	 
	 
 }
//recursive function that returns the factorial.
int factorial(int input, int total){
	if(input !=0){//escape condition;
		total =  input*factorial(input-1, total);
	}
	return total;
	
}
	
