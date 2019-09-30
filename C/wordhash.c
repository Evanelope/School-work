/*
******************************************************************
*   Compile using: gcc -g -Wall -std=gnu99 wordhash.c -o wordhash
******************************************************************
*/
 
#ifndef WORDHASH_H_
	#include "wordhash.h"
#endif

void upper(char * word){
	int count = 0;
	while(*(word + count) !='\0'){
		if(*(word + count) < 122 && *(word + count) > 96){
			*(word + count) -= 32;
		}
		count++;
	}	
	return;
} 

char * gettoken(FILE * fd){
	int i = 0;		
	char temp;
	char * word = malloc(sizeof(char)*20);
	while((temp = fgetc(fd)) != EOF &&
			temp !='\n' &&
			temp != '\t' &&
			temp != ' '){
		if(temp > 96  && temp < 122){
			temp -= 32;
		}			
		*(word + i) = temp;		
		i++;
	}
	*(word + i) = '\0';
	if (word[0] == '\0'){
		return NULL;
	}
	return word;
 }

void init_hash_table(struct hash_entry hash_table[]) {
	for (int i = 0; i < HASH_TABLE_SIZE;i++) {
		hash_table[i].head = NULL;
		hash_table[i].count = 0;
	}

	return;
}


void insert_in_hash_table(struct hash_entry hash_table[], char *token) {
    // This function will insert a token into the correct location
	// of the hash table. The token is inserted at the end of the correct
	// location in the hash table. Note that if there are duplicate tokens,
	// then the linked list will have multiple entries corresponding to each
	// occurrence of the duplicate token.
	
	int pos = token[0] - 65;
	
	struct node temp = {token, hash_table[pos].head};
	hash_table[pos].head = malloc(sizeof(temp));
	*hash_table[pos].head = temp;
	hash_table[pos].count++;
	return;
}

void print_hash_table(struct hash_entry hash_table[]) {
	for (int i = 0;i < HASH_TABLE_SIZE;i++) {
		printf("\n(%c, %d) :: \t",i + 65, (hash_table[i].head != NULL ? hash_table[i].count : 0));		// character value in A-Z range
		struct node * ptr =  hash_table[i].head;
		// Now traverse linked list of hash_table[i]
		while (ptr != NULL) {
			printf("%s --> ",ptr->data);
			ptr = ptr->next;
		}
		printf("NULL\n");
	}

	return;
}

void delete_hash_table(struct hash_entry hash_table[]) {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		if (hash_table[i].head != NULL) {
			struct node *ptr = hash_table[i].head->next;
			struct node *prev = hash_table[i].head;
			do {				
				while(ptr->next->next != NULL){
					prev = ptr;
					ptr = prev->next;
				}
				
				free(ptr->next);
				ptr = prev;
				prev = ptr->next;			
			} while (prev != NULL);
			hash_table[i].head->next = NULL;
		}
		free(hash_table[i].head);
	}
}


int main(int argc, char *argv[]) {
char *word = NULL;
	struct hash_entry hash_table[HASH_TABLE_SIZE];
	init_hash_table(hash_table);	
	FILE *fp = NULL;
	if (argc > 1) {
		if ((fp = fopen(argv[1],"r")) == NULL) {
			fprintf(stderr,"\nError in opening file %s. Exiting...\n",argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	int tokens_count = 0, raw_tokens_count = 0;
	while((word = gettoken(fp)) != NULL){// tests to see if end of file.
		if(
			!(word[0] =='\n' ||// checking to see if token read is empty space.
			word[0] == '\t' ||
			word[0] == ' ' ||
			word[0] == '\0')){				
				printf("made it here too.");
				upper(word);
				++raw_tokens_count;
				// If word starts with a letter, then insert into hash table
				if(word[0] > 64 && word[0] < 91){
					printf("\nToken to insert into hash table: %s", word);
			
					insert_in_hash_table(hash_table, word);
				} else {		// otherwise discard the raw token
					free(word);
					word = NULL;
				}
			
		}
	printf("\nTotal raw tokens found = %d\n", raw_tokens_count);
	printf("\nTotal tokens inserted into hash table = %d\n", tokens_count);
}
	print_hash_table(hash_table);
	fclose(fp);
	return 0;
}
