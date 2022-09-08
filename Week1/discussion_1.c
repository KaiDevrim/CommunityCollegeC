/*
    This program will perform a variety of operations
    on a variable. Including taking a sum, product, difference,
    quotient and remainder of a variable.

    K D McCormick, 2022-06-22
*/

#include <stdio.h>

int main(void) {
    double result = 0.0;
    int first = 20;
    int second = 50;

    result = first + second;
    printf("The result for addition is: %f\n", result); // addition

    result = first - second;
    printf("The result for subtraction is: %f\n", result); // subtraction

    result = first * second;
    printf("The result for multiplication is: %f\n", result); // multiplication

    result = (double) first / second;
    printf("The result for division is: %f\n", result); // division

    result = first % second;
    printf("The result for the remainder is: %f\n", result); // remainder

    return 0;
}