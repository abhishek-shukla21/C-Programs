#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   14.08.22

program: WAP to count and display the position of Armstrong number in an array

Example 

Input
    153 370 99 84 1634
Output
    found armstrong number at position#0: 153
    found armstrong number at position#1: 370
    found armstrong number at position#4: 1634
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE  ((unsigned char)!0)
#define FALSE ((unsigned char)0)

typedef struct {
    int* values;
    int size;
}array;

void clearStdinFromGarbage(void);
array* createArray(int size);
int insertElement(array* arr, int pos, int value);
void displayArray(array* arr);

int get_number_of_digits(int number);
unsigned char get_last_digit(int number);
unsigned char is_armstrong(int number);
void find_and_display_position_of_armstrong_number(array* a);

//clearStdinFromGarbage
//clears stdin from anything. Wrong user inputs will be erased.
void clearStdinFromGarbage(void) {
    while (getchar() != '\n');
}