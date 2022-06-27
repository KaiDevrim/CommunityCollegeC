/*
    Make a double array with a length of 20.
    Ask for user input
    While user input > 0.0 then continue asking
    if user input == 0.0 || 0 then break
    keep a count of amount of elements actually in the array
    keep a count of total weight

    find closest number to average
    loop through all the numbers in the array
    find the minumum deviation
    find all numbers within the minumum deviation
    put them in an array
    loop through them all
    check if they equal the minumum deviation
    print the amount of items closest to average
    print the items closest to average

    K D McCormick, 2022-06-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	// Initialize variables in a way that doesn't leave them grabbing values from memory.
    double product_weights[20];
    double input_weight = 0.0;
    int tracker = 0;
    double total_weights = 0.0;
    double average = 0.0;
    
    // Get the input first before we do checking in the do/while loop.
    printf("Enter a weight in kg, or 0 to quit: ");
    scanf("%lf", &input_weight);
    do
    {
		// Quit loop when the user wants to quit.
		if (input_weight == 0.000000) {
			break;
		}
		// We do not need to care about negative values.
		if (input_weight < 0.000000)
        {
            printf("Ignoring negative value.\n");
        }
        // Add the input to array and increment tracker so we know how many items are in the array.
        else
        {
            product_weights[tracker] = input_weight;
            total_weights = total_weights + input_weight;
            tracker = tracker + 1;
        }
        // After doing all the logic we ask the user for more input.
        printf("Enter a weight in kg, or 0 to quit: ");
        scanf("%lf", &input_weight);
        // Since the max items we have is 20 we stop there or when the user quits.
    } while (input_weight != 0.000000 || tracker < 20);
    // Calculate the average from all the items in array.
    average = total_weights / tracker;
    // Print information that we gathered from the user.
    printf("Number of entries: %i\n", tracker);
    printf("Average weight: %.3lf kg\n", average);
    
    // First, find the minimum deviation from the average.
	double minimum_deviation = fabs(product_weights[0] - average);
	for (int i = 0; i < 20; i++) {
		if (fabs(product_weights[i] - average) < minimum_deviation) {
			minimum_deviation = fabs(product_weights[i] - average);
		}
	}

	// Now put all the elements with the minimum deviation.
	// Into a new array named "closest".
	int n_closest = 0;
	double closest[20];
	for (int i = 0; i < 20; i++) {
		if (fabs(product_weights[i] - average) == minimum_deviation) {
			closest[n_closest] = product_weights[i];
			n_closest++;
		}
	}
	
	printf("Number of items closest to average: %i\n", n_closest);
	printf("The item(s) - weight in kg:\n");
	// Loop through all the items in closest averages array and print them.
	for (int i = 0; i < n_closest; i++) {
		printf("%lf \n", closest[i]);
	}
    return 0;
}
