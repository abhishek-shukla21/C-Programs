#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   07.08.22

program: WAP program to print multiplication table of any number.

*/
#include <stdio.h>

#define TABLE_SIZE 20 //20x20
int main()
{   //starting from 2, because no one should be interested in multiplication *1
    for (unsigned char rows = 1; rows <= TABLE_SIZE; rows++) {
        for (unsigned char culomns = 1; culomns <= TABLE_SIZE; culomns++) {
            printf("%5i", rows*culomns);
        }
        putchar('\n');
    }
    return 0;
}
