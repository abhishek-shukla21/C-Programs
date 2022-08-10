/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   10.08.22

program: WAP program to print all natural numbers from 1 to n - using while loop.

Example 1

Input
    5
Output
	1	2	3	4	5
*/
#include <stdio.h>
int main()
{
    int n = 0, j=1;
    printf("Enter a natural number: ");
    scanf("%i", &n);
    while(n<=0){
        printf("No input <= 0 allowed, try again: ");
        scanf("%i", &n);
    }
    while(j<=n){
        printf("%i\t", j++);
    }
    return 0;
}
