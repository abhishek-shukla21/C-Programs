#include <stdio.h>

void main()
{
    int number;
    printf("Enter a number \n");
    scanf("%d", &number);
    printf("%s number \n", number >= 0 ? "Positive" : "Negative");
}
