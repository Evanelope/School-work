 
 struct Book{
char title[20]; //Book Title
char author[20];//Book Author
char publisher[20];//Book publisher
int date; // Publication date
struct Member own;// Owner of the book or null if unregistered.
}; 
 
 
 // Book function declarations
int booksearch(struct Book *books);
void addbook(struct Book *book, struct Member members);
void printbook(struct Book *book);
void returnbook(struct Book *book);
void printall(struct Book *book);
void booksavailable(struct Book *books);

//book searching function declarations.
int bookxdate(void *input,struct Book *books);
int bookxtitle(void *input, struct Book *books);
int bookxauthor(void *input, struct Book *books);
int bookxpublish(void *input, struct Book *books);

//search function pointer.
int bookxparam[](void *input, struct Book *books) = {bookxtitle,bookxauthor,bookxpublish,bookxdate};


// Book searching menu.
int booksearch(struct Book *books){
	int select;
	printf("How do you want to search for a book?\n");
	printf("1. Title.\n");
	printf("1. Author.\n");
	printf("3. Publisher.\n");
	printf("4. Pub Date.\n"); 
	scanf("%d", &select);
	switch(select){
		case 1:
		case 2:
		case 3: {  // selections that result in searching with a string.
				char name[20];
				printf("What are you searching for?"); scanf("%s", name);
				printf("\n\n\n");				
				select = bookxparam[select -1](name, books); // Pointer function for less clutter
				printf("\n\n");
				return select;
				break;
				}
		case 4: {
				printf("What are you searching for?"); scanf("%d", &select);				 
				//select = bookxdate(&select, books);
				select = bookxparam[select -1](&select, books);
				if(select != 0) return select;
				break;
				}
		default:{
				printf("Not a valid selection %s, let's try again.\n", ClerkName);
				booksearch(books);
			}
	}
	printf("Book not found.");
	
	return 0;
}

// Book searching functions returning the array number of the book class.
int bookxdate(void *sdate, struct Book *books){
	int *input = (int*)sdate;
	for(int i =0; i < TOTALBOOKS; i++){
		if(((books+i)->date)== *input){
			printbook(books+i);			
			return i;					
		}
	}
	return 0;
}

int bookxtitle(void *stitle, struct Book *books){
	for(int i =0; i < TOTALBOOKS; i++){
		if(strcmp(((books+i)->title),stitle)==0){
			printbook(books+i);			
			return i;					
		}
	}
	return 0;
}

int bookxauthor(void *sauthor, struct Book *books){
	char *input = (char*)sauthor;
	for(int i =0; i < TOTALBOOKS; i++){
		if(strcmp(((books+i)->author),input)==0){
		printbook(books+i);			
			return i;					
		}
	}
	return 0;
}	
int bookxpublish(void *spublish, struct Book *books){
	char *input = (char*)spublish;
	for(int i =0; i < TOTALBOOKS; i++){
		if(strcmp(((books+i)->publisher),input) == 0){
			printbook(books+i);			
			return i;					
		}
	}
	return 0;
}	


//Book printing functions
void printbook(struct Book *book){
	printf("Title: %s\nAuthor: %s\nPublisher: %s\nDate: %d\n", book->title, book->author, book->publisher, book->date);
	printmember(&(book->own));
}

//book add and return functions.
void addbook(struct Book *book, struct Member members){
   printf("Book Name? ");
   scanf("%s", book->title);
   printf("Book Author? ");
   scanf("%s", book->author);
   printf("Book Publisher? ");
   scanf("%s", book->publisher);
   printf("Publishing date? ");
   scanf("%d", &(book->date));
   (book->own) = members; 
   
}
//books returned are in possession of the library.
void returnbook(struct Book *book){
	 printf("Let's first find the book.\n");
	 (book + booksearch(book))->own = library; 	
}

/*void booksavailable(struct Book *books){
	for(int i =0; i<TOTALBOOKS; i++){
		if((books+i)->own.FName == library.FName){
			printbook(books+i);
		}
	}
}
void printall(struct Book *books){
	for(int i=0; i<TOTALBOOKS; i++){
		printbook(books + i);
		printf("\n\n");
	}
}
*/
