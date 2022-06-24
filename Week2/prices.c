/*
    Psuedocode:
    Create the following variables, price, input_price, sales_tax, and price_with_tax as doubles.
    Create an items variable as an int that increases by 1 each time in the do while loop.
    Create do/while loop that prints out a message then reads the user input as a double.
    Then while the input_price is not 0 then continue with the loop. Calculate the
    price_with_tax with price * sales_tax. Then print out the needed information
    with the variables given.

    K D McCormick, 2022-06-23
*/

#include <stdio.h>

int main() {
    // Initialize variables
    double input_price = 0.0;
    double price = 0.0;
    int items = 0;
    double sales_tax = 1.075;
    double price_with_tax = 0.0;
    // Because I don't know how to print a % sign :/
    char percent = '%';
    // Start the do while loop
    do
    {
        // Print and take input
        printf("Enter a price, or zero when finished: $");
        scanf("%lf", &input_price);
        printf("\n");
        // Sets the total price and increments the amount of items
        price = price + input_price;
        items++;
    } while (input_price != 0.0);
    // Because the last input technically counts as an item
    items = items - 1;
    // Calculate price with the tax here
    price_with_tax = price * sales_tax;
    // Output the information obtained in an easy to read format
    printf("Number of items purchased: %i\n", items);
    printf("Subtotal \t $%.2f\n", price);
    printf("Sales tax 7.5%c   $%.2f\n", percent, price * 0.075);
    printf("Total \t \t $%.2f\n", price + price_with_tax);
    // End program
    return 0;
}
