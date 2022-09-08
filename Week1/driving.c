/*
    Uses hardcoded variables like total miles driven
    the cost per gallon, the miles per gallon, the
    parking fees, and the daily tolls to use in a formula
    that calculates the average driving cost per day a
    person may expect to have in their circumstances.
    It also cleanly prints out all of the data in an easy
    to read and understand format.

    K D McCormick, 2022-06-23
*/

#include <stdio.h>

int main(void) {
    // Initialize base variables
    int total_miles_driven = 35;
    double cost_per_gallon = 3.25;
    double miles_per_gallon = 27.50;
    double parking_fees = 2.50;
    double daily_tolls = 3.80;
    double daily_driving_cost = 0.0;

    // Output what each variable signifies
    printf("Miles driven per day: %i\n", total_miles_driven);
    printf("Cost per gallon of gasoline: $%.2f\n", cost_per_gallon);
    printf("Miles per gallon: %.2f\n", miles_per_gallon);
    printf("Daily parking fees: $%.2f\n", parking_fees);
    printf("Daily tolls: $%.2f\n", daily_tolls);

    // Calculate daily driving cost
    daily_driving_cost = total_miles_driven / miles_per_gallon * cost_per_gallon + parking_fees + daily_tolls;
    printf("Your driving cost per day is $%.2f\n", daily_driving_cost);
    return 0;
}