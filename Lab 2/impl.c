#include <stdio.h>

struct bad_struct {
	short s1;
	long l1;
	short s2;
};

struct good_struct {
	short s1;
	short s2;
	long l1;
};

union unit {
	char c;
	int i;
	long l;
};

enum Grade {F = 0, E, D, C, B, A};

const char enum2str[] = {'F', 'E', 'D', 'C', 'B', 'A'};

#define BIT(n)		(1 << (n))
#define IS_SET(v, n)	(((v) & BIT(n)) != 0)
#define BIT_SET(v, n)	(v |= BIT(n))
#define BIT_CLEAR(v, n)	(v &= -(BIT(n)))
#define BIT_FLIP(v, n)	(v ^= BIT(n))

void print_in_binary(unsigned int x) {
	int i;
	for(i = 31; i >= 0; i--) {
		if(IS_SET(x, i)) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
	printf("\n");
	return 0;
}

int main() {
	//Part 3 - Structure
	struct bad_struct bs;
	struct good_struct gs;
	
	printf("Size of bs: %d\n", sizeof(bs));
	printf("Size of gs: %d\n", sizeof(gs));

	printf("Address of bs.s1: %p\n", &bs.s1);
	printf("Address of bs.l1: %p\n", &bs.l1);
	printf("Address of bs.s2: %p\n", &bs.s2);
	printf("Address of gs.s1: %p\n", &gs.s1);
	printf("Address of gs.s2: %p\n", &gs.s2);
	printf("Address of gs.l1: %p\n", &gs.l1);
	
	//Part 4 - Union
	union unit u;

	printf("Size of u: %d\n", sizeof(u));

	printf("Address of u.c: %p\n", &u.c);
	printf("Address of u.i: %p\n", &u.i);
	printf("Address of u.l: %p\n", &u.l);

	scanf("%lu", &u.l);
	
	printf("%c, %lu, %d, %s\n", u.c, u.l, u.i, &u.l);
	
	//Part 5 - Enumerator
	enum Grade g = A;
	printf("Grade g = %d\n", g);
	printf("Grade g = %c\n", enum2str[g]);

	//Part 6 - Macros and Print in Binary
	int b = 20;
	printf("Print in binary: ");
	print_in_binary(b);
	
	//BIT_SET
	int s = 20;
	BIT_SET(s, 1);
	printf("BIT_SET: ");
	print_in_binary(s);

	//BIT_CLEAR
	int c = 20;
	BIT_CLEAR(c, 3);
	printf("BIT_CLEAR: ");
	print_in_binary(c);

	//BIT_FLIP
	int f = 20;
	BIT_FLIP(f, 3);
	printf("BIT_FLIP: ");
	print_in_binary(f);
}
