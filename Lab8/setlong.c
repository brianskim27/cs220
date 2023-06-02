#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

#define SIZE 10


/*The buffer to hold the program state */
jmp_buf env;

/* g is a global variable */
int g = 10;

/* Task 2a: Declare struct var_state here */
struct var_state {
	void *addr;
	unsigned int size;
	struct var_state *next;
	char data[0];
}
*var_state_head = NULL;

/* Task 2b: Implement save_state() */
void save_state(void * var_addr, unsigned int var_size){
	struct var_state *new_node;
	new_node = (struct var_state *)malloc(sizeof(struct var_state) + var_size);
	memset(new_node, 0, sizeof(struct var_state) + var_size);

	new_node->addr = var_addr;
	new_node->size = var_size;
	memcpy(new_node->data, var_addr, var_size);
	new_node->next = var_state_head;
	var_state_head = new_node;
}

/* Task 2b: Implement restore_state() */
void restore_state(){
	struct var_state *curr, *prev;
	curr = prev = var_state_head;
	while(curr) {
		prev = curr;
		memcpy(prev->addr, prev->data, prev->size);
		curr = curr->next;
		free(prev);
	}
}
		
/* Task 1a: Implement signal handler() */
void handler(int signum){
	if(signum = SIGSEGV) {
		longjmp(env, signum);
	}
}

int main()
{
	int x;
	char *p;
	x = 11;
	p = (char *) malloc (SIZE);
	p[0] = p[1] = 'x';

	/* Task 1b: Using the signal function, register a "handler" function as the handler for SIGSEGV */
	signal(SIGSEGV, handler);


	/*Task 2c:  Call save_state on each variable and the array*/
	save_state(&g, sizeof(g));
	save_state(&x, sizeof(x));
	save_state(&p, sizeof(p));
	for(int i = 0; i < sizeof(p); i++) {
			save_state(&p[i], sizeof(p));
	}

	if(!setjmp(env)) {
	  /*This is the "risky" block*/
		g = 30;
		x = 100;
		p = 0;
		p[0] = p[1] = p[2] = 'x';
	} else {
	        restore_state();
		printf("%d, %d, %c, %c\n", g, x, p[0], p[1]);  /* Expected: 10, 11, x, x */
	}
	return 0; 
}

