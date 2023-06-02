#include <stdlib.h>
#include <stdio.h>

struct list {
  //struct list *next;
  unsigned long val;
  struct list *next;
};

extern struct list *reverse_list_asm(struct list *head);

void print_list(struct list *head){
	while(head != NULL) {
		printf("%lu -> ", head->val); 
		head = head->next; 
	}
	printf("NULL\n"); 
}

int main(){
  struct list nodes[4];
  for (unsigned long i = 0; i < 3; i++){
    nodes[i].val = i+1;
    nodes[i].next = &nodes[i+1];
  }
  nodes[3].val = 4;
  nodes[3].next = NULL;
  print_list(&nodes[0]);
  print_list(reverse_list_asm(&nodes[0]));
}

