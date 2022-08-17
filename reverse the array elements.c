/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   04.08.22
program:  WAP to reverse the array elements
Example
Input
    hello world
Output
	dlrow olleh
*/

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
