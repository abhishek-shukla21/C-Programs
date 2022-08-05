//WAP program to count the number of digits in a number.

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
