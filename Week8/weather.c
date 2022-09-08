/*
 * Create a constant variable for the file name
 * Then make an array for each month.
 * Then make a constant int for the line length
 * Then make a structure for the data, setting
 * the following data
 *
 * The year, month, and day as an int
 * The max and min as double
 *
 * In the main function open the input file
 * and test if it can open, if not then
 * throw an error. Else open the file
 * and perform the rest of the operations.
 *
 * Then ask for the file name and repeat
 * if it cannot open the file. Then
 * open the file that was created and do the
 * following on it.
 *
 * Write the header to the file.
 * Make two data structs and two doubles
 * for average min and max.
 * Then loop through each line of the file
 * and set the previous.day to current.day
 * unless it is the next month. Then keep
 * checking if the previous.month
 * is equal to the current.month and if it
 * is then increase previous.month by 1.
 * Then calculate the min and max averages
 * and write it to the file.
 * Loop through the file until the end of the file.
 *
 * K D McCormick, 2022-07-20
 */
#include <stdio.h>
const char in_file_name[30] = "san_jose_temperature_2020.txt";
const char * MONTHS[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
const int MAX_LINE_LENGTH = 28;
typedef struct data {
	int year;
	int month;
	int day;
	double max;
	double min;
} data;
int main() {
	FILE *infile, *outfile;
	char out_file_name[63];
	infile = fopen(in_file_name, "r");
	if (infile == NULL) {
		printf("Unable to open file %s", in_file_name);
		return 0;
	}
	else {
		do {
			printf("Enter output file name: ");
			scanf("%s", out_file_name);
		} while(fopen(out_file_name, "w") == NULL);

		outfile = fopen(out_file_name, "a");
		if (outfile == NULL) {
			printf("Unable to open output file %s", out_file_name);
		}
		else {
			fprintf(outfile, "Mon./Year Avg Max  Avg Min (°C)\n");
			data current = {2022,01,01,0.0,0.0};
			data previous = {2022,01,01,0.0,0.0};
            double avg_min = 0.0;
            double avg_max = 0.0;
			do {
				fscanf(infile, "%d %d %d   %lf   %lf\n", &current.year, &current.month, &current.day, &current.max, &current.min);
                if (previous.month == current.month) {
                    previous.day = current.day;
                }
                if (previous.month != current.month) {
                    previous.month++;
                    avg_min = previous.min / previous.day;
                    avg_max = previous.min / previous.day;
                    fprintf(outfile, "%s %i %.3lf %.3lf\n", MONTHS[previous.month - 2], current.year, avg_max, avg_min);
                    avg_min = 0.0;
                    avg_max = 0.0;
                    previous.max = 0.0;
                    previous.min = 0.0;
                }
				previous.max += current.max;
				previous.min += current.min;
			} while(!feof(infile));
            avg_min = previous.min / previous.day;
            avg_max = previous.max / previous.day;
            fprintf(outfile, "%s %i %.3lf %.3lf\n", MONTHS[current.month - 1], current.year, avg_max, avg_min);
		}
	}

	fclose(infile);
	fclose(outfile);
	return 0;
}
