/**
* @brief Assignment 9
* @name Kern Espinoza
*/

using namespace std;

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "datafileFunctions.h"

bool StringContainsDigits(const string& str)
{
    return (string::npos != str.find_first_of("0123456789"));
}

string StringToLowercase(string upperString)
{
    for (string::size_type i = 0; i < upperString.length(); i++)
    {
        if (upperString[i] <= 'Z' && upperString[i] >= 'A')
                upperString[i] -= ('Z' - 'z');
    }

    return upperString;
}

FireReport CreateFireReportFromString(string &dataString)
{
    FireReport newFire;

    // Create a stringstream from line in order to separate by commas
    stringstream sstream(dataString);

    // Extract data
    // Fire ID:
    if (getline(sstream, dataString, ','))
    { newFire.fireIdentifier = dataString; }
    // Fire Name:
    if (getline(sstream, dataString, ','))
    { newFire.fireName = dataString; }
    // Fire Size:
    if (getline(sstream, dataString, ',') && StringContainsDigits(dataString))
    { newFire.fireSizeInAcres = stod(dataString); }
    // Fire Date&Time:
    if (getline(sstream, dataString, ',') && StringContainsDigits(dataString))
    { newFire.fireDateAndTime = dataString; }
    // Fire General Cause (how):
    if (getline(sstream, dataString, ','))
    { newFire.fireGeneralCause = dataString; }
    // Fire Land Type (private, BLM, etc):
    if (getline(sstream, dataString, ','))
    { newFire.fireLandType = dataString; }

    return newFire;
}

bool GetFireReportsFromFile(FireReport fires[numReportsToPull], string dataFilename)
{
    // Minion variables.
    int line = 0; // Keeps track of which fire report index we're on.
    string lineString; // Whole line as one string.
    string lineData; // An individual data point within the line.

    // Open sesame.
    ifstream inFile;
    inFile.open(dataFilename);

    // Was file valid / any problems opening it?
    if(inFile.fail() || !inFile.is_open() || !inFile.good()) // some of these conditions may be redundant, but whatever.
    {
        cout<<"Could not open file: " << dataFilename << endl;
        return false; // Bye!
    }

    // Skip first line (it's just the column names)
    getline(inFile, lineString);

    // Read the file as much as possible.
    while (!inFile.eof())
    {
        // Cancel reading after the maximum lines have been reached.
        if (line >= numReportsToPull)
            break;

        getline(inFile, lineString); // Read the line and save the whole thing as one string.
        // TODO: Make sure the line isn't blank
        FireReport newFire = CreateFireReportFromString(lineString); // Populate the Fire Report struct with the data from that string.

        // Add this fire instance to the array & increment the index.
        fires[line] = newFire;
        line++;
    }

    // Done.
    inFile.close();

    return true;
}

void PrintDataColumnTitles()
{
    // Show the columns for each data point:
    printf("%-28s | %-12s | %-22s | %-12s | %-14s | %-40s", "Fire Name", "Fire ID", "Date/Time", "Fire Size", "Land Type", "Cause");
    // Line divider.
    printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
}

void PrintFireReport(FireReport fire)
{
    // TODO: Change these strings to be c-style strings anyway?
    printf("%-28s | %-12s | %-22s | %-7.2lfAcres | %-14s | %-40s \n", fire.fireName.c_str(), fire.fireIdentifier.c_str(), fire.fireDateAndTime.c_str(), fire.fireSizeInAcres, fire.fireLandType.c_str(), fire.fireGeneralCause.c_str()); // Column titles
    return;
}

void PrintAllFireReports(FireReport fires[numReportsToPull])
{
    PrintDataColumnTitles();

    for (int i = 0; i < numReportsToPull; i++)
    {
        // Skip any fires with a blank ID
        if (fires[i].fireIdentifier == "")
            continue;

        // Output the report
        PrintFireReport(fires[i]);
    }
}

void PrintSingleFireFromPrompt(FireReport fires[numReportsToPull])
{
    FireReport singleFire;

    cout << "Which criterion would you like to select by?" << endl << "You can type 'Name', 'ID', or 'Back'." << endl;
    string inputCommand;
    getline(cin, inputCommand);
    inputCommand = StringToLowercase(inputCommand);

    // Do we need to back out of this operation?
    if (inputCommand == "back" || inputCommand == "cancel")
    {
        return;
    }
    // Find a fire by name.
    else if (inputCommand.find("name") != string::npos)
    {
        // Prompt for input.
        cout << endl << "What is the name of the fire incident?" << endl;
        // Take input.
        getline(cin, inputCommand);
        // Announce the output.
        cout << endl << "Searching for a fire with name " << "\"" << inputCommand << "\": " << endl;
        // Search for the relevant fire.
        for (int i = 0; i < numReportsToPull; i++)
        {
            if (StringToLowercase(inputCommand) == StringToLowercase(fires[i].fireName))
                singleFire = fires[i];
        }
    }
    else if ((inputCommand.find("id") != string::npos) || (inputCommand.find("number") != string::npos))
    {
        // Prompt for input.
        cout << endl << "What is the ID of the fire incident?" << endl;
        // Take input.
        getline(cin, inputCommand);
        // Search for the relevant fire.
        for (int i = 0; i < numReportsToPull; i++)
        {
            if (StringToLowercase(inputCommand) == StringToLowercase(fires[i].fireIdentifier))
                singleFire = fires[i];
        }
        // Announce the output.
        cout << endl << "Searching for a fire with ID " << "\"" << inputCommand << "\": " << endl;
    }

    PrintDataColumnTitles();
    PrintFireReport(singleFire);

    return;
}

void PrintFiresOnDate(FireReport fires[numReportsToPull])
{
    // Prompt for input.
    cout << endl << "Display fires from which date? (MM/DD/YYYY)" << endl;
    // Take input.
    string fireDate;
    getline(cin, fireDate);

    cout << endl << "Here are the fires from " << "\"" << fireDate << "\": " << endl;
    PrintDataColumnTitles();

    for (int i = 0; i < numReportsToPull; i++)
    {
        if (fires[i].fireDateAndTime.find(fireDate) != string::npos)
        {
            PrintFireReport(fires[i]);
        }
    }
}

void PrintFiresOfCause(FireReport fires[numReportsToPull])
{
    // Prompt for input.
    cout << endl << "Display fires caused by what? (Case sensitive)" << endl;
    // Take input.
    string fireCause;
    getline(cin, fireCause);

    cout << endl << "Here are the fires caused by " << "\"" << fireCause << "\": " << endl;
    PrintDataColumnTitles();

    for (int i = 0; i < numReportsToPull; i++)
    {
        if (fires[i].fireGeneralCause.find(fireCause) != string::npos)
        {
            PrintFireReport(fires[i]);
        }
    }
}

void PrintMinMaxByCause(FireReport fires[numReportsToPull])
{
    // Prompt for input.
    cout << endl << "Display the largest and smallest fires caused by what? (Case sensitive)" << endl;
    // Take input.
    string generalCause;
    getline(cin, generalCause);

    FireReport maxFire;
    FireReport minFire;

    double currentMax = 0;
    double currentMin = 999999;

    for (int i = 0; i < numReportsToPull; i++)
    {
        // Skip any records that don't match the specified cause.
        if (fires[i].fireGeneralCause.find(generalCause) == string::npos)
            continue;

        // Check if this fire is greater than the current maximum, while ignoring 0-size fires.
        if (fires[i].fireSizeInAcres > 0 && fires[i].fireSizeInAcres < currentMin)
        {
            minFire = fires[i];
            currentMin = minFire.fireSizeInAcres;
        }

        // Check if this fire is smaller than the current minimum.
        if (fires[i].fireSizeInAcres > currentMax)
        {
            maxFire = fires[i];
            currentMax = minFire.fireSizeInAcres;
        }
    }

    // Output the extrema.
    cout << endl << "Here are the largest and smallest fires caused by " << "\"" << generalCause << "\": " << endl;
    PrintDataColumnTitles();
    PrintFireReport(minFire);
    PrintFireReport(maxFire);

    return;
}


void PrintMinMaxByLand(FireReport fires[numReportsToPull])
{
    // Prompt for input.
    cout << endl << "Display the largest and smallest fires taking place on what type of land? (Case sensitive)" << endl;
    // Take input.
    string landType;
    getline(cin, landType);

    FireReport maxFire;
    FireReport minFire;

    double currentMax = 0;
    double currentMin = 999999;

    for (int i = 0; i < numReportsToPull; i++)
    {
        // Skip any records that don't match the specified type of land.
        if (fires[i].fireLandType.find(landType) == string::npos)
            continue;

        // Check if this fire is greater than the current maximum, while ignoring 0-size fires.
        if (fires[i].fireSizeInAcres > 0 && fires[i].fireSizeInAcres < currentMin)
        {
            minFire = fires[i];
            currentMin = minFire.fireSizeInAcres;
        }

        // Check if this fire is smaller than the current minimum.
        if (fires[i].fireSizeInAcres > currentMax)
        {
            maxFire = fires[i];
            currentMax = minFire.fireSizeInAcres;
        }
    }

    // Output the extrema.
    cout << endl << "Here are the largest and smallest fires which occurred on land type " << "\"" << landType << "\": " << endl;
    PrintDataColumnTitles();
    PrintFireReport(minFire);
    PrintFireReport(maxFire);

    return;
}

void PrintAverageFireAreaByCause(FireReport fires[numReportsToPull])
{
    // Prompt for input.
    cout << endl << "Display the average fire size by which cause? (Case sensitive)" << endl;
    // Take input.
    string fireCause;
    getline(cin, fireCause);

    int fireCount = 0;
    double totalSize = 0;

    for (int i = 0; i < numReportsToPull; i++)
    {
        // Check whether this fire matches the given criteria.
        if (fires[i].fireGeneralCause == fireCause)
        {
            fireCount++;
            totalSize += fires[i].fireSizeInAcres;
        }
    }

    double averageSize = ((fireCount == 0 || totalSize == 0) ? 0 : (double)(totalSize / fireCount));

    cout << "On average, fires caused by " << "\"" << fireCause << "\"" << " spread to a size of " << averageSize << " acres. " << endl;

    return;
}

void PrintAverageFireAreaByLand(FireReport fires[numReportsToPull])
{
    // Prompt for input.
    cout << endl << "Display the average fire size by which type of land? (Case sensitive)" << endl;
    // Take input.
    string landType;
    getline(cin, landType);

    int fireCount = 0;
    double totalSize = 0;

    for (int i = 0; i < numReportsToPull; i++)
    {
        // Check whether this fire matches the given criteria.
        if (fires[i].fireLandType == landType)
        {
            fireCount++;
            totalSize += fires[i].fireSizeInAcres;
        }
    }

    double averageSize = ((fireCount == 0 || totalSize == 0) ? 0 : (double)(totalSize / fireCount));

    cout << "On average, fires on " << "\"" << landType << "\"" << " land spread to a size of " << averageSize << " acres. " << endl;

    return;
}

bool DisplayReportsFromInterpretedCommand(FireReport (&fires)[numReportsToPull])
{
    cout << "Which type of reports would you like to view?" << endl << "You can type 'All', 'Single', 'Matching', 'Extrema', 'Aggregate', or 'Quit'." << endl;

    string inputCommand;
    getline(cin, inputCommand);
    inputCommand = StringToLowercase(inputCommand);

    // Add an extra space after the command
    cout << endl;

    // Commands to end the program
    if (inputCommand == "exit" || inputCommand == "quit" || inputCommand == "close")
        return false;

    // Commands to display the whole darn thing
    else if (inputCommand == "all" || inputCommand == "everything" || inputCommand == "*")
    {
        PrintAllFireReports(fires);
        return true;
    }

    // Commands to get a single fire instance by name/ID/etc
    else if (inputCommand == "single" || inputCommand == "specific" || inputCommand == "one")
    {
        PrintSingleFireFromPrompt(fires);
        return true;
    }

    // Commands to get a range of matching fires
    else if (inputCommand == "matching" || inputCommand == "range" || inputCommand == "some")
    {
        cout << "Which criterion would you like to select by?" << endl << "You can type 'Cause', 'Date', or 'Back'." << endl;

        getline(cin, inputCommand);
        inputCommand = StringToLowercase(inputCommand);

        // Do we need to back out of this operation?
        if (inputCommand == "back" || inputCommand == "cancel")
        {
            return true;
        }
        // Find a fire.
        else if (inputCommand.find("cause") != string::npos)
        {
            PrintFiresOfCause(fires);
        }
        else if (inputCommand.find("date") != string::npos)
        {
            PrintFiresOnDate(fires);
        }
    }




    // Commands to get a min/max fire
    else if (inputCommand == "min" || inputCommand == "max" || inputCommand == "extrema")
    {
        cout << "Which criterion would you like to select by?" << endl << "You can type 'Cause', 'Land', or 'Back'." << endl;

        getline(cin, inputCommand);
        inputCommand = StringToLowercase(inputCommand);

        // Do we need to back out of this operation?
        if (inputCommand == "back" || inputCommand == "cancel")
        {
            return true;
        }
        // Find a fire by some criteria.
        else if (inputCommand.find("cause") != string::npos)
        {
            PrintMinMaxByCause(fires);
        }
        else if ((inputCommand.find("land") != string::npos))
        {
            PrintMinMaxByLand(fires);
        }

        return true;
    }



    // Commands to get aggregate data
    else if (inputCommand == "aggregate" || inputCommand == "average")
    {
        cout << "Which criterion would you like to average by?" << endl << "You can type 'Cause', 'Land', or 'Back'." << endl;

        getline(cin, inputCommand);
        inputCommand = StringToLowercase(inputCommand);

        // Do we need to back out of this operation?
        if (inputCommand == "back" || inputCommand == "cancel")
        {
            return true;
        }
        // Find a fire by some criteria.
        else if (inputCommand.find("cause") != string::npos)
        {
            PrintAverageFireAreaByCause(fires);
        }
        else if (inputCommand.find("land") != string::npos)
        {
            PrintAverageFireAreaByLand(fires);
        }


        return true;
    }

    return true;
}
