#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Implement the reverse_words function below that accepts a string and reverses the word ordering within the string. Note that the characters within the words are not reversed. */

char *reverse_words(char *str){
    int len, i, index, word_Start, word_End;
    char temp[100];
    len = strlen(str);
    index = 0;
    word_Start = len - 1;
    word_End = len - 1;

    while(word_Start > 0) {
        if(str[word_Start] == ' ') {
            i = word_Start + 1;
            while(i <= word_End) {
                temp[index] = str[i];
                i++;
                index++;
            }
            temp[index++] = ' ';
            word_End = word_Start - 1;
        }
        word_Start--;
    }
    
    for(i = 0; i <= word_End; i++) {
        temp[index] = str[i];
        index++;
    }
    
    temp[index] = '\0';
    str = temp;

    return str;
}

int main(){
  char * str;
  printf("Test cases:\n");
  str = "";
  printf("string = \"%s\"; return value = \"%s\"\n", str, reverse_words(str));
  str = "Hello World";
  printf("string = \"%s\"; return value = \"%s\"\n", str, reverse_words(str));
  str = "HeyYou";
  printf("string = \"%s\"; return value = \"%s\"\n", str, reverse_words(str));
  str = "What is the question?";
  printf("string = \"%s\"; return value = \"%s\"\n", str, reverse_words(str));
  str = "It is what it is.";
  printf("string = \"%s\"; return value = \"%s\"\n", str, reverse_words(str)); 

  return 0;
}
