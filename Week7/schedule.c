/*
 * Create the days variables by starting with Monday as 1
 * and then changing the bits using << for each day
 * Then define a LANG variable.
 * 
 * If the lang is set to 0 use English, else if its 1 use
 * German.
 * 
 * Create a constant int for the maximum number of classes.
 * Then make the schedule struct that holds the
 * name in a 20 long char array, the days in a bitfield of
 * length 7, the start_hour and end_hour in a bitfield of
 * length 5 and the end_minute and start_minute in a bitfield of
 * length 6.
 * 
 * Then make a has_conflict function that takes in two schedules
 * and returns if it conflicts or not. It checks for conflicts
 * by comparing the start time and end time for both schedules
 * given.
 * 
 * Then make a display function that will display the conflicting
 * information.
 * 
 * In the main function create a current schedule struct of
 * length MAX_CLASSES then iterate through it and checking
 * if each course conflicts with another and displaying the data
 * when it does.
*/

#define MONDAY 1
#define TUESDAY MONDAY << 1
#define WEDNESDAY TUESDAY << 1
#define THURSDAY WEDNESDAY << 1
#define FRIDAY THURSDAY << 1
#define SATURDAY FRIDAY << 1
#define SUNDAY SATURDAY << 1
#define LANG 1

#if LANG == 0
	char DAYS[7][3] = {"M", "T", "W", "Th", "F", "Sa", "Su"};
	char conflict[20] = "conflicts with";
#elif LANG == 1
	char DAYS[7][3] = {"Mo", "Di", "Mi", "Do", "Fr", "Sa", "So"};
	char conflict[25] = "steht in Konflikt mit";
#endif

#include <stdio.h>
#include <string.h>
const int MAX_CLASSES = 8;

typedef struct schedule {
	char name[20];
	char days : 7;
	unsigned int start_hour : 5;
	unsigned int start_minute : 6;
	unsigned int end_hour : 5;
	unsigned int end_minute : 6;
	
} schedule;

_Bool has_conflict(schedule sect_a, schedule sect_b) {
		if (sect_a.start_hour >= sect_b.start_hour && 
		sect_a.start_minute >= sect_b.start_minute &&
		sect_a.end_hour >= sect_b.end_hour && 
		sect_a.end_minute >= sect_b.end_minute) {
			return 1;
		}
		else {
			return 0;
		}
	return 0;
}

void display(schedule sect) {
	char day[20];
	for (int i = 0; i < 6; i++) {
			if (sect.days >> i & 1) {
				strcpy(&day[i], DAYS[i]);
			}
	}
	printf("%s %s (%i%i-%i%i)", sect.name, day, sect.start_hour,
	sect.start_minute, sect.end_hour, sect.end_minute);
}

int main(void) {
	schedule current[MAX_CLASSES] = {
		{"ECON 101", MONDAY | WEDNESDAY, 9, 15, 11, 35},
		{"PHYS 002", TUESDAY | THURSDAY, 10, 25, 13, 00},
		{"COMSC 079C", MONDAY, 7, 45, 9, 30},
		{"ACCTG 0063A", WEDNESDAY | FRIDAY, 10, 15, 12, 35},
		{"CHEM 001", TUESDAY | THURSDAY, 17, 00, 19, 25},
		{"MATH 017", MONDAY | TUESDAY | WEDNESDAY| THURSDAY, 13, 05, 15, 45},
		{"ART 099", TUESDAY | THURSDAY, 12, 05, 16, 35}
	};
	int j = 1;
	for (int i = 0; i < MAX_CLASSES; i++) {
		if ( (has_conflict(current[j], current[i])) && (j != i)) {
			display(current[j]);
			printf(" %s ", conflict);
			display(current[i]);
			printf("\n");
		}
		if (i == 8) {
			j++;
			i = j;
		}
	}
	return 0;
}
