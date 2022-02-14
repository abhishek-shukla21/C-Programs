#include <stdio.h>
#include <stdlib.h>

int main()
{
    // WAP to input week number and print week day. (Hint Week starts from Monday)
    int c;
    printf("Enter the Number between 1 to 7 to the week day \n");
    scanf("%d", &c);
    switch(c){
        case 1 : printf("Monday");
                    break;
        case 2 : printf("Tuesday");
                    break;
        case 3 : printf("Wednesday");
                    break;
        case 4 : printf("Thursday");
                    break;
        case 5 : printf("Friday");
                    break;
        case 6 : printf("Saturday");
                    break;
        case 7  : printf("Sunday");
                    break;
        default : printf("Enter Input between 1 to 7 only.");
    }

    return 0;
}
