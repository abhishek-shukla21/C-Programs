#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
    printf("Enter a character to check if it's is Alphabet, Number or Special character \n");
    scanf("%c", &a);
    if(a>= 'a' && a<= 'z' || a>= 'A' && a<= 'Z' ) {
        printf(" '%c' is Alphabet", a);
    }
    else if(a>= '0' && a<= '9') {
        printf(" '%c' is number", a);
    }
    else
        printf(" Special character");
    return 0;
}
