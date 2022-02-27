#include <stdio.h>

int main()
{
    int i=1, number;
    printf("Enter the number");
    scanf("%d", &number);
    while(i<=number){
        printf("%d ", i);
        i++;
    }
    return 0;
}
