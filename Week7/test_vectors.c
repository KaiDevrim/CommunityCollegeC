/*
 * Create a series of 3 vectors then make a variable for choice.
 * Then in a while loop, ending when choice is 4 do the following
 * 
 * Print the choices for the user then take the user's choice
 * as an int into the choice variable.
 * 
 * If the choice is 1 then print out the information needed
 * for the user and capture the input to send to the add()
 * function, then display the vector using the display_vector()
 * function.
 * 
 * If the choice is 2 then print out the information needed
 * for the user and capture the input to send to the scale()
 * function, then display the vector using the display_vector()
 * function.
 * 
 * If the choice is 3 then print out the information needed
 * for the user and capture the input to send to the dot_product()
 * function, then display the output of the dot product using printf().
 * 
 * If the choice is 4 then print Goodbye and return 0;
 * K D McCormick, 2022-07-20
*/

#include <stdio.h>
#include "vector2d.h"
#include "vector2d.c"



int main(void) {
	vec2d v1;
	vec2d v2;
	vec2d v3;
	int choice = 0;
	do {
	printf("\n1) Add vectors; 2) Scale vector; 3) Dot product; 4) Exit: ");
	scanf("%i", &choice);
	if (choice == 1) {
		printf("Enter the x and y values for the first vector, separated by spaces: ");
		scanf("%lf %lf", &v1.x, &v1.y);
		printf("Enter the x and y values for the second vector, separated by spaces: ");
		scanf("%lf %lf", &v2.x, &v2.y);
		v3 = add(v1, v2);
		printf("Sum is ");
		display_vector(v3);
	}
	
	else if (choice == 2) {
		double factor = 0.0;
		printf("Enter the x and y values for the vector, separated by spaces: ");
		scanf("%lf %lf", &v1.x, &v1.y);
		printf("Enter scaling factor: ");
		scanf("%lf", &factor);
		v3 = scale(v1, factor);
		printf("Scaled vector is ");
		display_vector(v3);
	}
	
	else if (choice == 3) {
		double result = 0.0;
		printf("Enter the x and y values for the first vector, separated by spaces: ");
		scanf("%lf %lf", &v1.x, &v1.y);
		printf("Enter the x and y values for the second vector, separated by spaces: ");
		scanf("%lf %lf", &v2.x, &v2.y);
		result = dot_product(v1, v2);
		printf("Dot product is %.3f", result);
	}
	
	else if (choice == 4) {
		printf("Goodbye.");
		return 0;
	}
} while(choice != 4);
printf("Goodbye.");
return 0;
}
