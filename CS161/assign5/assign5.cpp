/**
* @brief Assignment 5
* @name Kern Espinoza
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
// Constants
const int monthToOutput = 4; // Only output logs from April.
const string outputDataSpace = "   "; // I wasn't sure exactly how to separate the data points in the output, but the professor example uses three spaces.
const char dateDelimOutput = 47; // Month/Day/Year is separated by slashes '/' in the output.
const char dateDelimInput = 45; // Month/Day/Year is separated by dashes '-' in the input.
const char timeDelimInput = 58; // Time is separated by colons ':' in the input.
const string listOfMonthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

// Open the log file.
ifstream inFile;
inFile.open("WebLog.txt");

// Was the file valid?
if(inFile.fail())
{
cout<<"Could not open the file." << endl;
return 0;
}

// Read the file:
while (!inFile.eof())
{
    // Read the line:
    string address, username, dateInputString, timeInputString, durationInMinutes, outputLine;
    inFile >> address >> username >> dateInputString >> timeInputString >> durationInMinutes;

    // Whether we just read an intelligible line.
    if (inFile.fail()) {
        cout << "End of readable data." << endl;
        break;
    }

    // Interpret the date:
    // First pull month/day/year values from the amalgamated date string.
    // To that end, determine where the first slash is at:
    int dateStringDayDelimIndex = dateInputString.find(dateDelimInput); // The date is the only uncertain '-' index (because month is always 3 chars & year is always 2)

    // The month number has to get figured out from the Jan/Feb/etc text.
    string dateMonthName = dateInputString.substr(dateStringDayDelimIndex+1,3);; // Jan, Feb, etc; located after the first deliminator
    int dateMonthNumber = 0; // 1 = January, etc

    // Try to match month text to a month number:
    for (int i = 0; i < 12; i++)
    {
        if (dateMonthName == listOfMonthNames[i])
        {
            dateMonthNumber = (i + 1);
            break;
        }
    }

    // Check whether this is a relevant month
    if (!(dateMonthNumber == monthToOutput))
    {
        // This isn't a month that we're interested in
        continue; // Skip this iteration of the while loop
    }

    // Now that the month has been checked, this must be a relevant line in the log, so continue figuring out the date:
    int dateDayNumber = stoi(dateInputString.substr(0,dateStringDayDelimIndex)); // The day starts at the beginning and extends to the first deliminator
    int dateYearNumber = stoi(dateInputString.substr(dateStringDayDelimIndex+5,2)); // The year starts after the second deliminator and is always 2 characters
    // Output username & formatted date:
    cout << username << outputDataSpace; // Username + space
    cout << dateMonthNumber << dateDelimOutput << dateDayNumber << dateDelimOutput << dateYearNumber <<  outputDataSpace; // Formatted date

    // Now it's time for the time
    // Figure out where the first colon is
    int timeStringHourDelimIndex = dateInputString.find(timeDelimInput);
    // Get hours & minutes from the string (seconds aren't needed)
    int timeHourNumber = stoi(timeInputString.substr(0,timeStringHourDelimIndex)); // The hour starts at the beginning and goes to the first deliminator
    int timeMinuteNumber = stoi(timeInputString.substr(timeStringHourDelimIndex+1,2)); // The minute starts after the first deliminator and is always 2 characters because of its leading zero

    // Output the formatted time:
    cout << (timeHourNumber <= 12 ? timeHourNumber : timeHourNumber - 12) << ":" << (timeMinuteNumber < 10 ? "0" : "") << timeMinuteNumber << (timeHourNumber > 12 ? "PM" : "AM") << outputDataSpace;

    // The last thing to output is the record's duration in minutes:
    cout << durationInMinutes << outputDataSpace << endl;
}

inFile.close();
return 0;
}
