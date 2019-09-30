//Evan Meyerhoff
//This is the only question I'm not extremely sure that I met the conditions.
//Takes char and outputs to screen unless:
// 	1.The character is a space which prints a newline.
//	2.The character is a period which ends the program.

#include <stdio.h>

int main(){
	char input = '\n';
	printf("Insert one character at a time");
	for(;;){//infinite loop that breaks when a period is inputted.
		input= getchar();
		if(input == '.')break;
		if(input == ' ') putchar('\n');
		putchar(input);
	}
}
		
		
		
	
