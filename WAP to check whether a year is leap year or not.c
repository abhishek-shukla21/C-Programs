#include <stdio.h>

int main(){

   int year;

   printf("Enter the year to check: ");

   scanf("%d",&year);

   if ((!(year % 4) && year % 100) || !(year%400))
{
      	printf("Leap year");
}
   else
      printf("Not a leap year");

}
