/*
 * This structure represents my favourite games and its review scores,
 * install size, and game name. The review score is from metacritic.
*/

struct game {
	char game_name[64];
	double review_score;
	double install_size;
};

struct game games = {
	{"Factorio", 90, 890},
	{"Half-Life 2", 96, 3500},
	{"Super Smash Bros. Ultimate", 93, 14000}
};

/*
 * This program calculates parking charges. It asks the user
 * for the time a vehicle entered and exited the parking lot in
 * 24-hour format (such as 1029 or 1453).
 * 
 * It calculates the number of hours and minutes the vehicle was parked,
 * and uses that to figure out the cost:
 *      $2.00 for the first three hours
 *      $0.50 for each additional hour or fraction thereof
 * 
 * The program then asks the user if they wish to enter another set
 * of data (Y for yes or N for no), and then repeats the process if
 * the user enters Y, or ends the program if they enter N.
 */
 
#include <stdio.h>
#include <ctype.h>  // utilities for characters
#include <stdbool.h> // for easier use of booleans

/*
 * Write a function named valid_time() that takes an integer
 * representing a time in 24-hour format, such as 1329 or 0945 and
 * returns a boolean.
 * 
 * This function checks that the hours part (the first two digits)
 * are in the range 0-23. If not, the function prints an error message.
 * 
 * It then checks that the minutes part (the last two digits)
 * are in the range 0-59. If not, the function prints an error message.
 * 
 * If both the hours and minutes are OK, the function returns true;
 * otherwise it returns false 
 */

bool valid_time(int time) {
	bool is_valid = false;
	if ((time / 100) >= 0 && (time / 100) <= 23) {
		is_valid = true;
	}
	if ((time % 100) >= 0 && (time%100) <= 59) {
		is_valid = true;
	}
	if ((time / 100) < 0 || (time / 100) > 23) {
		is_valid = false;
		printf("Hours must be from 0-23\n");
	}
	if ((time % 100) < 0 || (time % 100) > 59) {
		is_valid = false;
		printf("Minutes must be from 0-59\n");
	}
	return is_valid;
}

//===============================================

/*
 * Write a function named calculate_charges() that takes two integers
 * representing the number of hours and the number of minutes that a person
 * was parked. 
 * 
 * This function returns a double for the parking charge:
 * $2.00 minimum fee to park for up to three hours
 * and an additional $0.50 per hour for each hour or part thereof
 * over three hours.
 */

//===============================================

double calculate_charges(int hours, int minutes) {
	double charges = 0.0;
	if (hours <= 3) {
		charges = 2.0;
	}
	else {
		hours = hours - 3;
		charges = hours * 0.5;
	}
	if (minutes >= 1) {
		charges = charges + 0.5;
	}
	return charges;
}

/*
 * Write a function named get_time() that takes an array of
 * characters as its argument - this is the prompt string.
 * 
 * The function will display the prompt and input a
 * time in 24-hour format as an integer. It will do this
 * repeatedly as long as the input is not a valid time;
 * once the time is valid, it returns the time as an integer.
 * 
 * This function *must* call the valid_time() function to determine
 * if the time the user gave is valid or not.
 */


//===============================================

int get_time(char prompt[]) {
	int time = 0;
	bool valid = false;
	do {
		printf("%s", prompt);
		scanf("%i", &time);
		if (valid_time(time)) {
			valid = true;
			return time;
			break;
		}
	} while(!valid);
	
	return time;
}

/*
 * This function takes no input and returns no value;
 * it is a utility function to clear out the input buffer.
 */
void clear_keyboard(void) {
    while (getchar() != '\n') {
        // keep going
    }
}

/*
 * Write a function named get_yes_no() that takes an array of
 * characters as its argument - this is the input prompt.
 * 
 * This function will repeatedly display the prompt and get a
 * single-character response until the user enters either Y or N
 * in upper or lower case. If the user enters a character other than
 * Y or N, the function prints an appropriate error message.
 * 
 * It returns true if the user entered Y or y, false otherwise.
 * 
 * Hint: use a do/while loop, and call clear_keyboard() at the beginning
 * of the loop before displaying the input prompt. 
 */

//===============================================

bool get_yes_no(char prompt[]) {
	char input;
	clear_keyboard();
	printf("Enter more data? (Y/N): ");
	scanf("%c", &input);
	do {
		if (input == 'y' || input == 'Y') {
			return true;
		}
		else {
			return false;
		}
		clear_keyboard();
		printf("Enter more data? (Y/N): ");
		scanf("%c", &input);
	} while(input == 'y' || input == 'Y');
	return true;
}

// Leave the main() function exactly as it is here.

int main(void)
{
    int start_time = 0;
    int end_time = 0;
    bool proceed = false;
     
    do
    {
        start_time = get_time("Enter starting time in 24-hour format: ");
        end_time = get_time("Enter ending time in 24-hour format: ");
        
        // Split the starting and ending times into their hours and minutes
        int start_hr = start_time / 100;
        int start_min = start_time % 100;
        
        int end_hr = end_time / 100;
        int end_min = end_time % 100;
        
        // Calculate the total number of minutes the vehicle was parked
        int duration = (end_hr - start_hr) * 60 + (end_min - start_min);
        
        // And split that into hours and minutes
        int duration_hr = duration / 60;
        int duration_min = duration % 60;
        
        // Then calculate the charge for parking and print the result
        double charge = calculate_charges(duration_hr, duration_min);
        printf("Charge for parking %i hr %i min: $%.2f\n", duration_hr, duration_min, charge);
        
        proceed = get_yes_no("Enter more data? (Y/N): ");
        printf("\n"); // for spacing
        
    } while (proceed);

    return 0;
}
