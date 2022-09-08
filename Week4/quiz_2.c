#include <stdio.h>
double after_sales_tax(amt)
{
    double sale = amt + (amt * .06);
    return sale;
}

int main(void)
{
	char percent = '%';
    printf("Welcome to the 6%c tax calculator!\n", percent);
    double total = 0.0;
    printf("Please enter the total amount: ");
    scanf("%lf", &total);
    printf("The total amount after tax is: $%.2f\n", after_sales_tax(total));
    return 0;
}
