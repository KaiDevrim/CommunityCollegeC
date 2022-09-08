/*
    Psuedocode:
    Declare and set the population to 308401808 as it was that in 2011.
    Print out the header
    For each year starting at 2011 and ending with 2020, print out the population

    To calculate the popula tion, every 9 seconds is a birth, every 10 seconds
    is a death, every 47 seconds is a net migrate gain. Using this we can assume
    a net gain of 1.53 humans a minute. Then we do
    1.53 * 60 (hours) * 24 (days) * 7 (weeks) * 4 (months) * 12 (years) to
    get a total of 740275 humans a year. Then every year we add the
    increase per year to the existing population count and print out
    that information.

    K D McCormick, 2022-06-24
*/
#include <stdio.h>

int main() {
    // Declare and initialize the constants
    long int population = 308401808;
    int increase_per_year = 740275;
    // Set the header
    printf("Year  Estimated Population\n");
    // Start 2011 then go to 2020 inclusive
    for (int year = 2011; year <= 2020; year++)
    {
        // Print out the population every year
        printf("%i  %i\n", year, population);
        // Increase the population every year
        population = population + increase_per_year;
    }
    // End the program
    return 0;
}