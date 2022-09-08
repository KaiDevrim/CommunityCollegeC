/*
 * Write a series of functions to manipulate strings.
 * Use pointers wherever possible. Each function is preceded
 * by the description of the function's purpose and its
 * parameters.
 */
 
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * Return the length of the given string.
 */
int str_length(const char *p_str) {
	return strlen(p_str) - 1;
}

/*
 * Trim whitespace from the beginning and end of a given string.
 */
void trim(const char *p_str, char *p_result) {
	int j = 0;
    for (int i = 0; i < str_length(p_str); i++) {
		if (!(isspace(p_str[i]))) {
			p_result[j] = p_str[i];
			j++;
		}
	}
}

/*
 * This function finds the position of a delimiter in
 * a string, starting at a given position. Returns -1
 * if the delimiter is not found. If the start position is less than zero,
 * use zero. If the start position is greater than the string length,
 * return -1.
 */
int find_char(char delimiter, const char *p_str, int start_position) {
	for (int i = 0; i < str_length(p_str); i++) {
		if (p_str[i] == delimiter) {
			return i;
		}
	}
    return -1;
}

/*
 * Copy the substring of a given string, from the given
 * start position up to but not including the given end position.
 * If the start position is less than 0, start at 0.
 * The end position may be greater than the string length.
 * If the end position is -1, take the substring up to the end of the string.
 */
void substring(const char *p_str, int start_position, int end_position, char *p_result) {
	int j = 0;
    for (int i = 0; i < str_length(p_str); i++) {
		if ((i > start_position) && (end_position == -1)) {
			p_result[j] = p_str[i];
			j++;
		}
		else if ((i < end_position) && (i > start_position)) {
			p_result[j] = p_str[i];
			j++;
		}
	}
}

/*
 * Split an array of characters on a delimiter, calculating an
 * array of integers giving the positions of the delimiter in the
 * string, with -1 as the last entry in the array.
 * 
 * Example:
 * char date[20] = "2021-03-15";
 * int positions[21]; // every character could be a delimiter
 * split('-', date, positions); // 4, 7, -1
 */
void split(char delimiter, const char *p_str, int *position_array)
{
	int j = 0;
    for (int i = 0; i < str_length(p_str); i++) {
		if (p_str[i] == delimiter) {
			position_array[j] = i;
			j++;
		}
	}
}
        

int main(void) {
    char trim_test[100] = " \t abc  def \n \t   ";
    char trim_result[100];
    trim(trim_test, trim_result);
    printf("Trimmed string: |%s|\n", trim_result); // |abc  def|
    
    int trimmed_length = str_length(trim_result);
    printf("Trimmed length: %d\n", trimmed_length); // 8
    
    char find_test[100] = "abc:defg:hij";
    int pos1 = find_char(':', find_test, 0);
    int pos2 = find_char(':', find_test, 4);
    int pos3 = find_char('?', find_test, 0);
    int pos4 = find_char(':', find_test, 25);
    int pos5 = find_char('e', find_test, -10);
    // should print out 3, 8, -1, -1, and 5
    printf("find_char results: %d, %d, %d, %d, and %d\n",
        pos1, pos2, pos3, pos4, pos5);
    
    char word[15] = "dumbwaiters";
    char part_word[15];
    substring(word, 4, -1, part_word);
    // should print out waiters
    printf("Substring of %s from position 4 to end is %s\n", word, part_word);
    
    char date[20] = "2021-03-15";
    int split_points[21]; // could have a delimiter at each position
    split('-', date, split_points);
    
    int index = 0;
    printf("Results of split: ");
    do {
        printf("%d ", split_points[index]);
    } while (split_points[index++] != -1);
    printf("\n");
    
    char year[10];
    char month[10];
    char day[10];
    substring(date, 0, split_points[0], year);
    substring(date, split_points[0] + 1, split_points[1], month);
    substring(date, split_points[1] + 1, split_points[2], day);
    printf("Reformatted date: %s/%s/%s\n", month, day, year); // 03/15/2021
    
    printf("\n");
    return 0;
}
