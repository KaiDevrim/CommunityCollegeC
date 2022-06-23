/*
    This program sets an age in years,
    calculates the approximate age in days,
    and prints them both, labeled properly.

    K D McCormick, 2022-06-22
*/

#include <stdio.h>

int main(void) {
    int years = 21;
    int days = years * 365;
    printf("An age of %i is about %i days.\n", years, days);
    return 0;
}