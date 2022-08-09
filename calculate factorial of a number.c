#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   09.08.22

program: WAP program to calculate factorial of a number.

Example 1

Input
    Input number: 5
Output
    120

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
unsigned int calcFactorial(int number) {
    if (number < 0) return FALSE;

    int tmp = 1;
    for (int i = number; i > 0; i--) {
        tmp *= i;
    }
    return tmp;
}

int main()
{
    int input = 0;
    puts("Enter a positive integer: ");
    while(scanf("%i", &input) != 1) {
        clearStdinFromGarbage();
        puts("Uuups ... somethin went wrong. Try again: ");
    }
    printf("%i", calcFactorial(input));

    return 0;
}
