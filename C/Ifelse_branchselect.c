#include <stdio.h>
void choice(int);
int main()
{
	int user;
	printf("Which branch of the nested else do you want to reach?\n");
	printf("1: Inital if branch\n");
	printf("2: The else if branch\n");
	printf("3: The default else branch\n");
	scanf("%d", &user);
	if(user == 1){
		choice(user);
	}else if(user == 2){
		choice(user);
	}
	else if(user == 3){
		choice(user);
	}
	else{
		choice(user); return 1;
	}
	return 0;
}
void choice(int c){
	switch(c){
		case 1: printf("You chose the 'if' branch!\n"); break;
		case 2: printf("You chose the 'else if' branch!\n"); break;
		case 3:{ printf("You "); 
			printf("chose ");
			printf("the ");
			printf("'else' ");
			printf("branch!\n");
			break;
		}
		default: printf("You entered an invalid number exiting program");
	}
}
