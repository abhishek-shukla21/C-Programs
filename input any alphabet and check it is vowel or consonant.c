#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
    printf("Enter an Alphabet(small letter) to check if it's a vowel or consonent");
    scanf("%c", &a);
    if (a == 'a' || a == 'e' || a == "i" || a == "o" || a == "u") printf("Vowel");
    else printf("Consonent");

    return 0;
}

