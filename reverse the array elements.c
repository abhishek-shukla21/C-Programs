#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000u

void reverseString(char *str){
    if (str[0] != '\0') reverseString(str+1);
    putchar(str[0]);
}
int main(void) {
    char str[BUFFER_SIZE];
    puts("Enter a string to revert: ");
    gets_s(str);
    reverseString(str);
    return 0;
}
