/**
* @brief Assignment 3
* @name Kern Espinoza
*/

#include <iostream>
#include <cmath>

#define PI 3.141592653589

using namespace std;

int main()
{
    // Get triangle data:
    cout << "Enter side a: ";
    double sideLength_a;
    cin >>  sideLength_a;

    cout << "Enter side b: ";
    double sideLength_b;
    cin >>  sideLength_b;

    cout << "Enter angle A: ";
    double angleMeasure_A;
    cin >>  angleMeasure_A;

    // Make sure angle A is valid.
    if (angleMeasure_A >= 180 || angleMeasure_A <= 0)
    {
        cout << angleMeasure_A << " is not a valid angle measure." << endl;
        return 0;
    }

    // Degree/Radian conversion.
    double angleMeasure_A_Radians = angleMeasure_A * (PI/180);
    double bTimesSinA = (sideLength_b * sin(angleMeasure_A_Radians));
    // Get angle measure B.
    double angleMeasure_B_Radians = asin((bTimesSinA) / sideLength_a);
    double angleMeasure_B = angleMeasure_B_Radians * (180/PI);
    // Get angle measure C.
    double angleMeasure_C = (180 - (angleMeasure_A + angleMeasure_B));

    // Determine number of possible triangles.
    int numPossibleTriangles;
    // If A is acute, there are two cases to consider:
    if ((angleMeasure_A < 90))
    { // If A is acute and a>=b, there is exactly one triangle:
        if (sideLength_a >= sideLength_b)
        {
            numPossibleTriangles = 1;
        } else { // If a<b, there are three cases:
            if (sideLength_a < bTimesSinA) //
                numPossibleTriangles = 0; // First possibility: No solution
            else if (abs(bTimesSinA - sideLength_a) < 0.0001)
                numPossibleTriangles = 1; // Second possibility: One triangle
            else
                numPossibleTriangles = 2; // Third possibility: Two triangles
        }
    } else { // If A is non-acute and a>b, then one triangle exists:
            numPossibleTriangles = (int)(sideLength_a > sideLength_b);
    }

    // Output based on number of solutions
    switch(numPossibleTriangles) {
        default:
            cout << "No solution" << endl;
            break;
        case 1 :
            cout << "Angle B = " << round(angleMeasure_B) << " degrees" << endl << "Angle C = " << round(angleMeasure_C) << " degrees" << endl;
            break;
        case 2 :
            double angleMeasure_B_alternate = (180 - angleMeasure_B);
            double angleMeasure_C_alternate = (180 - (angleMeasure_A + angleMeasure_B_alternate));
            cout << "Angle B = " << round(angleMeasure_B) << " degrees" << endl << "Angle C = " << round(angleMeasure_C) << " degrees" << endl;
            cout << "OR" << endl << "Angle B = " << round(angleMeasure_B_alternate) << " degrees" << endl << "Angle C = " << round(angleMeasure_C_alternate) << " degrees" << endl;
            break;
    }

    return 0;
}
