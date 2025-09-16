#include <iostream>
using namespace std;

int monthQuarter(int monthNumber)
{
    if (monthNumber == 1 || monthNumber == 2 || monthNumber == 3)
    {
        cout << "First Quarter.";
    }
    else if (monthNumber == 4 || monthNumber == 5 || monthNumber == 6)
    {
        cout << "Second Quarter.";
    }
    else if (monthNumber == 7 || monthNumber == 8 || monthNumber == 9)
    {
        cout << "Third Quarter.";
    }
    else if (monthNumber == 10 || monthNumber == 11 || monthNumber == 12)
    {
        cout << "Fourth Quarter.";
    }
    else
    {
        cout << "Invalid Month!";
    }
    return 0;
}

int main()
{
    // 17April25
    // Program:
    /* check if the input number of the monthes is at the first quarter or
     second or third or fourth. */

    int number;

    cout << "Enter The Number OF The Month: ";
    cin >> number;

    monthQuarter(number);
}