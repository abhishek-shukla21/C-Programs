#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   14.08.22

program: WAP to convert Decimal number into Octal number
Example 1

Input
    8
Output
    10
*/

#include <stdio.h>
#include <stdlib.h>

//clearStdinFromGarbage
//clears stdin from anything. Wrong user inputs will be erased.
void clearStdinFromGarbage(void) {
    while (getchar() != '\n');
}

//decimal_to_octal
//recursive function that converts a decimal nuber to an octal number
int decimal_to_octal(int decimal) {
    return decimal > 0 ? decimal % 8 + 10 * decimal_to_octal(decimal / 8) : 0;
}

int main()
{
    int input = 0;
    puts("Enter a decimal number to convert it to an octal number: ");
    while (scanf("%i", &input) != 1) {
        clearStdinFromGarbage();
        puts("Uuups ... something went wrong. Try again: ");
    }
    printf("%d", decimal_to_octal(input));
    return 0;
}
