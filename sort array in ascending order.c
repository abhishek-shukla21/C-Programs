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
#define MERGE_SORT ((unsigned char) 'b')

typedef struct {
    int* values;
    int size;
}array;

void clearStdinFromGarbage(void);
array* createArray(int size);
int insertElement(array* arr, int pos, int value);
void displayArray(array* arr);
array* cpyArray(array* arr1);
void swap(array* a, int pos1, int pos2);
array* bubbleSortArray(array* arr);
void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);
void chooseSortingAlg(array* a);

int main()
{
    array* a;
    unsigned char options = FALSE, sortingAlg = BUBBLE_SORT;
    int input = FALSE, size = FALSE, randomVal = FALSE, val = FALSE;
    time_t t;
    /* Intializes random number generator */
    srand((unsigned)time(&t));

    puts("In this program we'll sort an array."
        "Choose an option a/b:\n a) Generate a random array \n b) Enter the elements manually");
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

    chooseSortingAlg(a);
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

//swap
//swaps two elements in an array
void swap(array* a, int pos1, int pos2) {
    int tmp = a->values[pos2];
    a->values[pos2] = a->values[pos1];
    a->values[pos1] = tmp;
}

//bubbleSartArray
//sorts an array with the bubbleSort algorithm
array* bubbleSortArray(array* arr) {
    array* sortedArray = cpyArray(arr);
    if (sortedArray != NULL) {
        for (int i = 0; i < sortedArray->size; i++) {
            for (int j = 0; j < sortedArray->size - 1 - i; j++) {
                if (sortedArray->values[j] > sortedArray->values[j + 1]) {
                    swap(sortedArray, j, j + 1);
                }
            }
        }
    }
    return sortedArray;
}

void merge_sort_recursion(int a[], int l, int r)
{
    // we stop recursion when l >= r
    if (l < r)
    {
        // find the midpoint of l and r
        int m = l + (r - l) / 2;

        // apply the function recursively to the left and right portions split 
        // at the midpoint
        merge_sort_recursion(a, l, m);
        merge_sort_recursion(a, m + 1, r);

        // at this point both portions of the array have been sorted, and we now 
        // merge the sorted portions of the array
        merge_sorted_arrays(a, l, m, r);
    }
}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
    // calculate the length of the left and right portions of the array
    int left_length = m - l + 1;
    int right_length = r - m;

    // create temporary arrays to store these portions
    int *temp_left = (int*)malloc(sizeof(int)*left_length);
    int *temp_right= (int*)malloc(sizeof(int) * right_length);

    // used as index/counter variables for the 3 arrays a, temp_left, temp_right
    int i, j, k;

    // copy the left portion into the temp_left array
    for (i = 0; i < left_length; i++)
        temp_left[i] = a[l + i];

    // copy the right portion into the temp_right array
    for (i = 0; i < right_length; i++)
        temp_right[i] = a[m + 1 + i];

    // Use i to move through the indexes of temp_left, j to move through the 
    // indexes of temp_right, and k to move through the portion of the array 
    // a from l ... r.  We basically keep checking the "head" of temp_left 
    // and temp_right (knowing both arrays are sorted) and put the smaller of 
    // the two into array a (using i, j, k to move through the arrays).  When
    // we run out elements in either temp_left or temp_right, the remaining 
    // elements from the other array will be copied over into a.
    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        // so long as we have not already reached the end of the temp_left array 
        // with our variable i, then if the next element in the left_temp array 
        // is smaller OR if we have reached the end of the temp_right array, 
        // then store the next element from temp_left into the next element in 
        // the array a
        if ((i < left_length) &&
            (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            a[k] = temp_left[i];
            i++;
        }
        // otherwise if the next element in temp_right than the next element in 
        // temp_left OR we have reached the end of temp_left, store the next 
        // element from the temp_right array into the next element in array a
        else
        {
            a[k] = temp_right[j];
            j++;
        }
    }
    free(temp_right);
    free(temp_left);
}

void merge_sort(int a[], int length)
{
    // call the merge sort recursion function, the left index of 0 and the
    // right index of length - 1 are provided as we are initially looking 
    // at sorting "the entire array"
    merge_sort_recursion(a, 0, length - 1);
}

//chooseSortingAlg
//allows the user to choose an algorithm to sort an array.
//for now only bubble sort and merge sort implemented
//TODO: implement more sorting algorithms
void chooseSortingAlg(array* a) {
    unsigned char sortingAlg = FALSE;
    array* sortedArray = NULL;
    puts("\nChoose a sorting algorithm:\na) Bubble sort\nb) Merge sort");
    clearStdinFromGarbage();
    while (scanf("%c", &sortingAlg) != 1) {
        clearStdinFromGarbage();
        puts("Uuups ... somethin went wrong. Try again: ");
    }

    switch (sortingAlg)
    {
    case BUBBLE_SORT:
        sortedArray = bubbleSortArray(a);
        puts("The array was sorted with the bubble sort algorithm. Printing the sorted array...");
        displayArray(sortedArray);
        free(sortedArray);
        break;
    case MERGE_SORT:
        sortedArray = cpyArray(a);
        merge_sort(sortedArray->values, sortedArray->size);
        displayArray(sortedArray);
        free(sortedArray);
        break;
    default:
        puts("Undefined input.");
        break;
    }
    return;
}
