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


unsigned char is_armstrong(int number) {
    int tmp = FALSE, cpy = number, nr_of_dgts = get_number_of_digits(number);

    while (get_number_of_digits(number)) {
        tmp += (int)pow(get_last_digit(number), nr_of_dgts);
        number /= 10;
    }
    return tmp == cpy ? TRUE : FALSE;
}

unsigned char get_last_digit(int number) {
    return number % 10;
}

int get_number_of_digits(int number) {
    return number > 0 ? 1 + get_number_of_digits(number / 10) : FALSE;
}

//clearStdinFromGarbage
//clears stdin from anything. Wrong user inputs will be erased.
void clearStdinFromGarbage(void) {
    while (getchar() != '\n');
}

//createArray
//allocates memory for the array
array* createArray(int size) {
    if (size <= 0)
        return NULL;

    array* arr = (array*)malloc(sizeof(array));
    if (arr != NULL) {
        arr->values = (int*)malloc(size * sizeof(int));
        arr->size = size;
        if (arr->values != NULL) {
            for (int i = 0; i < size; i++) {
                arr->values[i] = 0;
            }
            return arr;
        }
    }
    return NULL;
}

//insertElement
//inserts an element to the given position into the array
int insertElement(array* arr, int pos, int value) {
    if (arr == NULL) return FALSE;
    if (pos < 0 || pos > arr->size) return FALSE;

    arr->values[pos] = value;

    return arr->values[pos];
}

//displayArray
//prints the elements of an array seperated by spaces
void displayArray(array* arr) {
    if (arr == NULL) return;

    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->values[i]);
    }
    putchar('\n');
    return;
}