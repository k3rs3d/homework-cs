/**
* @brief Assignment 6
* @name Kern Espinoza
*/

using namespace std;

#include "cardFunctions.h"

int charToInt(char digit)
{
    // ASCII numbers: 48 is 0, 57 is 9
    if (digit > 57 || digit < 48)
        return 0;

    // 48=0; cast the difference
    return (int)(digit - 48);
}

int doubledDigitValue(int number)
{
    // Double
    number *= 2;

    // Single-digit results are returned as-is
    if (number < 10)
        return number;

    // At this point, the result must be double-digit
    // so now it's time to sum those digits
    int sum = 0;
    while (number != 0)
    {
        sum += (number % 10);
        number /= 10;
    }

    return sum;
}

string getCardType(const string& cardNumber)
{
    // Possible return values
    const string cardIssuerVisa = "Visa";
    const string cardIssuerMasterCard = "MasterCard";
    const string cardIssuerAmEx = "American Express";
    const string cardIssuerUnknown = "unknown issuer";

    // Not a valid number
    if (cardNumber.length() < 2)
        return cardIssuerUnknown;

    // Look at the first digit
    switch (charToInt(cardNumber[0]))
    {
        case 3: // 34 or 37: American Express
            if (((charToInt(cardNumber[1]) == 4) || (charToInt(cardNumber[1]) == 7)))
                return cardIssuerAmEx;
        break;

        case 4: // 4: Visa
            return cardIssuerVisa;
        break;

        case 5: // 5: MasterCard
            return cardIssuerMasterCard;
        break;
    }

    return cardIssuerUnknown;
}

int luhnDigitSum(const string& cardNumber)
{
    int sum = 0;

    // Start at the end of the number and work from right to left:
    for (int i = (cardNumber.length() - 1); i >= 0; i--)
    {
        // If this is an even-numbered digit (second, fourth, etc):
        if (((i+1) % 2) == 0)
        {
            sum += doubledDigitValue(charToInt(cardNumber[i]));
        } else { // Odd-numbered digit:
            sum += charToInt(cardNumber[i]);
        }
    }

    return sum;
}

bool isValid(const string& cardNumber)
{
    // A card number is potentially valid if its luhn sum is divisible by 10
    return ((luhnDigitSum(cardNumber) % 10) == 0);
}
