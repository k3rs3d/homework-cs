/**
* @brief Assignment 7
* @name Kern Espinoza
*/

#include <iostream>
#include "gradeFunctions.h"

using namespace std;

int main()
{
    int size = 10; // How many scores to check.
    double scoreAverage = 0; // Averaged/mean score value.
    double stdDeviation = 0; // Standard deviation.

// Testing:

    // Get input:
    cout << "Enter 10 scores: ";
    int* scores = new int[size];
    getArrayData(scores, size);

    scoreAverage = average(scores, size);
    stdDeviation = standardDeviation(scores, size, scoreAverage);

    cout << endl << "The average is: " << scoreAverage << endl;
    cout << "The standard deviation is: " << stdDeviation << endl;
    cout << "Student: \t";

    for (int i = 0; i < size; i++)
    {
        cout << (i+1) << " ";
    }

    cout << endl << "Grade: \t\t";

    for (int i = 0; i < size; i++)
    {
        cout << getLetterGrade(scores[i], scoreAverage, stdDeviation) << " ";
    }

    cout << endl;
}
