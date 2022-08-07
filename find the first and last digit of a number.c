#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   07.08.22

program: WAP program to find the first and last digit of a number.

Example

Input
    Input number: 1234
Output
    First digit: 1
    Last digit: 4
*/
#include <stdio.h>
#include <math.h>

#define BUFFER_SIZE 100

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

//getFirstDgt
//returns the first digit of a number
unsigned char getFirstDgt(int number) {
    return number / (pow(10, getNrOfDgts(number) - 1));
}

//moduloTen
//does the same as %10. I wrote it just for fun ^^
unsigned char moduloTen(int input) {
    int reducedInput = input, tmp;
    while (reducedInput >= 10) {
        tmp = getFirstDgt(reducedInput) * pow(10, getNrOfDgts(reducedInput) - 1);
        if (reducedInput >= tmp) {
            reducedInput -= tmp;
        }
    }
    return reducedInput;
}

int main()
{
    int input = 0;
    unsigned char firstDgt = 0, lastDgt = 0, nrOfDgts = 0;
    char str[BUFFER_SIZE] = { '\0' };
    puts("Enter an integer: \n");
    while (scanf("%i", &input) != 1) {
        clearStdinFromGarbage();
        puts("Uuups ... something went wrong. Try again: ");
    }
    firstDgt = getFirstDgt(input);
    lastDgt = moduloTen(input);
    sprintf(str, "You entered: %i. The first digit is: %i and the last digit is: %i", input, firstDgt, lastDgt);
    puts(str);

    return 0;
}
