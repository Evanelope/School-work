//Evan Meyerhoff
//CS 306
//Assignment 4

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
	
	//valid amount of argument check.
	if(argc < 2 || argc > 5){
		printf("Invalid number of arguments, 1-4 arguments");
		exit(EXIT_SUCCESS);
	}
	
	char input[1]; //the character read.
	int red = 1; //characters read count...
	int pipes[4][2]; //pipes for children.

	//making the pipes for files.
	for(int i = 0; i < argc -1; i++){
		pipe(pipes[i]);
	}				
	
	pid_t pids[argc-1];
		
	//loop through filenames giving each fork the number of file to run ls on.
	//did filenumber == 1 so i can do argv[i] when associating file names.
	for(int filenumber = 0; filenumber < argc-1; filenumber++){
		
		//create fork and check for fail condition.
		if((pids[filenumber] = fork()) == -1){
			printf("Fork failed for file %s", argv[filenumber + 1]);
			exit(EXIT_FAILURE);
		}		
		
		//parent tree.
		if(pids[filenumber] > 1){			
			close(pipes[filenumber][1]);//close write end of pipe
			wait(NULL);//wait for the child created.
			while((red = read(pipes[filenumber][0], input, 1)) > 0){
				write(1, input, 1);	// writes read end of pipe.
			}
		}	
		
		//child tree.			
		if(pids[filenumber] == 0){
			close(pipes[filenumber][0]);// close read pipe end.
			dup2(1, pipes[filenumber][1]); //dupping output to stdout		
			execlp("ls", "ls", "-l", argv[filenumber+1], NULL); //printint ls-l to stdout			
			printf("Program still running error occured Exiting");//exec fail check.
			exit(EXIT_FAILURE);
		}
		
		close(pipes[filenumber][0]);//close remaining pipes.
	}
		
}	
