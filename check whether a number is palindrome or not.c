#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   08.08.22

program: WAP program to check whether a number is palindrome or not.

Example 1

Input
    Input number: 1234
Output
    The number 1234 is no palindrome.

Example 2

Input
    Input number: 1221
Output
    The number 1221 is a palindrome.
*/
#include <stdio.h>
#include <math.h>

#define TRUE  !0
#define FALSE 0

//clearStdinFromGarbage
//clears stdin from anything. Wrong user inputs will be erased.
void clearStdinFromGarbage(void) {
    while (getchar() != '\n');
}

//getNrOfDgts
//returns number of digits
unsigned char getNrOfDgts(int number) {
    return log10(number) + 1;
}

int main()
{
    int input = 0, inputCpy;
    int output = 0;
    unsigned char firstDgt = 0, lastDgt = 0, isPalindrome = FALSE;
    puts("Enter an integer: \n");
    while (scanf("%i", &input) != 1) {
        clearStdinFromGarbage();
        puts("Uuups ... something went wrong. Try again: ");
    }
    inputCpy = input;
    while (getNrOfDgts(inputCpy) != 0) {
        lastDgt = (inputCpy % 10);
        output += lastDgt * pow(10, getNrOfDgts(inputCpy)-1);
        inputCpy /= 10;
    }
    if (output == input) {
        printf("The number %i is a palindrome.", input);
    }
    else
    {
        printf("The number %i is no palindrome", input);
    }
    
    return 0;
}
