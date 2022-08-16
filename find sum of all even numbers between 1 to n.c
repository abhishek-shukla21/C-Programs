/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   14.08.22

program: WAP program to find sum of all even numbers between 1 to n.

Example

Input
    5
Output
    6
*/

#include <stdio.h>
int main()
{
    int n = 0, ctr = 0, sum = 0;
    printf("Enter a natural number: ");
    scanf("%i", &n);
    while (n <= 0) {
        printf("No input <= 0 allowed, try again: ");
        scanf("%i", &n);
    }
    while (++ctr <= n) {
        sum += ctr%2 == 0 ? ctr : 0;
    }
    printf("%i", sum);
   
