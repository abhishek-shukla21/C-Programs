//WAP program to find roots of a quadratic equation using switch case.
#include <stdio.h>
#include <math.h>

#define TRUE !0
#define FALSE 0

void clearNewLineChar(void) {
    while (getchar() != '\n');
}
int main()
{
    double a = 0.0f, b = 0.0f, c = 0.0f, root1 = 0.0f, root2 = 0.0f, cmplxRootRe = 0.0f, cmplxRoot1Im = 0.0f, cmplxRoot2Im = 0.0f;
    unsigned char complexRoots = FALSE;

    printf("Let's calculate the roots of a quadratic equation a*x^2 + b*x + c. The value of a is not allowed to be 0.\n");
    printf("Please enter three numbers in the following format a b c: ");
    while (scanf("%lf %lf %lf", &a, &b, &c) != 3 || a == 0.0f) {
        clearNewLineChar();
        printf("Uuups ... something went wrong. Try again: ");
    }
    
    printf("\nYou entered: a = %.3lf, b = %.3lf, c = %.3lf\n", a, b, c);

    complexRoots = b * b - 4 * a * c < 0 ? TRUE : FALSE;

    switch (complexRoots) {
    case TRUE:
        cmplxRootRe = -b/(2*a);
        cmplxRoot1Im = sqrt(4*a*c -b*b)/(2*a);
        cmplxRoot2Im = -cmplxRoot1Im;
        printf("The roots are complex:\nx_1 = %.3lf + (%.3lf)i\nx_2 = %.3lf + (%.3lf)i", cmplxRootRe, cmplxRoot1Im, cmplxRootRe, cmplxRoot2Im);
        break;
    case FALSE:
        root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        root2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        printf("The roots are:\nx_1 = %.3lf\nx_2 = %.3lf", root1, root2);
        break;
    }
    return 0;
}
