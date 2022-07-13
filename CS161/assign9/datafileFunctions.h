/**
* @brief Assignment 9
* @name Kern Espinoza
*/

#ifndef DATAFILEFUNCTIONS_H
#define DATAFILEFUNCTIONS_H

#include <iostream>
#include <string>
using namespace std;

struct FireReport { string fireIdentifier; string fireName; double fireSizeInAcres; string fireDateAndTime; string fireGeneralCause; string fireLandType; };
const int numReportsToPull = 160; // Maximum number of lines to pull.

// Helper Functions:

/**
 * @brief StringContainsDigits Returns true if this string contains digits. Meant for verifying a string before trying to use stoi, etc, on it.
 * @param str The string to check for digits.
 * @return Returns true if this string contains digits. Otherwise false.
 */
bool StringContainsDigits(const string& str);

/**
 * @brief Returns a new Fire Report with information pulled from the given string.
 * @param dataString The (comma-deliminated) string containing the information that the Fire Report needs.
 * @return Returns a new Fire Report with data populated from the given string.
 */
FireReport CreateFireReportFromString(string &dataString);

/**
 * @brief Prints the titles of each column, e.g.: "Fire Name", "Fire Date", etc., corresponding with each data point.
 */
void PrintDataColumnTitles();

/**
 * @brief Prints a single Fire instance on its own line.
 * @param fire Which particular report to display.
 */
void PrintFireReport(FireReport fire);

/**
 * @brief Prints every valid FireReport in an array of FireReports.
 * @param fires The master-list of fires to print from.
 */
void PrintAllFireReports(FireReport fires[numReportsToPull]);

/**
 * @brief Takes an array of (presumably blank) Fire Reports, and fills out their information from the given data file. Returns true/false depending on whether the file read worked.
 * @return Returns true if reading was successful.
 */
bool GetFireReportsFromFile(FireReport fires[numReportsToPull], string dataFilename = "data.csv");


// Part 3 : Output single records

/**
 * @brief Asks the user to distinguish between a Name search and ID search. Then searches the FireReport array for the given record and displays it.
 * @param fires The struct array to search for a certain record.
 */
void PrintSingleFireFromPrompt(FireReport fires[numReportsToPull]);


// Part 4 : Output matching records

/**
 * @brief Prompts the user to enter a date (MM/DD/YYYY) and then prints all records within the FireReport array which match that date.
 * @param fires The struct array to search for records.
 */
void PrintFiresOnDate(FireReport fires[numReportsToPull]);

/**
 * @brief Prompts the user to enter a fire cause (e.g., "Lightning"), and then prints all records within the FireReport array which match that cause.
 * @param fires The struct array to search for records.
 */
void PrintFiresOfCause(FireReport fires[numReportsToPull]);


// Part 5 : Find Max/Min

/**
 * @brief PrintMinMaxByCause Prompts the user for a fire cause (e.g., "Smoking"), then prints the largest and smallest relevant fires (by area).
 * @param fires The struct array to search for records.
 */
void PrintMinMaxByCause(FireReport fires[numReportsToPull]);

/**
 * @brief PrintMinMaxByLand Prompts the user for a land type (e.g., "State"), then prints the largest and smallest relevant fires (by area).
 * @param fires The struct array to search for records.
 */
void PrintMinMaxByLand(FireReport fires[numReportsToPull]);


// Part 6 : Aggregate data

/**
 * @brief PrintAverageFireAreaByCause Prompts the user to enter a fire cause (e.g., "Recreation"), then loops through all relevant records and displays the average fire size.
 * @param fires The struct array to search for records.
 */
void PrintAverageFireAreaByCause(FireReport fires[numReportsToPull]);

/**
 * @brief PrintAverageFireAreaByLand Prompts the user to enter a land type (e.g., "BLM"), then loops through all relevant records and displays the average fire size.
 * @param fires The struct array to search for records.
 */
void PrintAverageFireAreaByLand(FireReport fires[numReportsToPull]);

// Functions for selecting the data:
/**
 * @brief DisplayReportsFromInterpretedCommand This is the main command-interpreting function which allows the user to select a category of reports (e.g., "Single", "Aggregate", etc).
 * @return Returns true if the program should keep running. Returns false if the user wants to stop.
 */
bool DisplayReportsFromInterpretedCommand(FireReport (&fires)[numReportsToPull]);

#endif // DATAFILEFUNCTIONS_H
