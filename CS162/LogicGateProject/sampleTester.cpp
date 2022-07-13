//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;


//Include your .h files

TEST_CASE( "SAMPLE/test post-increment" ) {

    int x = 1;

    //Check that x is 1. CHECK means keep running this TEST_CASE even if failed.
    CHECK( x == 1 );

    x++;

    //Check that x is 2. REQUIRE means stop running this TEST_CASE if failed.
    REQUIRE( x == 2 );
}