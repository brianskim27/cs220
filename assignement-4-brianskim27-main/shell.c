#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

/*
 * shell() {
 * 	display_prompt(); 
 * 	accept_command(); 
 *
 * 	pid = fork(); 
 * 	if(fork == 0) { //create a child process
 * 		exec(command); //replace the child with the command
 * 	}
 * 	wait_for_the_child(); 
 * }
 */

int main()
{
	char command[1024];	
	char *args[100];

	while(1) {
		printf("hi> "); //prompt
		if(fgets(command, 1023, stdin) == NULL) {
			break;
		}
		if(strcmp(command, "exit\n") == 0) {
			break;
		}
		
		char *p = &command[0]; 
		while(*p != '\n') p++; 
		*p = '\0';
		
		int i = 0;
		char *token;
		token = strtok(command, " ");
		while(token != NULL) {
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		if(!fork()) {
			execvp(args[0], args);
			fprintf(stderr, "Exec failed!\n"); 
			perror(NULL);
		}
		else {
			//this is the parent
			wait(NULL); 
		}
	}


	return 0; 
}


