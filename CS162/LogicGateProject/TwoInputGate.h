/**
* @brief Assignment 8
* @name Kern Espinoza
*/#ifndef TWOINPUTGATE_H


#define TWOINPUTGATE_H

#include <memory>
#include "Component.h"

//Supported operations
enum LogicOperation {OR, AND, XOR};

//Lookup table for names of operations:
//  LOGIC_LABELS[OR] --> "OR"
//  LOGIC_LABELS[AND] --> "AND"...
const std::string LOGIC_LABELS[] = {"OR", "AND", "XOR"};


class TwoInputGate : public Component
{
private:
    Component* input1;
    Component* input2;
    LogicOperation gateType;
public:
    TwoInputGate(LogicOperation op);
    bool getOutput();
    void setInput1(Component* in1);
    void setInput2(Component* in2);
    void prettyPrint(string padding);
    void linearPrint();
};


#endif // TWOINPUTGATE_H
