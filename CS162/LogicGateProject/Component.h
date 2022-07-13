/**
* @brief Assignment 8
* @name Kern Espinoza
*/

#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

using namespace std;

class Component
{
public:
    virtual bool getOutput() =0;
    virtual void prettyPrint(string padding) =0;
    virtual void linearPrint() =0;
};

#endif // COMPONENT_H
