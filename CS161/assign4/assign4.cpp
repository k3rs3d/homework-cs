/**
* @brief Assignment 4
* @name Kern Espinoza
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Force output with fixed decimal, 2 decimal places
    cout << fixed << setprecision(2);

    // Get current balance:
    cout << "Enter balance: ";
    double cardBalanceInput;
    cin >> cardBalanceInput;

    // Get payment amount:
    cout << "Enter payment: ";
    double paymentAmountInput;
    cin >> paymentAmountInput;

    // Get APR:
    cout << "Enter APR: ";
    double APRInput;
    cin >> APRInput;

    double paymentThisMonth; // In its own variable in case the outstanding balance is less than the payment amount
    double remainingBalance = cardBalanceInput;
    double interestRate = APRInput * 0.0008333333333; // Technically less accurate than dividing by 12, but this way allows for APR of 0% and computes faster anyway
    double interestThisMonth = 0;

    // Column labels:
    cout << "Month\tInt.\tPay\tBalance" << endl;

    // I could use While for this, but instead,
    // I will stop the loop after 100 years just in case it doesn't break naturally (for whatever reason)
    for (int i = 0; i < 1200; i++)
    {
        // Check to see whether the balance has been paid off yet.
        if (remainingBalance <= 0)
            break;

        // Is this the zero month?
        if (i == 0)
        {
            // For the first month, pretty much just print the balance.
            cout << i << "\t\t" << cardBalanceInput << "\t" << endl;
        } else {
            // Non-zero months:
            // First, calculate and add interest.
            interestThisMonth = interestRate * remainingBalance;
            remainingBalance += interestThisMonth;
            // Determine this month's payment.
            paymentThisMonth = (remainingBalance > paymentAmountInput) ? paymentAmountInput : (paymentAmountInput - (paymentAmountInput - remainingBalance));
            // Apply the payment.
            remainingBalance = (abs(remainingBalance - paymentThisMonth) < 0.00001) ? 0 : (remainingBalance - paymentThisMonth);
            // Finally, output all the numbers.
            cout << i << "\t" << interestThisMonth << "\t" << paymentThisMonth << "\t" << remainingBalance << endl;
        }
    }
}
