/**
* @brief Assignment 8
* @name Kern Espinoza
*/

#include <iostream>

#include "TwoInputGate.h"

TwoInputGate::TwoInputGate(LogicOperation op)
{
    gateType = op;

    input1 = nullptr;
    input2 = nullptr;
}

bool TwoInputGate::getOutput() {
    switch (gateType)
    {
        case AND:
        {
            return (input1->getOutput() == input2->getOutput());
        }
        case OR:
        {
            return (input1->getOutput() || input2->getOutput());
        }
        case XOR:
        {
            return (input1->getOutput() != input2->getOutput());
        }
    }
}

void TwoInputGate::setInput1(Component *in1)
{ input1 = in1; }

void TwoInputGate::setInput2(Component *in2)
{ input2 = in2; }

void TwoInputGate::linearPrint()
{
    cout << "(";
    input1->linearPrint();

    switch(gateType)
    {
    case AND:
        {
            cout << " && ";
            break;
        }
    case OR:
        {
         cout << " || ";
         break;
        }
    case XOR:
        {
           cout << " ^ ";
           break;
        }
    }

    input2->linearPrint();
    cout << ")";
}

void TwoInputGate::prettyPrint(string padding)
{
    // Padding
    cout << padding;

    // Label
    switch(gateType)
    {
    case AND:
        {
            cout << "AND ";
            break;
        }
    case OR:
        {
         cout << "OR ";
         break;
        }
    case XOR:
        {
           cout << "XOR ";
           break;
        }
    }

    // Values
    cout << endl;
    input1->prettyPrint(padding + "--");
    cout << endl;
    input2->prettyPrint(padding + "--");
}
