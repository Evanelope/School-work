/* Project 2 Library assignment
 * Evan Meyerhoff
 * 3/22/2019
 * CS221
 * 
 * Structures are in there own header files with helper functions.
 * The exception is the removemember function explained at function. 
 * 
 * Tried using fgets to get strings with spaces but couldn't get the 
 * trailing endline off without copying some code.
 * 
 * String elements do not take multiple word strings. 
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>	


//Global Variables
int TOTALMEMBERS = 0;// Total number of members in the library.
int TOTALBOOKS = 0; //	Total number of books in the library.

int memsize = 5;   //   |\amount of malloc for structure arrays.
int booksize = 5;  //   |/

char ClerkName[20]; //Name of the clerk who has registered the customer


//Header files containing functions for each struct; made for modularity.
#include "addr.h"
#include "member.h"
#include "book.h"


//Main function declarations; 
void mainswitch(int select, struct Book *books, struct Member *members);
void initialmenu();
int mainmenu();
void removemember(struct Member *members, struct Book *books);

int main(){
	
	int select;

	//Allocate initial amount of memory for the struct arrays.
	struct Member *members = (struct Member *)malloc(sizeof(struct Member)*memsize);
	struct Book *books = (struct Book *)malloc(sizeof(struct Book)*booksize); 
	
	
	initialmenu();	
	do{ // reruns options until exited.
		select = mainmenu();
		mainswitch(select, books, members);
	}while(select != 0);	
	return 0;
}

//Prints the main menu.
int mainmenu(){
	int select;
	printf("1. Borrow a book.\n");
	printf("2. Return a book.\n");
	printf("3. New Member Registration.\n");		
	printf("4. Revoke Membership.\n");		
	printf("5. Search for a book.\n");
	printf("6. Find a Member.\n");
	printf("0. Log out\n");	
	scanf("%d", &select);
	return select;
}
 
//beginning of helper functions.	
void mainswitch(int select, struct Book *books, struct Member *members){
	printf("\n\n\n\n\n\n\n\n\n\n");
	switch(select){
		/*
			*case 1 tests if the there is enough memory allocated for the book and if there
			*isn't it will allocate more.  
		*/	
		case 1: {
				select = membersearch(members);
								
				if(TOTALBOOKS == booksize){
					booksize +=5;
					books = realloc(books, sizeof(struct Book)*booksize);
				}
				addbook(books+TOTALBOOKS, *(members + select));
				TOTALBOOKS++;	
				break;		
			}
		case 2: returnbook(books);break;
		/*
			Same as with case one but with the members array. 
		*/	
		case 3: {if(TOTALMEMBERS == memsize){
					memsize +=5;
					members = realloc(members, sizeof(struct Member)*memsize);
				}
				addmember(members+TOTALMEMBERS);	
				TOTALMEMBERS++;			
				break;
			}
		case 4: removemember(members, books);break;
		case 5: booksearch(books);break;
		case 6: membersearch(members);break;
		case 0: printf("If you aren't logged in you aren't getting paid!\n"); break;
		default: printf("Please %s, we've been over this.. please insert a value listed..\n", ClerkName);
	}
}

//login screen gets the Clerks Name.	
void initialmenu(){
	printf("Welcome to the Library Management System(LMS)\n");
	printf("Please insert you name. ");
	scanf("%s", ClerkName);
	printf("Hello %s, get to work already.\n\n\n\n\n\n", ClerkName);
}

/* 	
    *Had to put into main because my book header comes after book header
	*Checks to see if member has a book and if he does he can't be removed until 
	*all books are returned. 
*/
void removemember(struct Member *members, struct Book *books){
	int check = membersearch(members);
	printf("\n\n\n\n\n\n\n\n\n");
	char own;
	for(int i= 0; i<TOTALBOOKS; i++){
		if(strcmp((((books + i)->own).FName),(members+check)->FName) == 0){
			
			
			printbook(books+i);
			printf("\n\nThey still owns a book. He must return it before he can be removed.\n");
			own = 1;
		}
	}       
	if(own != 1){
		printf("Removed.\n");
		*(members+check) = library;
	}
}
	
	
