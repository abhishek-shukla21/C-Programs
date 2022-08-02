//WAP program to print all natural numbers from 1 to n. - using while loop.
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
