/**
* @brief Assignment 8
* @name Kern Espinoza
*/

#ifndef NOTGATE_H
#define NOTGATE_H

#include <memory>
#include "Component.h"

class NotGate : public Component
{
private:
    Component* input;
public:
    NotGate();
    bool getOutput();
    void setInput(Component* in);
    void prettyPrint(string padding);
    void linearPrint();
};

#endif // NOTGATE_H
