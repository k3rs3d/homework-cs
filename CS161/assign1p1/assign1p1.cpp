#include <iostream>

using namespace std;

int main()
{
    // Ask for the number of inches to measure:
    cout << "Enter the number of inches: ";
    double inchesInput;
    cin >> inchesInput;

    int remainingInches = static_cast<int>(inchesInput);

    // Find the number of miles:
    int numberOfMiles = remainingInches / 63360;
    remainingInches = remainingInches % 63360;

    // Find the number of yards:
    int numberOfYards = remainingInches / 36;
    remainingInches = remainingInches % 36;

    // Find the number of feet:
    int numberOfFeet = remainingInches / 12;
    remainingInches = remainingInches % 12;

    // Find the number of inches:
    int numberOfInches = remainingInches;

    // Display the final output:
    cout << numberOfMiles << " miles." << endl <<
    numberOfYards << " yards." << endl <<
    numberOfFeet << " feet." << endl <<
    numberOfInches << " inches.";

    return 0;
}
