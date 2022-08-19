#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   19.08.22
program: WAP to the sum of integers in an array
Example 1
Input
    4 9 5 80 10 2
Output
    110
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE  !0
#define FALSE 0
#define ARRAY_DEFAULT_SIZE ((int)20)
#define RANDOM_ARRAY ((unsigned char)'a')
#define ENTER_ELEMENTS ((unsigned char)'b')

typedef struct {
    int* values;
    int size;
    int sum;
}array;

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
        arr->sum = 0;
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
    return;
}

int main()
{
    array* a;
    unsigned char options = FALSE;
    int input = FALSE, size = FALSE, randomVal = FALSE, val = FALSE;
    time_t t;
    /* Intializes random number generator */
    srand((unsigned)time(&t));

    puts("In this program we'll calculate the sum of the integers in an array. "
        "Choose an option a/b:\n a) Random array \n b) Enter elements");
    while (scanf("%c", &options) != 1) {
        clearStdinFromGarbage();
        puts("Uuups ... somethin went wrong. Try again: ");
    }

    switch (options)
    {
    case RANDOM_ARRAY:
        a = createArray(ARRAY_DEFAULT_SIZE);

        for (int i = 0; i < a->size; i++) {
            randomVal = (int)(rand() % 1000);
            if (insertElement(a, i, randomVal) != randomVal) {
                puts("Error: insertElement failed. Terminating program...");
                return 0;
            }
            a->sum += randomVal;
        }
        puts("Printing random generated array...");
        displayArray(a);
        break;
    case ENTER_ELEMENTS:
        puts("How many elements do you want to enter?");

        while (scanf("%d", &size) != 1) {
            clearStdinFromGarbage();
            puts("Uuups ... somethin went wrong. Try again: ");
        }

        a = createArray(size);
        if (a != NULL) {
            for (int i = 0; i < a->size; i++) {
                printf("Enter element #%d: ", i + 1);
                while (scanf("%d", &val) != 1) {
                    clearStdinFromGarbage();
                    puts("Uuups ... somethin went wrong. Try again: ");
                }
                if (insertElement(a, i, val) != val) {
                    puts("Error: insertElement failed. Terminating program...");
                    return 0;
                }
                a->sum += val;
            }
            puts("You entered the following numbers: ");
            displayArray(a);
        }
        break;
    default:
        a = NULL;
        puts("Invalid input. Terminating the program...");
        break;
    }
    printf("The sum of the elements in the array is: %d\n", a->sum);
    return 0;
}
