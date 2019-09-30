#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct Player{
	int wins;
	char *name;
};

int computerthrow();
char throw();
int compare(char,int);
int main(){
	//variables
	char *chars = malloc(2); // using char for easier use with read.
	char *pname;
    char *cname;
 
    //initializing player	
    write(1, "How many characters is your name?", 34);
	read(0, chars , 2);	
    pname = malloc(chars[0]);
	write(1, "What is your name?", 19); 	
	read(0, pname, *chars);	
    
    //initializing computer.
    write(1, "How many characters is the name?", 33);
	read(0, chars , 2);	
    cname = (char*)malloc(chars[0]);
	write(1, "What is your name?", 19); 	
	read(0, cname, *chars);	

    struct Player player = {0,pname};
	struct Player computer = {0,cname};
	
    //structure pointers
	struct Player *pplayer = &player;
	struct Player *pcomputer = &computer;
	
	do{
		switch(compare(throw(),computerthrow())){
		
		case 0: write(1, "This is a tie!\n", 15); break;
		case 1: {
			write(1, pplayer->name, (sizeof(pplayer->name)-2)); 
			write(1, " wins.\n", 6); 
			pplayer->wins +=1;break;
			}
		case 2: {
			write(1, pcomputer->name, sizeof(pcomputer->name)); 
			write(1, "wins.\n", 6);
			pcomputer->wins +=1;break;
			}
		default:  write(1, "Insert a valid number\n", 23);
		}
	}while(((pplayer->wins < 4)&&(pcomputer->wins <4)));
	
}

char throw(){
	char* select = malloc(3);
	write(1, "What do your want to throw?\n", 29);
	write(1, "1. Rock.\n", 10);
	write(1, "2. Paper.\n", 11);
	write(1,"3. Scissors.\n", 14);
	read(0, select, 3);
	return select[0];
}

int computerthrow(){	
return (rand() %3)+1;
}
int compare(char player, int computer){
//player win == 1, computer win == 2; tie == 0

if((player == '1')&&(computer == 1))return 0;
if((player == '1')&&(computer == 2))return 2;
if((player == '1')&&(computer == 3))return 1;
if((player == '2')&&(computer == 1))return 2;
if((player == '2')&&(computer == 2))return 0;
if((player == '2')&&(computer == 3))return 1;
if((player == '3')&&(computer == 1))return 2;
if((player == '3')&&(computer == 2))return 1;
return 3;
}
