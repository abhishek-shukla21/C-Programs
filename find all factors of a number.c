#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   08.08.22

program: WAP program to find all factors of a number.

Example 1

Input
    Input number: 20
Output
    1 2 4 5 10 20

*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE  !0
#define FALSE 0

//clearStdinFromGarbage
//clears stdin from anything. Wrong user inputs will be erased.
void clearStdinFromGarbage(void) {
    while (getchar() != '\n');
}

//displayFactors
//calculates all factors of a number and prints them on stdout
unsigned char displayFactors(unsigned int number) {
    if (number < 0) return FALSE;
    for (unsigned int i = 1; i <= number; i++) {
        if (!(number % i)) {
            printf("%i ", i);
        }
    }
    return TRUE;
}

int main()
{
    unsigned int input = 0;
    puts("Enter a positive integer: ");
    while(scanf("%i", &input) != 1) {
        clearStdinFromGarbage();
        puts("Uuups ... somethin went wrong. Try again: ");
    }
    if (!displayFactors(input)) {
        puts("You entered a negative number.");
    }

    return 0;
}
