/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   04.08.22
program: WAP program to print all ASCII characters with their values.
*/
int main(void) {
    printf("DEC\tCHARACTER\n");
    for (int i = 0x20; i <= 0xFF; i++)
        printf("%i\t%c\n", i, i);
    return 0;
}
