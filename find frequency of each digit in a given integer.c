#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   08.08.22

program: WAP program to find frequency of each digit in a given integer.

Example 1

Input
    Input number: 1234
Output
    The number 1234 is no palindrome.

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

//countNrOfDgts
//counts the frequency of a digit in a number and prints it afterwards.
void countNrOfDgts(int number) {
    int input = number;
    int arr[10] = { 0 };
    unsigned char firstDgt = 0, lastDgt = 0;

    while (getNrOfDgts(number) != 0) {
        lastDgt = (number % 10);
        arr[lastDgt]++;
        number /= 10;
    }

    printf("The frequency of the digits in the number %i is printed ... \n", input);
    for (int i = 0; i < 10; i++) {
        if (arr[i] != 0) {
            printf("Digit %i x %i\n", i, arr[i]);
        }
    }
    return;
}

int main()
{
    int input = 0, inputCpy;
    int output = 0;
    int *arr = { 0 };
    
    puts("Enter an integer: \n");
    while (scanf("%i", &input) != 1) {
        clearStdinFromGarbage();
        puts("Uuups ... something went wrong. Try again: ");
    }
    countNrOfDgts(input);

    return 0;
}
