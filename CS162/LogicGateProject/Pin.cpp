/**
* @brief Assignment 8
* @name Kern Espinoza
*/

#include <iostream>

#include "Pin.h"

Pin::Pin(string theLabel)
{
    label = theLabel;
    value = false;
}

bool Pin::getOutput() { return value; }

void Pin::setValue(bool newVal) { value = newVal; }

void Pin::linearPrint()
{
    cout << label;
}

void Pin::prettyPrint(string padding)
{
    // Padding -> Label -> Data
    cout << padding << label << " : " << (value ? 1 : 0);
}
