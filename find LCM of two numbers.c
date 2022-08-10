#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   10.08.22

program: WAP program to find LCM of two numbers.

Example 1

Input
    4 5
Output
    20

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

//getLCM
//algorithm to find the lowest common multiple
int getLCM(int number1, int number2) {
    int LCM = number1 > number2 ? number1 : number2;
    while (TRUE) {
        if (LCM % number1 == 0 && LCM % number2 == 0) {
            printf("The least common factor of %d and %d is: %d", number1, number2, LCM);
            break;
        }
        LCM++;
    }
    return LCM;
}

int main()
{
    int input1 = 0, input2 = 0;
    puts("Enter two numbersin the format a b: ");
    while (scanf("%i %i", &input1, &input2) != 2) {
        clearStdinFromGarbage();
        puts("Uuups ... somethin went wrong. Try again: ");
    }
    getLCM(input1, input2);

    return 0;
}
