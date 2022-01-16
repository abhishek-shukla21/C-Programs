#include <stdio.h>

void main()
{
    int number;

    printf("Enter a number \n");
    scanf("%d", &number);
    if (number >= 0)
        printf("Positive number \n");
    else
        printf("Negative number \n");
}
