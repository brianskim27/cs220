#include <stdio.h>

void bad()
{
  /* write your code here */
	char *new_name = "Quick brown fox jumped over the lazy dog";
	unsigned char *temp;
	
	//int Offset_name = 0x20;
	//int Offset_age = 0x28;
	//int ret_offset = 0x1b;
	//int stack_offset_ret_addr = 0x10;

	temp = (unsigned char *) (&new_name);
	*((unsigned long *) (temp + 0x18)) += 0x1b;

 	*((char **) (temp + 0x20)) = new_name;
	*((int *) (temp + 0x28)) = 1000;
  
}

/* do not change anything below */
int main()
{
	struct {
		char *name; 
		int age; 
	} student = {.name = "John", .age = 22 }; 
	bad(); 
	printf("Student.name = %s\nstudent.age = %d\n", student.name, student.age); 
	return 0; 
}

