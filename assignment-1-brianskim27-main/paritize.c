#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paritize(void *p, unsigned int num_bytes){
    u_int8_t* bytes = (u_int8_t*) p;

    for(int i = 0; i < num_bytes; i++) {
        int n = 0;
        unsigned int byte = *bytes;
	unsigned int mask = 1;
        
	for(int j = 0; j < 7; j++) {
            if((byte & mask) != 0) {
		n++;
	    }
            mask = mask << 1;
        }
        
	if(n % 2 == 0) {
            *bytes &= 0b01111111;
        } 
	else {
            *bytes |= 0b10000000;
        }
        bytes++;
    }

    p = bytes;

}

int main(){
  unsigned int x = 0xdeadbeef;
  unsigned long y = 0x12345678deadc0de;
  printf("Test cases:\n");
  printf("byte-array = %x num_bytes = %lu ", x, sizeof(x));
  paritize(&x, 4);
  printf("result = %x\n", x);
  printf("byte-array = %lx num_bytes = %lu ", y, sizeof(y));
  paritize(&y, 8);
  printf("result = %lx\n", y);
  
  return 0;
}
