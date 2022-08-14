#define _CRT_SECURE_NO_WARNINGS
/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   14.08.22

program: WAP to convert Decimal number into Octal number
Example 1

Input
    8
Output
    10
*/

#include <stdio.h>
#include <stdlib.h>

int decimal_to_octal(int decimal) {
    return decimal > 0 ? decimal % 8 + 10 * decimal_to_octal(decimal / 8) : 0;
}