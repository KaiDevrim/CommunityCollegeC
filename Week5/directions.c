/*
 * Psuedocode:
 * 
 * Create city structure that contains name at max length of 20,
 * a latitude and longitude double variable.
 * A maximum number of cities integer.
 *
 * Then make a display_city function that takes in the city struct
 * as a variable called cities
 * Then print out the city name, followed by its exact coords
 * gotten from the latitude and longitude.
 * 
 * Call the display_city function from the main function.
 * The main function should have an array of cities with max items
 * equal to the previously set, N_CITIES variable.
 * Fill the data with the given data on the assignment page.
 * 
 * Call the display_city function in a loop with the array of cities
 * passed in.
 * 
 * Then make another function called display_direction_to that
 * takes in a destination_city and a starting_city and prints out
 * which direction the destination city is from the starting city.
 * 
 * K D McCormick, 2022-06-29
*/

#include <stdio.h>

const int N_CITIES = 6;

struct city {
	char name[20];
	double latitude;
	double longitude;
};

void display_city(struct city cities) {
	printf("%s", cities.name);
	printf("%.3lf\u00b0 %.3lf\u00b0\n", cities.latitude, cities.longitude);
}

void display_direction_to(struct city destination_city, struct city starting_city) {
	if(destination_city.latitude > starting_city.latitude) {
		printf("  south");
	}
	if(destination_city.latitude < starting_city.latitude) {
		printf("  north");
	}
	if(destination_city.longitude > starting_city.longitude) {
		printf("west");
	}
	if(destination_city.longitude < starting_city.longitude) {
		printf("east");
	}
}

int main(void) {
	struct city cities[N_CITIES] = {
		{"Paris", 48.85, 2.35},
		{"Antananarivo", -18.933, 47.517},
		{"Reno", 39.517, -119.817},
		{"Los Angeles", 34.050, -118.250},
		{"Detroit", 42.333, -83.033},
		{"Windsor (Ontario)", 42.283, -83.000}
	};
	int index = 0;
	for (int city_index = 0; city_index < N_CITIES; city_index++) {
		display_city(cities[city_index]);
	}
	for(int city_index = 0; city_index < N_CITIES; city_index++) {
		printf("%s is: \n", cities[city_index].name);
		for (int direction_index = 0; direction_index < N_CITIES; direction_index++) {
			index++;
			if (direction_index != city_index) {
			display_direction_to(cities[direction_index], cities[city_index]);
			printf(" of %s\n", cities[direction_index].name);
		}
		}
	}
}
