#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int val; 
	struct node *next;
};
typedef struct node Node; 

/* Do not alter print_list or print_2darray functions */
void print_list(Node *node)
{
	while(node) {
		printf("%d -> ", node->val); 
		node = node->next; 
	}
	printf("NULL\n"); 
}

void print_2darray(int ** m, unsigned int * arr, unsigned int rows){
  if(arr == NULL || rows == 0){
    printf("NULL\n");
    return;
  }
  printf("[");
  for(int i = 0; i<rows; i++){
    if (arr[i] == 0) printf("NULL");
    else{
      printf("[");
      for(int j = 0; j < arr[i]; j++){
	printf("%d", m[i][j]);
	if (j != arr[i]-1){
	  printf(",");
	}
      }
      printf("]");
    }
    if(i != rows-1){
      printf(",");
    }
  }
  printf("]\n");

}

unsigned int count_nodes(struct node *head){
  int count = 0;
  
  while(head != NULL) {
	  head = head->next;
	  count++;
  }

  return count;
}

Node **split_list(Node *head, unsigned int num){
  Node **ptr;
  for(int i = 0; i < num; i++) {
	  ptr[i] = NULL;
  }

  int j = 0;
  Node *current = head;
  while(current != NULL) {
	  if(ptr[j % num] == NULL) {
		  ptr[j % num] = current;
		  current = current->next;
		  ptr[j % num]->next = NULL;
	  }
	  else {
		  Node* temp = ptr[j % num];
		  while(temp->next != NULL) {
			  temp = temp->next;
		  }
		  temp->next = current;
		  current = current->next;
		  temp = temp->next;
		  temp->next = NULL;
	  }
	  
	  j++;
  }	
	
  return ptr;
}

void addNode(Node *head, Node *node) {
  node->next = head->next->next;
  head->next = node;
}
  
Node *deleteNode(Node *head) {
  Node *del_Node = head->next;
  Node *new_Node =  malloc(sizeof(Node));
  new_Node->next = head->next->next;
  head->next = new_Node;
  
  return del_Node;
}

Node *node_swap(Node *head, unsigned int index1, unsigned int index2){
  Node *node1 = NULL, *node2 = NULL, *head2 = head, *head3 = head;
 
  if(head == NULL) {
	  return head;
  }
  if(index1 == index2) {
	  return head;
  }
  if(index1 > index2) {
	 int temp = index2;
	 index2 = index1;
	 index1 = temp;
  }
  if(index2 - index1 > 10) {
	  return head;
  }
  int count = 0;
  while(head2 != NULL && head2->next != NULL) {
	  if(count == index1) {
		  if(index1 = 0) {
			  node1 = head;
		  }
		  else {
			  node1 = deleteNode(head);
		  }
	  }
	  if(count == index2) {
		  node2 = deleteNode(head);
	  }
	  head2 = head2->next;
	  count++;
  }
  
  count = 0; 
  while(head3 != NULL && head3->next != NULL) {	  
	  if(index1 = 0) {
		  head = node2;
	  }
	  if(count + 1 == index1) {
		  addNode(head3, node2);
	  }
	  if(count + 1 == index2) {
		   addNode(head3, node1);
	  }
	  head3 = head3->next;
	  count++;
  }
  return head;
}

Node *interleave_list(Node *head1, Node *head2)
{
  Node *res, *temp1, *temp2;

  if(!head1) {
	 return head2;
  }
  if(!head2) {
	 return head1;
  }
  
  res = head1;
  while(head1 != NULL && head2 != NULL) {
	 temp1 = head1->next;
	 temp2 = head2->next;

	 if(head1->next) {
		head2->next = head1->next;
	 }
 	
	 head1->next = head2;
	 head1 = temp1;
	 head2 = temp2;
  }

  return res; 
}



int get_float_exponent(float f){
  u_int32_t *i = (u_int32_t *) &f;
 
  if(f == 0.0) {
	  return ((*i >> 23) & 255);
  }
  else {
  	  return (((*i >> 23) & 255) - 127);
  }
}

int **custom_2dallocator(unsigned int *arr, unsigned int rows){ 
  int cols;
  int **ret;
  ret = (int **) malloc(sizeof(int) * rows * cols);
  
  if(ret == NULL) {
	  return NULL;
  }
  for(int i = 0; i < rows; i++) {
	  cols = arr[i];
	  if(arr[i] = 0) {
		  ret == NULL;
	  }
	  *(ret + i) = (int *) malloc(sizeof(int *) * rows * cols);
  }
  return ret; 
}

/* Make no changes to the code below this point */
int main(int argc, char * argv[])
{
  #define NUM_NODES 2
  Node nodes[NUM_NODES];
  int i; 
  for(i = 0; i < NUM_NODES-1; i++) {
    nodes[i].val = i+1; 
    nodes[i].next = &nodes[i+1];
  }		
  nodes[NUM_NODES-1].next = NULL; 
  nodes[NUM_NODES-1].val = NUM_NODES+1; 

  Node yet_another_list[1];
  yet_another_list[0].val = 1;
  yet_another_list[0].next = NULL;

  Node nodes2[4]; 
  for(int i = 0; i < 3; i++) {
    nodes2[i].val = i+1; 
    nodes2[i].next = &nodes2[i+1];
  }		
  nodes2[3].next = NULL; 
  nodes2[3].val = 4;

  //Q1
  if (argc == 2 || argc == 1){
    printf("Test cases for Question 1:\n\n");
    printf("List: ");
    print_list(&nodes[0]);
    printf("Number of nodes in list: %d\n\n", count_nodes(&nodes[0]));
    printf("List: ");
    print_list(NULL);
    printf("Number of nodes in list: %d\n\n", count_nodes(NULL));
    printf("List: ");
    print_list(&yet_another_list[0]);
    printf("Number of nodes in list: %d\n\n", count_nodes(&yet_another_list[0]));
  }

  //Q2
  if (argc == 3 || argc == 1){
    printf("Test cases for Question 2:\n\n");
    printf("head: NULL\nnum = 1\n");
    Node ** split2 = split_list(NULL,1);
    printf("ret[0] = ");
    print_list(split2[0]);
    printf("\n");

    printf("head: ");
    print_list(&nodes2[0]);
    printf("num = 1\n");
    Node **split1 = split_list(&nodes2[0], 1);
    printf("ret[0] = ");
    print_list(split1[0]);
    printf("\n");

    for(int i = 0; i < 3; i++) {
      nodes2[i].val = i+1; 
      nodes2[i].next = &nodes2[i+1];
    }		
    nodes2[3].next = NULL; 
    nodes2[3].val = 4;
    
    printf("head: ");
    print_list(&nodes2[0]);
    printf("num = 2\n");
    Node ** split3 = split_list(&nodes2[0],2);
    printf("ret[0] = ");
    print_list(split3[0]);
    printf("ret[1] = ");
    print_list(split3[1]);
    printf("\n");

    for(int i = 0; i < 3; i++) {
      nodes2[i].val = i+1; 
      nodes2[i].next = &nodes2[i+1];
    }		
    nodes2[3].next = NULL; 
    nodes2[3].val = 4;
    
    printf("head: ");
    print_list(&nodes2[0]);
    printf("num = 3\n");
    Node ** split4 = split_list(&nodes2[0],3);
    printf("ret[0] = ");
    print_list(split4[0]);
    printf("ret[1] = ");
    print_list(split4[1]);
    printf("ret[2] = ");
    print_list(split4[2]);
    printf("\n");

    for(int i = 0; i < 3; i++) {
      nodes2[i].val = i+1; 
      nodes2[i].next = &nodes2[i+1];
    }		
    nodes2[3].next = NULL; 
    nodes2[3].val = 4;


    printf("head: ");
    print_list(&nodes2[0]);
    printf("num = 4\n");
    Node ** split5 = split_list(&nodes2[0],4);
    printf("ret[0] = ");
    print_list(split5[0]);
    printf("ret[1] = ");
    print_list(split5[1]);
    printf("ret[2] = ");
    print_list(split5[2]);
    printf("ret[3] = ");
    print_list(split5[3]);
    printf("\n");

    for(int i = 0; i < 3; i++) {
      nodes2[i].val = i+1; 
      nodes2[i].next = &nodes2[i+1];
    }		
    nodes2[3].next = NULL; 
    nodes2[3].val = 4;

    printf("head: ");
    print_list(&nodes2[0]);
    printf("num = 6\n");
    Node **split6 = split_list(&nodes2[0], 6);
    printf("ret[0] = ");
    print_list(split6[0]);
    printf("ret[1] = ");
    print_list(split6[1]);
    printf("ret[2] = ");
    print_list(split6[2]);
    printf("ret[3] = ");
    print_list(split6[3]);
    printf("ret[4] = ");
    print_list(split6[4]);
    printf("ret[5] = ");
    print_list(split6[5]);
    printf("\n");

  }

  //Q3
  
  if (argc == 4 || argc == 1){
    printf("Test cases for Question 3:\n\n");
    int n=3;
    Node nodes3[n]; 
    for(int j = 0; j < n-1; j++) {
      nodes3[j].val = j+1; 
      nodes3[j].next = &nodes3[j+1];
    }		
    nodes3[n-1].next = NULL; 
    nodes3[n-1].val = n;

    printf("head: ");
    print_list(&nodes3[0]);
    Node *swapped1 = node_swap(&nodes3[0], 0, 0);
    printf("index1 = 0, index2 = 0\n");
    printf("result: ");
    print_list(swapped1);
    printf("\n");

    printf("head: ");
    print_list(&nodes3[0]);
    Node *swapped2 = node_swap(&nodes3[0], 0, 1);
    printf("index1 = 0, index2 = 1\n");
    printf("result: ");
    print_list(swapped2);
    printf("\n");

     for(int j = 0; j < n-1; j++) {
      nodes3[j].val = j+1; 
      nodes3[j].next = &nodes3[j+1];
    }		
    nodes3[n-1].next = NULL; 
    nodes3[n-1].val = n;

    printf("head: ");
    print_list(&nodes3[0]);
    Node *swapped3 = node_swap(&nodes3[0], 0, 2);
    printf("index1 = 0, index2 = 2\n");
    printf("result: ");
    print_list(swapped3);
    printf("\n");

    printf("head: ");
    print_list(&nodes2[0]);
    Node *swapped4 = node_swap(&nodes2[0], 2, 1);
    printf("index1 = 2, index2 = 1\n");
    printf("result: ");
    print_list(swapped4);
    printf("\n");
    
    for(int j = 0; j < n-1; j++) {
      nodes3[j].val = j+1; 
      nodes3[j].next = &nodes3[j+1];
    }		
    nodes3[n-1].next = NULL; 
    nodes3[n-1].val = n;

    printf("head: ");
    print_list(&nodes3[0]);
    Node *swapped5 = node_swap(&nodes3[0], 0, 11);
    printf("index1 = 0, index2 = 11\n");
    printf("result: ");
    print_list(swapped5);
    printf("\n");
  }
    
  //Q4
  if (argc == 5 || argc == 1){
    Node head1[3];
    Node head2[2];

    printf("Test cases for Question 4:\n\n");

    head1[0].val = 1;
    head1[0].next = &head1[1];
    head1[1].val = 3;
    head1[1].next = NULL;

    head2[0].val = 2;
    head2[0].next = &head2[1];
    head2[1].val = 4;
    head2[1].next = NULL;

    printf("head1 = ");
    print_list(&head1[0]);
    printf("head2 = ");
    print_list(&head2[0]);
    printf("result = ");
    Node * interleave1 = interleave_list(&head1[0], &head2[0]);
    print_list(interleave1);
    printf("\n");

    printf("head1 = ");
    print_list(NULL);
    printf("head2 = ");
    print_list(NULL);
    printf("result = ");
    Node * interleave2 = interleave_list(NULL, NULL);
    print_list(interleave2);
    printf("\n");

    head2[0].val = 1;
    head2[0].next = NULL;

    printf("head1 = ");
    print_list(NULL);
    printf("head2 = ");
    print_list(&head2[0]);
    printf("result = ");
    Node * interleave3 = interleave_list(NULL, &head2[0]);
    print_list(interleave3);
    printf("\n");

    head1[0].val = 1;
    head1[0].next = &head1[1];
    head1[1].val = 2;
    head1[1].next = &head1[2];
    head1[2].val = 3;
    head1[2].next = NULL;

    head2[0].val = 3;

    printf("head1 = ");
    print_list(&head1[0]);
    printf("head2 = ");
    print_list(&head2[0]);
    printf("result = ");
    Node * interleave4 = interleave_list(&head1[0], &head2[0]);
    print_list(interleave4);
    printf("\n");
    
  }

  //Q5

  if(argc == 6 || argc == 1){
    float x;
    int exp;
    printf("Test cases for Question 5:\n\n");
    
    x = -23455.232;
    exp = get_float_exponent(x);
    printf("float: %f, exponent = %d\n\n",x,exp);

    x = 0;
    exp = get_float_exponent(x);
    printf("float: %f, exponent = %d\n\n",x,exp);

    x = -12E-8;
    exp = get_float_exponent(x);
    printf("float: %f, exponent = %d\n\n",x,exp);

    x = 2.0;
    exp = get_float_exponent(x);
    printf("float: %f, exponent = %d\n\n",x,exp);
    
    

  }

  //Q6

  if (argc == 7 || argc == 1) {
    printf("Test cases for Question 6:\n\n");
    unsigned int rows1 = 4;
    unsigned int arr1[4] = {1,2,3,4}; 
    int ** m1 = custom_2dallocator(arr1, rows1);
    printf("arr = [1,2,3,4], rows = 4\n");
    printf("Memory layout:");
    print_2darray(m1, arr1, rows1);
    printf("\n");

    unsigned int rows2 = 1;
    unsigned int arr2[1] = {1}; 
    int ** m2 = custom_2dallocator(arr2, rows2);
    printf("arr = [1], rows = 1\n");
    printf("Memory layout:");
    print_2darray(m2, arr2, rows2);
    printf("\n");

    unsigned int rows3 = 4;
    unsigned int arr3[4] = {1,3,0,2}; 
    int ** m3 = custom_2dallocator(arr3, rows3);
    printf("arr = [1,3,0,2], rows = 4\n");
    printf("Memory layout:");
    print_2darray(m3, arr3, rows3);
    printf("\n");

    unsigned int rows4 = 0;
    unsigned int * arr4 = NULL; 
    int ** m4 = custom_2dallocator(arr4, rows4);
    printf("arr = NULL, rows = 0\n");
    printf("Memory layout:");
    print_2darray(m4, arr4, rows4);
    printf("\n");
    
    unsigned int rows5 = 10;
    unsigned int * arr5 = NULL; 
    int ** m5 = custom_2dallocator(arr5, rows5);
    printf("arr = NULL, rows = 10\n");
    printf("Memory layout:");
    print_2darray(m5, arr5, rows5);
    printf("\n");

    unsigned int rows6 = 0;
    unsigned int arr6[2] = {1,2}; 
    int ** m6 = custom_2dallocator(arr6, rows6);
    printf("arr = [1,2], rows = 0\n");
    printf("Memory layout:");
    print_2darray(m6, arr6, rows6);
    printf("\n");
  }

  return 0;
}



