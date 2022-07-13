/**
* @brief Assignment 6
* @name Kern Espinoza
*/

#ifndef CARDFUNCTIONS_H
#define CARDFUNCTIONS_H
#include <string>
using namespace std;

/**
 * @brief Turns a char into the number it represents (e.g., '3' -> 3).
 * @param digit The numerical character to convert to an integer.
 * @return Returns an integer corresponding to the provided number char.
 */
int charToInt(char digit);

/**
 * @brief Doubles the given integer. If the doubled value is two digits long, instead returns the sum of those digits.
 * @param number The number to double.
 * @return Returns the doubled number.
 */
int doubledDigitValue(int number);

/**
 * @brief Returns a string for which company issued this card: Visa, MasterCard, AmEx, or Unknown. This is determined by the first digit of the card number.
 * @param cardNumber The card number to check.
 * @return Returns the appropriate string, such as "Visa" or "Unknown".
 */
string getCardType(const string& cardNumber);

/**
 * @brief Sums the digits of the credit card number according to the Luhn algorithm.
 * @param cardNumber The card number to sum.
 * @return Returns the final Luhn sum as an integer.
 */
int luhnDigitSum(const string& cardNumber);

/**
 * @brief Returns true if the given credit card number is potentially valid according to the Luhn algorithm.
 * @param cardNumber The credit card number for check for validity.
 * @return True/False, depending on whether the Luhn algorithm checks out.
 */
bool isValid(const string& cardNumber);

#endif // CARDFUNCTIONS_H
