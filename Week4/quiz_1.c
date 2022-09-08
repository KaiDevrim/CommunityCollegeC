#include <stdio.h>
int divide(int numerator, int denominator)
{
    int quotient = numerator / denominator;
    return quotient;
}

int main(void)
{
    int numerator = 0;
    int denominator = 0;
    int quotient = 0;
    printf("Enter the numerator: ");
    scanf("%d", &numerator);
    printf("Enter the denominator: ");
    scanf("%d", &denominator);
    quotient = divide(numerator, denominator);
    printf("The quotient is %d\n", quotient);
    return 0;
}