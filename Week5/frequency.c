/*
 * Include the relevant libraries, like stdio and ctype for strings
 * Make a maximum length int of about 1024 o that the user
 * can type a lot before running out.
 * 
 * Make a frequencies array with a maximum length of 24 and initialize
 * every item in it to 0. Then make an index variable that will
 * act as an index when setting going through each letter of the
 * alphabet. Then make a character array of maximum length of 1024
 * that will hold the user's input.
 * 
 * Then print out the prompt for the user to enter in their input.
 * Then use fgets to store the string in the input variable and set
 * the maximum length to the same as the maximum length variable
 * created above. Then loop through the input of the user and break
 * when it reaches a end of line character like \r or \n.
 * 
 * Then make a do/while statement that loops through the input and
 * if the input is in the alphabet then add 1 to the frequency array
 * where the lowercase of the input - the character a is so that
 * the input starts at 0 and each character acts like the location
 * of the letter in the frequency array. End the do/while loop if
 * the input's index is a end of line character like \n or \r.
 * 
 * Then print out the characters in order of the alphabet by looping
 * from 0 to 24. Inside of the loop print out the integer + 65
 * as a character so that it starts at the ascii letter for A.
 * Then print out the frequency array at the for loop's index.
 * 
 * K D McCormick, 2022-07-04
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
	const int MAX_LEN = 1024;
	int frequencies[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int index = 0;
	char input[MAX_LEN];
	printf("Input lines of text. Press just ENTER when finished: \n");
	fgets(input, MAX_LEN, stdin);
	for (int i = 0; i < MAX_LEN; i++) {
		if (input[i] == '\n' | input[i] == '\r') {
			break;
		}
	}
	
	do {
		if (input[index] == '\n' || input[index] == '\r') {
			break;
		}
		if(isalpha(input[index])) {
			frequencies[tolower(input[index]) - 'a'] = frequencies[tolower(input[index]) - 'a'] + 1;
		}
		index++;
	} while(input[index] != '\n' || input[index] != '\r');
	
	for (int i = 0; i < 24; i++) {
		printf("%c: ", i+65);
		printf("%i\n", frequencies[i]);
	}
	return 0;
}
