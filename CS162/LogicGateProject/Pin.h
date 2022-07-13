/**
* @brief Assignment 8
* @name Kern Espinoza
*/

#ifndef PIN_H
#define PIN_H

#include "Component.h"

class Pin : public Component
{
private:
    bool value;
    string label;
public:
    Pin(string theLabel);
    bool getOutput();
    void setValue(bool newVal);
    void prettyPrint(string padding);
    void linearPrint();
};

#endif // PIN_H
