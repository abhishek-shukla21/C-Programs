#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   12.08.22

program: WAP to sort array in ascending order

Example 1

Input
    4 9 2 80 10 2
Output
    2 2 4 9 10 80
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE  !0
#define FALSE 0
#define ARRAY_DEFAULT_SIZE ((int)20)
#define RANDOM_ARRAY ((unsigned char)'a')
#define ENTER_ELEMENTS ((unsigned char)'b')
#define BUBBLE_SORT ((unsigned char)'a')

typedef struct {
    int* values;
    int size;
}array;

void clearStdinFromGarbage(void);
array* createArray(int size);
int insertElement(array* arr, int pos, int value);
void displayArray(array* arr);
array* cpyArray(array* arr1);

int main()
{
	return 0;
}

//clearStdinFromGarbage
//clears stdin from anything. Wrong user inputs will be erased.
void clearStdinFromGarbage(void) {
    while (getchar() != '\n');
}

//createArray
//allocates memory for an array
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
//inserts an element to the given position into an array
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
    return;
}

//cpyArray
//returns the copy of an array
array* cpyArray(array* arr1) {
    if (arr1 == NULL) return NULL;

    array* cpy = createArray(arr1->size);
    if (cpy != NULL) {
        cpy->size = arr1->size;
        for (int i = 0; i < cpy->size; i++) {
            if (insertElement(cpy, i, arr1->values[i]) != arr1->values[i]) {
                puts("Insertion failed while copying an array.");
                break;
            }
        }
    }
    return cpy;
}