/**
* @brief Assignment 6
* @name Kern Espinoza
*/

#include <iostream>
#include "cardFunctions.h"

using namespace std;

void FunctionTests()
{
    cout << "Testing credit card functions: " << endl << endl;

    // Test charToInt:
    char testCharZero = '0';
    cout << "Char: " << testCharZero << " | Int: " << charToInt(testCharZero) << endl;
    char testCharTwo = '2';
    cout << "Char: " << testCharTwo << " | Int: " << charToInt(testCharTwo) << endl;
    char testCharNine = '9';
    cout << "Char: " << testCharNine << " | Int: " << charToInt(testCharNine) << endl;

    // Test doubler:
    int doubleIntThree = 3;
    cout << "Int: " << doubleIntThree << " | Doubled: " << doubledDigitValue(doubleIntThree) << endl;
    int doubleIntFive = 5;
    cout << "Int: " << doubleIntFive << " | Doubled: " << doubledDigitValue(doubleIntFive) << endl;
    int doubleIntEight = 8;
    cout << "Int: " << doubleIntEight << " | Doubled: " << doubledDigitValue(doubleIntEight) << endl;

    // Test card issuer function:
    string testCardOne = "34112998471";
    cout << "Card: " << testCardOne << " | Issuer: " << getCardType(testCardOne) << endl;
    string testCardTwo = "49781283145";
    cout << "Card: " << testCardTwo << " | Issuer: " << getCardType(testCardTwo) << endl;
    string testCardThree = "512971239812";
    cout << "Card: " << testCardThree << " | Issuer: " << getCardType(testCardThree) << endl;

    // Test Luhn sum function:
    cout << "Luhn sum of " << testCardOne << " is: " << luhnDigitSum(testCardOne) << endl;
    cout << "Luhn sum of " << testCardTwo << " is: " << luhnDigitSum(testCardTwo) << endl;
    cout << "Luhn sum of " << testCardThree << " is: " << luhnDigitSum(testCardThree) << endl;

    // Test validity checker:
    cout << testCardOne << " is " << (isValid(testCardOne) ? "Valid" : "NOT Valid") << endl;
    cout << testCardTwo << " is " << (isValid(testCardTwo) ? "Valid" : "NOT Valid") << endl;
    cout << testCardThree << " is " << (isValid(testCardThree) ? "Valid" : "NOT Valid") << endl;
}

int main()
{
    // !!! Uncomment the following line to run/output the function tests !!!
    //FunctionTests();

    // Get the card number
    string cardNumber = "";
    cout << "Enter credit card number: ";
    cin >> cardNumber;

    // Output the result
    cout << endl << (isValid(cardNumber) ? "Valid number" : "Not Valid") << ", " << getCardType(cardNumber) << endl;

    return 0;
}
