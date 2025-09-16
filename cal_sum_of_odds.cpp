#include <iostream>
using namespace std;

int main()
{
    int number, odds;
    cout << "Enter a number: ";
    cin >> number;

    
    int total = 0;
    for (int i = 1; i <= number; ++i)
    {
        cout << "Enter the " << i << " number: ";
        cin >> odds;
        if (odds % 2 != 0)
            total += odds;
    }
    cout << "Sum of odds: " << total;

    return 0;
}