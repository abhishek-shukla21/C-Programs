//WAP program to print all natural numbers in reverse (from n to 1). - using while loop.
#include <stdio.h>
int main()
{
    int n = 0;
    printf("Enter a natural number: ");
    scanf("%i", &n);
    while(n<=0){
        printf("No input <= 0 allowed, try again: ");
        scanf("%i", &n);
    }
    while(n>0){
        printf("%i\t", n--);
    }
       
    return 0;
}
