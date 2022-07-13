#include <iostream>

using namespace std;

int main()
{
    // Ask for the order cost:
    cout << "Enter the cost of an order: ";
    double orderCostInput;
    cin >> orderCostInput;

    // Ask for the shipping type:
    cout << "Enter the shipping method: \n" << "1 - Drone\n2 - 2-Day\n3 - Standard" << endl;
    int shippingMethodInt;
    cin >> shippingMethodInt;

    double shippingCharge;

    // Apply shipping method charges
    switch(shippingMethodInt) {
       case 1  : // Drone Delivery
          if (orderCostInput < 100)
          {
              cout << "Not available" << endl;
              return 0;
          } else if (orderCostInput < 500) {
              shippingCharge = 50;
          } else {
              shippingCharge = orderCostInput * 0.1;
          }
          break;
       case 2  : // 2-Day Delivery
        if (orderCostInput <= 300)
        {
            shippingCharge = 10 + (orderCostInput * 0.02);
        } else {
            shippingCharge = 0;
        }
          break;
       case 3  : // Standard Delivery
        if (orderCostInput < 35)
        {
            shippingCharge = 5;
        } else if (orderCostInput < 100) {
            shippingCharge = 8;
        } else {
            shippingCharge = 0;
        }
       break;

       default :
        {
            cout << "Bad Input" << endl;
            return 0;
        }

    }

    cout << "Total is $" << (orderCostInput + shippingCharge) << endl;

    return 0;
}
