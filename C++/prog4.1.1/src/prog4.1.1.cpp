//============================================================================
// Name        : prog4.1.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int numCourses = 0;			// number of courses
	int** indivGrade = NULL;	// individual grades of assignments in courses
	int* numGradesPerCourse = NULL;	// number of grades per course
	float* courseGrade = NULL;	// grades for each of the courses
	float overallGrade = 0.0f;	// overall program grade

	// Enter the number of courses
	do {
		cout << "Enter number of courses: ";
		cin >> numCourses;
	} while (numCourses < 0);

	if (numCourses == 0) return 0;


	// Allocate storage for "array of rows" of individual grades
	indivGrade = new int* [numCourses];

	// Allocate storage for number of grades per course
	numGradesPerCourse = new int [numCourses];

	// Allocate storage for course grades
	courseGrade = new float[numCourses];

	// Input data for each course.
	for (int idxCourse = 0; idxCourse < numCourses; idxCourse++)
	{
		// Enter number of grades in each course.
		do {
			cout << "\n-----------------\nEnter number of grades in course #" << idxCourse+1 << ": ";
			cin >> numGradesPerCourse[idxCourse];
		} while (numGradesPerCourse[idxCourse] < 1);

		// Allocate storage for individual grades of assignments.
		indivGrade[idxCourse] = new int [numGradesPerCourse[idxCourse]];

		// Enter individual grades of assignments
		for (int idx = 0; idx < numGradesPerCourse[idxCourse]; idx++)
		{
			do {
				cout << "Enter grade #" << idx+1 << " for course #" << idxCourse+1 << " (1-5): ";
				cin >> indivGrade[idxCourse][idx];
			} while (indivGrade[idxCourse][idx] < 1 || indivGrade[idxCourse][idx] > 5);
		}
	}



	// Calculate averages.
	overallGrade = 0.f;

	for (int idxCourse = 0; idxCourse < numCourses; idxCourse++)
	{
		courseGrade[idxCourse] = 0.f;
		for (int idx = 0; idx < numGradesPerCourse[idxCourse]; idx++)
		{
			courseGrade[idxCourse] += indivGrade[idxCourse][idx];
		}
		courseGrade[idxCourse] /= numGradesPerCourse[idxCourse];

		overallGrade += courseGrade[idxCourse];
	}

	overallGrade /= numCourses;



	// Output results.
	cout << fixed << setprecision(2) << "\n\n------------------------------\n";
	for (int idxCourse = 0; idxCourse < numCourses; idxCourse++)
	{
		cout << "Course " << idxCourse+1 << ": final " << courseGrade[idxCourse] << ", grades: ";
		for (int idx = 0; idx < numGradesPerCourse[idxCourse]; idx++)
		{
			cout << indivGrade[idxCourse][idx] << " ";
		}
		cout << endl;
	}

	cout << "Overall final " << overallGrade << endl;


	//-----------------------------------------
	// Free memory

	for (int idxCourse = 0; idxCourse < numCourses; idxCourse++)
	{
		delete [] indivGrade;
	}
	delete [] courseGrade;
	delete [] numGradesPerCourse;
	delete [] indivGrade;

	return 0;
}
