/**
* @brief Assignment 7
* @name Kern Espinoza
*/

using namespace std;
#include <iostream>
#include <cmath>
#include "gradeFunctions.h"

void getArrayData(int scores[], int size)
{
    int newArrayEntry;

    for (int i = 0; i < size; i++)
    {
        cin >> newArrayEntry;
        scores[i] = newArrayEntry;
    }
}

double average(const int scores[], int size)
{
    if (size == 0) // Avoid division by zero
        return 0;

    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += scores[i];
    }

    return (sum / size);
}

double standardDeviation(const int scores[], int size, double mean)
{
    if (size == 0) // Avoid division by zero
        return 0;

    double squaredDiffSum = 0; // The sum of the squared differences (to be averaged)

    for (int i = 0; i < size; i++)
    {
        squaredDiffSum += pow(((double)scores[i] - mean),2);// Find difference & square
    }

    return sqrt(squaredDiffSum / size);
}

char getLetterGrade(int score, double mean, double stdDev)
{
    double meanDifference = (score - mean); // The difference between one score and the mean score
    double stdDsAboveAvg = (meanDifference / stdDev); // Standard Deviations Below Average

    if (stdDsAboveAvg >= 1)
        return 'A';
    else if (stdDsAboveAvg >= 0.5)
        return 'B';
    else if (stdDsAboveAvg >= -0.5)
        return 'C';
    else if (stdDsAboveAvg >= -1)
        return 'D';

    return 'F';
}

#include "gradeFunctions.h"

