#include <stdio.h>
#include <unistd.h>

int main();

unsigned char * libc_start = (unsigned char *) 0x7ffff7de5000;
unsigned char * libc_end = (unsigned char *) 0x7ffff7f3f000;

unsigned long addr_gadget_rdi = 0; 
unsigned long addr_gadget_rsi = 0; 
unsigned long addr_gadget_rdx = 0; 

int foo()
{
	char buf[64]; 
	
	while(libc_start < libc_end) {
		if(*libc_start != 0xc3) {
			libc_start++;
			continue;
		}
		if(*(libc_start -1 )== 0x5a) {
			addr_gadget_rdx = (unsigned long) (libc_start - 1);		
			/*libc_start++;*/
		}
		else if(*(libc_start - 1) == 0x5e) {
			addr_gadget_rsi = (unsigned long) (libc_start - 1);
			/*libc_start++;*/
		}
		else if(*(libc_start - 1) == 0x5f) {
			addr_gadget_rdi = (unsigned long) (libc_start - 1);
			/*libc_start++;*/
		}
		libc_start++;
		if(addr_gadget_rdi != 0 && addr_gadget_rsi != 0 && addr_gadget_rdx != 0)  {
			break;
		}
	}

	unsigned long *p = (unsigned long *) &buf[0];
	int i = 0;
	while (!(p[i] > (unsigned long) (&main) && p[i] < ((unsigned long) &main +50)))
	  {
	    i++;
	  }
	printf("retaddr located at %p. Returning to %p, distance from buf: %u\n", &p[i], (void*)p[i], i*sizeof(p[i]));
	printf("RDI_gadget addr = %p\n", (void *) addr_gadget_rdi); 
	printf("RSI_gadget addr = %p\n", (void *) addr_gadget_rsi); 
	printf("RDX_gadget addr = %p\n", (void *) addr_gadget_rdx); 
	printf("Addr of execve = %p\n", &execve); 
	printf("buffer addr = %p\n", buf);
	puts("Enter text: "); 
	gets(buf); 
	printf("Contents of the buf are: %s\n", buf); 
	return 9; 
}

int main()
{
	printf("Addr of main: %p\n", &main); 
	return foo(); 
}

