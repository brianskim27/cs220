#include <stdio.h>

int arith(int n1, int n2, char op)
{
	int result = 0; 
	switch(op) {
		case '+': result = n1 + n2; break; //add break after result = n1 + n2; to fix addition case 
		case '-': result = n1 - n2; break; 
		case '*': result = n1 * n2; break; 
		case '/': result = n1 / n2; break; 
		default: break; 
	}
	return result; 
}

int main()
{
	int num1, num2; 
	int result, i; 
	char op; 
	printf("Hello World\n"); 
	printf("Enter number 1: ");
	scanf("%d", &num1); 
	printf("Enter number 2: "); 
	scanf("%d", &num2);
        op = '+';	
	do {
		if(op != '+') {
			printf("Invalid operation. Try again!\n"); 
		}
		printf("Enter operation [+, -, /, *]: "); 
		scanf(" %c", &op);
	} while (op != '+' && op != '-' && op != '*' && op != '/'); 	
	result = arith(num1, num2, op); num2
	printf("%d %c %d = %d\n", num1, op, num2, result); //add result after num2 to print the value in result
	for(i = 0; i < 1000; i++) {
		if(i == 647) {
			printf("i = %d\n", i); //add i after "i =  %d\n" to print the value in i
		}
	}

	return result;
}	
return

