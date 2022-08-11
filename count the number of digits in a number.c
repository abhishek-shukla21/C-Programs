/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   10.08.22

program: WAP program to count the number of digits in a number.

Example 1

Input
    1234
Output
    4

*/
int main(void) {
    int number = 0, nrOfDigits = 1;
    printf("Please enter a number: ");
    scanf("%i", &number);
    while (number / 10 != 0) {
        nrOfDigits++;
        number /= 10;
    }
    printf("\nThe number has %i digits", nrOfDigits);
    return 0;
}
