/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   02.08.22
program: WAP program to print all even numbers between 1 to 100. - using while loop.
*/
#include <stdio.h>
int main()
{
    int n = 2;
    while(n<=100){
        printf("%i\t", n);
        n += 2;
    }
    return 0;
}
