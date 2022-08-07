#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   07.08.22

program: WAP program to swap first and last digits of a number.

Example

Input
    Input number: 1234
Output
    4231
*/
#include <stdio.h>
#include <math.h>

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
    int input = 0;
    int output = 0;
    int firstDgt = 0, lastDgt = 0;
    puts("Enter an integer: \n");
    while (scanf("%i", &input) != 1) {
        clearStdinFromGarbage();
        puts("Uuups ... something went wrong. Try again: ");
    }
    firstDgt = (input / (pow(10, getNrOfDgts(input) - 1)));
    lastDgt = (input%10);
    output = input + (int)((lastDgt - firstDgt) * pow(10, getNrOfDgts(input) -1)) - lastDgt + firstDgt;

    printf("swapped first and last digit: %i", output);
    return 0;
}
