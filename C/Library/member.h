struct Member {
char MID[20];// Member ID
char FName[20]; // First Name
char LName[20]; //Last Name
struct Address add;
int age;
}library = { .MID ="00000", .FName = "Library", .LName = "Library", .age = 99};


//Member function declarations
void printmember(struct Member *members);
void addmember(struct Member *members);


//Member searching functions
int membersearch(struct Member *members);
int memberxid(char[20], struct Member *members);
int memberxfirst(char[20], struct Member *members);
int memberxlast(char[20], struct Member *members);
int (*memberxparam[])(char[20], struct Member *members) = {memberxid,memberxfirst,memberxlast};
//Member functions.

void printmember(struct Member *member){
	printf("%s: %s %s, Age: %d\n", member->MID, member->FName, member->LName, member->age);
	printaddress(&(member->add));
}


void addmember(struct Member *member){
	printf("First Name: ");
	fgetc(stdin);
	scanf("%s", member->FName);
	printf("Last Name: ");
	scanf("%s", member->LName);
	printf("Age: ");
	scanf("%d", &member->age);
	printf("ID: ");
	scanf("%s", member->MID);
	newaddress(&(member->add));			
}

int membersearch(struct Member *members){
	int select;	
	printf("How do you want to search for a member?\n");
	printf("1. Member ID.\n");
	printf("2. First Name.\n");
	printf("3. Last Name.\n"); 
	scanf("%d", &select);
	printf("\n\n\n\n\n\n");
	switch(select){
		case 1:
		case 2:
		case 3: { 
				char name[20];
				printf("What are you searching for?"); scanf("%s", name);
				select = memberxparam[select -1](name, members);
				return select;
				break; // Pointer function for less clutter.
				}
		default:{
				printf("Not a valid selection %s, let's try again.", ClerkName);
				membersearch(members);
			}
			
	}
	printf("Member not found.");
	return 0;
}

//functions that compare user input with a member.
int memberxid(char *sid, struct Member *members){
	for(int i =0; i < TOTALMEMBERS; i++){
		if(strcmp(((members+i)->MID),sid)!= 0){
			printmember(members+i);
			return i;					
		}
	}
	return 0;
}
	
int memberxfirst(char *sfirst, struct Member *members){
	for(int i =0; i < TOTALMEMBERS; i++){
		if(strcmp(((members+i)->FName),sfirst)==0){
			printmember(members+i);			
			return i;					
		}
	}
	return 0;
}
	
int memberxlast(char *slast, struct Member *members){
	for(int i =0; i < TOTALMEMBERS; i++){
		if(strcmp(((members+i)->LName),slast)==0){
			printmember(members+i);			
			return i;					
		}
	}
	return 0;
}	


