/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   10.08.22

program: WAP to find max & min element in an array.

Example 1

Input
    4 9 5 80 10 2
Output
    min element: 2
    max element: 80

*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE  !0
#define FALSE 0
#define ARRAY_DEFAULT_SIZE ((int)20)
#define RANDOM_ARRAY ((unsigned char)'a')
#define ENTER_ELEMENTS ((unsigned char)'b')

typedef struct{
    int* values;
    int size;
}array;

//clearStdinFromGarbage
//clears stdin from anything. Wrong user inputs will be erased.
void clearStdinFromGarbage(void) {
    while (getchar() != '\n');
}

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

int insertElement(array* arr, int pos, int value) {
    if (arr == NULL) return FALSE;
    if (pos < 0 || pos > arr->size) return FALSE;

    arr->values[pos] = value;
    
    return arr->values[pos];
}

void displayArray(array* arr) {
//    if (arr == NULL) return;
    
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->values[i]);
    }
    return;
}