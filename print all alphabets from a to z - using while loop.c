//WAP program to print all alphabets from a to z. - using while loop.
#include <stdio.h>
int main()
{
    int n = 'a';
    while(n<='z'){
        printf("%c\t", n++);
    }
    return 0;
}
