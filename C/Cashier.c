#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
struct record{
	int id;
	char name[10];
	double price;
	int quantity;
	double profit;
	
};
void Accept(struct record *records);
void Profit(struct record *records);
void menu();
int cRecords; // Total number of records created.
int main(){
	//structure array variables and allocation.
	struct record *records; //array of records.
	int maxrecords = 5; //current limit on records.
	records = (struct record *)malloc(sizeof(struct record)*maxrecords);	
	
	int select; //menu selection variable

	do{
		menu();
		scanf("%d", &select);
		if(select == 1){ 
			if(cRecords < maxrecords) Accept(records+cRecords);
			else{//too many records. make more space through realloc;
				maxrecords+=5; 
				records = (struct record *)realloc(records, sizeof(struct record)*maxrecords);
				printf("You reached the max on items creating more bufffer.\n");
				Accept(records+cRecords);
			 }
		} // if not maxed on records add new record.
		else if(select == 2) Profit(records);
	}while((select == 1)||(select == 2));		
	printf("Thanks for using the program.");
}

void menu(){
	printf("1. Create a new sales record.\n");
	printf("2. Print out sales report.\n");
	printf("Anything else exits.\n");
}

void Accept(struct record *records){
	printf("What is the id of the item? ");
	scanf("%d", &((*records).id));
	printf("What is the name of the item? ");
	fgetc(stdin); // clear input of the new line character.
	fgets(((*records).name), 10, stdin);
	printf("What is the price of the item? ");
	scanf("%lf", &((*records).price));
	printf("How many were sold?");
	scanf("%d", &((*records).quantity));
	printf("How much do you make per item? ");
	scanf("%lf", &((*records).profit));
	++cRecords;
}

void Profit(struct record *records){
	double total;
	for(int i =0; i<cRecords; i++){
		total += (((*(records+i)).quantity)*((*(records+i)).profit));		
	}
	printf("Total profit is %.2lf", total);
}

