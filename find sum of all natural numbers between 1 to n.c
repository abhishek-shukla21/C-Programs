//WAP program to find sum of all natural numbers between 1 to n.
#include <stdio.h>
int main()
{
    int n=0, j=0;
    printf("Enter a natural number: ");
    scanf("%i", &n);
    while(n<=0){
        printf("No input <= 0 allowed, try again: ");
        scanf("%i", &n);
    }
    while(j<=n){
        j+=j++;
    }
    printf("%i", j);
    return 0;
}
