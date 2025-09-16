#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int numItems;
    double *prices = nullptr;

    cout << "Enter the number of menu items: ";
    cin >> numItems;

    while (numItems <= 0)
    {
        cout << "Please enter a positive number: ";
        cin >> numItems;
    }

    prices = new double[numItems];

    for (int i = 0; i < numItems; i++)
    {
        cout << "Enter the price of item " << (i + 1) << ": ";
        cin >> prices[i];

        while (prices[i] <= 0)
        {
            cout << "Price must be positive. Enter again: ";
            cin >> prices[i];
        }
    }

    cout << "Menu Prices: ";
    for (int i = 0; i < numItems; i++)
    {
        cout << fixed << setprecision(2);
        cout << prices[i];
        if (i < numItems - 1)
            cout << " ";
    }
    cout << endl;

    delete[] prices;
    prices = nullptr;

    return 0;
}