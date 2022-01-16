#include <stdio.h>
#include <stdlib.h>

void main()

{

  int num1,num2;

  printf("Enter  two numbers:");

  scanf("%d%d",&num1,&num2);

   if(num1==num2)

    printf("Both numbers are equal");

  else if(num1>num2)

    printf("Number 1 is greater");

 else if(num1<num2)

    printf("Number 2 is greater");

  else

   printf("\nResult:%d<%d",num1,num2);

  getch();

}
