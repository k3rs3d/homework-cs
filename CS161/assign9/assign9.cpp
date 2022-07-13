/**
* @brief Assignment 9
* @name Kern Espinoza
*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "datafileFunctions.h"

// File/Format options:
#define DATA_FILENAME "data.csv"
#define DELIMITER_CHAR ','

using namespace std;

int main()
{
    // Prepare to gather data.
    FireReport fires[numReportsToPull];

    // Try to read the file.
    if (GetFireReportsFromFile(fires, DATA_FILENAME))
    {
        // If the file was read correctly, get ready to take user input.
        bool runProgram = true;
        string inputCommand;

        // Keep taking inputs until the user quits.
        while (runProgram)
        {
               runProgram = DisplayReportsFromInterpretedCommand(fires);
               cout << endl;
        }
    }

    return 0;
}
