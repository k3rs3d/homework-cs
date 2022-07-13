/**
* @brief Assignment 7
* @name Kern Espinoza
*/

#ifndef GRADEFUNCTIONS_H
#define GRADEFUNCTIONS_H

using namespace std;

/**
 * @brief Reads in values from the console/keyboard into the 'scores' array.
 * @param scores An array containing every score.
 * @param size The size of the score array.
 */
void getArrayData(int scores[], int size);

/**
 * @brief Calculates the average of an array.
 * @param scores An array containing every score.
 * @param size The size of the score array.
 * @return
 */
double average(const int scores[], int size);

/**
 * @brief Calculates the standard deviation of an array, given its values & mean. (Population Sample)
 * @param scores An array containing every score.
 * @param size The size of the score array.
 * @param mean The average value of the scores in the array.
 * @return
 */
double standardDeviation(const int scores[], int size, double mean);

/**
 * @brief Calculates a letter grade for a single score, given a mean and standard deviation.
 * @param score An array containing every score.
 * @param mean The average value of the scores in the array.
 * @param stdDev The standard deviation of the scores in the array.
 * @return
 */
char getLetterGrade(int score, double mean, double stdDev);

#endif // GRADEFUNCTIONS_H
