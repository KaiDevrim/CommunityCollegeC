/*
 * Define constant integers for
 * the test and student variables.
 * There are only 4 tests so the constant tests
 * variable should be set to a maximum of 4.
 * 
 * There are only 5 students so the students variable
 * should be set to 5.
 * 
 * Create a student struct with the following parameters
 * a long int for the id
 * an int for their year_in_college
 * a double array of size equal to the constant tests
 * variable called test_scores
 * 
 * Create a method that returns nothing called
 * show_student_average that accepts a single student struct
 * The method should print the person's id then loop through
 * their test scores and create an average of it
 * After the loop, print out the average test score for
 * the person
 * 
 * In the main method create an array of students of
 * max length set to the constant students variable.
 * The students should have the same data given on
 * the assignment page.
 * 
 * Then create two loops that will iterate through the
 * columns of each test score and add it to a variable
 * After the inner loop, print out the total average
 * for the test that we looped through.
 * 
 * K D McCormick, 2022-07-08
*/

#include <stdio.h>

const int TESTS = 4;
const int STUDENTS = 5;

struct student {
	long int id;
	int year_in_college;
	double test_scores[TESTS];
};
typedef struct student student;

void show_student_average(student person) {
	printf("%li", person.id);
	double average_test_score = 0.0;
	for (int i = 0; i < TESTS; i++) {
		average_test_score = average_test_score + person.test_scores[i];
	}
	average_test_score = average_test_score / TESTS;
	printf("\t%.2f\n", average_test_score);
}

int main(void) {
	student people[STUDENTS] = {
		{9781473, 1, {97.25, 96.5, 90, 87.5}},
		{6014552, 2, {77.8, 80.0, 81.5, 79.5} },
		{3773909, 2, {85.5, 79, 79, 90.5}},
		{8102274, 1, {88.9, 90.5, 92, 94}},
		{4582934, 1, {90, 90, 92, 89.5}}
	};
	double total_average = 0.0;
	printf("ID \tAverage Test Score\n");
	for (int i = 0; i < STUDENTS; i++) {
		show_student_average(people[i]);
	}
	
	printf("\nTest \tAverage Score\n");
	for (int i = 0; i < TESTS; i++) {
		printf("%i \t", i+1);
		for (int j = 0; j < STUDENTS; j++) {
			total_average = total_average + people[j].test_scores[i];
		}
		total_average = total_average/STUDENTS;
		printf("%.2f\n", total_average);
		total_average = 0.0;
	}
	return 0;
}
