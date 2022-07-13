/**
* @brief Assignment 8
* @name Kern Espinoza
*/

#include <iostream>

#include "NotGate.h"

NotGate::NotGate()
{
    input = nullptr;
}

bool NotGate::getOutput() { return (input != nullptr ? !(input->getOutput()) : false); }

void NotGate::setInput(Component *in)
{
    input = in;
}

void NotGate::linearPrint()
{
    cout << "~(";

    input->linearPrint();

    cout << ")";
}

void NotGate::prettyPrint(string padding)
{
    cout << padding << "NOT" << endl;
    input->prettyPrint(padding + "--");
}
