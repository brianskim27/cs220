#include <stdio.h>
#include <stdlib.h>

extern unsigned long *get_rbp();
int main(int argc, char *argv[]);

unsigned long* print_backtrace(int count) {
	unsigned long x = (unsigned long) &main;
	int t = 0;
	unsigned char *v = (unsigned char *) &main;
	
	while(*v != 0xc3) {
		v = (unsigned char *) (x + t);
		t++;
	}
	unsigned long y = x + t;
	unsigned long *curr_rbp = get_rbp();
	unsigned long *ret_addr;
	unsigned long *arr = (unsigned long *) malloc(count * sizeof(ret_addr));
	
	int i = 0;
	while(count > 0) {
		i++;
		ret_addr = (unsigned long *) *(curr_rbp + 1);
		printf("%x\n", ret_addr);
		arr[i] = ret_addr;
		if(*ret_addr >= x && *ret_addr <= y) {
			return arr;
		}
		curr_rbp = (unsigned long *) *(curr_rbp);
		count--;
	}
}


/* Do not change anything below this point */
void j() { print_backtrace(10); }
void i() { j(); }
void h() { i(); }
void g() { h(); }
void f() { g(); }

int main(int argc, char *argv[])
{
  f();
  return 0;
}
