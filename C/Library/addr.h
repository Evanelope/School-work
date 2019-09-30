struct Address{
int stnum;//Street Number
char stname[20];//Street Name
char city[20];// City
char state[10];//2 letter State id
int zip; //member zipcode
};

//Address function declarations
void printaddress(struct Address *addr);
void newaddress(struct Address *addr);

//Address functions begin

void printaddress(struct Address *addr){
	printf("%d %s \n%s, %s %d\n", addr->stnum, addr->stname, addr->city, addr->state, addr->zip);
} 

void newaddress(struct Address *addr){
	printf("What is the street number? ");
	scanf ("%d$", &addr->stnum);
	printf("Name of the street? ");
	scanf ("%s$", addr->stname);
	printf("City? ");
	scanf ("%s$", addr->city);
	printf("State? ");
	scanf ("%s$", addr->state);
	printf("Zip Code? ");
	scanf ("%d$", &addr->zip);
}

