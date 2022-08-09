#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   09.08.22

program: WAP program to find HCF (GCD) of two numbers.

Example 1

Input
    20 30
Output
    10

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
int getHighestCommonFactor(int number1, int number2) {
    int highestCommonFactor = FALSE;
   for (int i = 1; i <= (number1 > number2 ? number1 : number2); i++) {
        if (number1%i == 0 && number2%i == 0){
            highestCommonFactor = highestCommonFactor < i ? i : highestCommonFactor;
        }
     }
    
    return highestCommonFactor;
}

int main()
{
    int input1 = 0, input2 = 0;
    puts("Enter two numbersin the format a b: ");
    while (scanf("%i %i", &input1, &input2) != 2) {
        clearStdinFromGarbage();
        puts("Uuups ... somethin went wrong. Try again: ");
    }
    int HGF = getHighestCommonFactor(input1, input2);
    if (!HGF) {
        puts("No HGF found.");
    }else{
        printf("The HGF is: %i", HGF);
    }

    return 0;
}
