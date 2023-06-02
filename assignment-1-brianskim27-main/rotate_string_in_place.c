#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Implement the rotate_string_in_place function below so that it ccepts a string and a displacement and rotates each alphabetical character in the string by the given displacement to the right where disp is between 0 and 2600. Non alphabetical characters are retained without modification */

void rotate_string_in_place(char *str, unsigned int disp){
    int i;

    for(i = 0; i < strlen(str); i++) {
        if(isupper(str[i])) {
            str[i] = ((str[i] - 65 + disp) % 26) + 65;
        }
        else if(islower(str[i])) {
            str[i] = ((str[i] - 97 + disp) % 26) + 97;
        }
        else {
            str[i] = str[i];
        }
    }
    
    return str;
}

int main(){
  char * str =  "gcc -c hw.c -o hw";
  char * cpy = (char *) malloc(strlen(str) + 1);
  printf("Test case:\n");
  printf("string = \"%s\"; ", str);
  strcpy(cpy, str);
  rotate_string_in_place(cpy, 2413);
  printf("Rotated(%u): \"%s\"\n", 2413, cpy);
  free(cpy);
  
  return 0;
}
