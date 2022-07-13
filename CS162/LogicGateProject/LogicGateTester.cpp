/**
* @brief Assignment 8
* @name Kern Espinoza
*/

//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//Include your .h files
#include "Pin.h"
#include "NotGate.h"
#include "TwoInputGate.h"

#include <iostream>
#include <vector>

using namespace std;


TEST_CASE( "Components/Pin" ) {
    cout << "Pin Only Test..." << endl;    

    Pin a("A");
    a.setValue(false);

    REQUIRE(a.getOutput() == false);

    a.setValue(true);
    REQUIRE(a.getOutput() == true);
}



TEST_CASE( "Components/NotGate" ) {
    cout << "NOT Gate Test..." << endl;

    NotGate g;

    Pin a("A");
    g.setInput(&a);

    a.setValue(true);
    REQUIRE(g.getOutput() == false);

    a.setValue(false);
    REQUIRE(g.getOutput() == true);
}



TEST_CASE( "Components/TwoInputGate/OR") {
    cout << "OR Gate Test..." << endl;

    TwoInputGate gOR(OR);

    Pin a("A");
    Pin b("B");

    gOR.setInput1(&a);
    gOR.setInput2(&b);

    a.setValue(false);
    b.setValue(false);
    REQUIRE(gOR.getOutput() == false);

    a.setValue(true);
    REQUIRE(gOR.getOutput() == true);

    a.setValue(false);
    b.setValue(true);
    REQUIRE(gOR.getOutput() == true);
}

TEST_CASE( "Components/TwoInputGate/AND")
{
    cout << "AND Gate Test..." << endl;

    TwoInputGate gAND(AND);

    Pin a("A");
    Pin b("B");

    gAND.setInput1(&a);
    gAND.setInput2(&b);

    a.setValue(true);
    b.setValue(true);
    REQUIRE(gAND.getOutput() == true);

    a.setValue(false);
    REQUIRE(gAND.getOutput() == false);

    b.setValue(false);
    REQUIRE(gAND.getOutput() == true);

    a.setValue(true);
    REQUIRE(gAND.getOutput() == false);
}



TEST_CASE( "Components/TwoInputGate/XOR" )
{
    cout << "XOR Gate Test..." << endl;

    TwoInputGate gXOR(XOR);

    Pin a("A");
    Pin b("B");

    gXOR.setInput1(&a);
    gXOR.setInput2(&b);

    a.setValue(true);
    b.setValue(true);
    REQUIRE(gXOR.getOutput() == false);

    a.setValue(false);
    REQUIRE(gXOR.getOutput() == true);

    b.setValue(false);
    REQUIRE(gXOR.getOutput() == false);

    a.setValue(true);
    REQUIRE(gXOR.getOutput() == true);
}



TEST_CASE( "Circuit" )
{
    cout << "Circuit Test..." << endl;

    // Components
    Pin a("A");
    Pin b("B");
    Pin c("C");

    NotGate ng;
    TwoInputGate gAND(AND);
    TwoInputGate gXOR(XOR);

    // Connections
    ng.setInput(&c);

    gXOR.setInput1(&a);
    gXOR.setInput2(&b);

    gAND.setInput1(&gXOR);
    gAND.setInput2(&ng);

    // Values
    a.setValue(false);
    b.setValue(false);
    c.setValue(false);

    REQUIRE(gAND.getOutput() == false);

    b.setValue(true);

    REQUIRE(gAND.getOutput() == true);

    c.setValue(true);

    REQUIRE(gAND.getOutput() == false);
}



TEST_CASE( "Print Functions" )
{
    // Circuit Components:
    Pin a("A");
    Pin b("B");
    Pin c("C");

    NotGate ng;
    TwoInputGate gOR(OR);
    TwoInputGate gXOR(XOR);
    TwoInputGate gAND(AND);

    // Connections:
    ng.setInput(&c);
    gXOR.setInput1(&a);
    gXOR.setInput2(&b);
    gOR.setInput1(&b);
    gOR.setInput2(&ng);
    gAND.setInput1(&gXOR);
    gAND.setInput2(&gOR);

    // Values:
    a.setValue(true);
    b.setValue(true);
    c.setValue(false);

    cout << endl << "Testing Linear Print Function: " << endl;
    gAND.linearPrint();

    cout << endl << endl << "Testing Pretty Print Function: " << endl;
    gAND.prettyPrint("");

    cout << endl << endl;
}
