#include <stdio.h>
#include <stdlib.h>

extern unsigned long *get_ebp();

void ret2libc(int dummy){
	unsigned long *curr_ebp = get_ebp();
	unsigned long temp = curr_ebp[1];
	curr_ebp[1] = (unsigned long) &system;
	char *str = "/bin/bash";
	curr_ebp[3] = (unsigned long) str;
	curr_ebp[2] = temp;
}

int main(){
  ret2libc(0);
  
  printf("Done!\n");
  return 0;

}

