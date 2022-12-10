#include <stdio.h>
int main() {
    char opt;
    int num1, num2;
    float res;
    printf (" Select an operator +, -, *, / \n ");
    scanf ("%c", &opt);
    printf (" Enter the first number: ");
    scanf(" %d", &num1);
    printf (" Enter the second number: ");
    scanf (" %d", &num2);

    if (opt == '+') res = num1 + num2;
    else if (opt == '-') res = num1 - num2;
    else if (opt == '*') res = num1 * num2;
    else if (opt == '/') {
        if (num2 == 0)
        {
            printf (" \n Divisor cannot be zero. Please enter another value ");
            scanf ("%d", &num2);
        }
        res = num1 / num2;
    }
    else {
        printf(" \n You have entered wrong inputs ");
        return 0;
    }
    printf ("%.2f", res);
    return 0;
}
