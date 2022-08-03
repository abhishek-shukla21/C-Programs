//WAP program to find sum of all odd numbers between 1 to n.
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
        sum += ctr % 2 == 0 ? 0 : ctr;
    }
    printf("%i", sum);
    return 0;
}
