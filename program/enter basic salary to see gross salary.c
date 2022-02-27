#include <stdio.h>

int main()
{
    float basicSalary, grossSalary, da, hra;

    printf("Enter basic salary of an employee: ");
    scanf("%f", &basicSalary);


    if(basicSalary <= 10000)
    {
        da  = basicSalary * 0.8;
        hra = basicSalary * 0.2;
    }
    else if(basicSalary <= 20000)
    {
        da  = basicSalary * 0.9;
        hra = basicSalary * 0.25;
    }
    else
    {
        da  = basicSalary * 0.95;
        hra = basicSalary * 0.3;
    }

    grossSalary = basicSalary + hra + da;

    printf("Gross Salary %f", grossSalary);

    return 0;
}

