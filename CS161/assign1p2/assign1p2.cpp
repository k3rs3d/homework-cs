#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Ask for the velocity in m/s:
    cout << "Enter the velocity in m/s: ";
    double velocityInput;
    cin >> velocityInput;

    cout << "Enter the value for g in m/s^2: ";
    double gInput;
    cin >> gInput;

    double maxHeight;

    // Calculate the throw height:
    maxHeight = 0.5 * (pow(velocityInput,2) / gInput);

    // Display the final output:
    cout << "It will reach " << maxHeight << " meters" << endl;

    return 0;
}
