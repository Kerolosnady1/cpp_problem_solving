#include <iostream>
using namespace std;

int evenOrOdd(int number)
{
    if (number % 2 == 0)
    {
        cout << "The Number Is Even.";
    }
    else
    {
        cout << "The Number Is Odd.";
    }
    return 0;
}

int main()
{
    // 17April25
    // Program:
    // Check If The Input Number Is Even Or Odd.

    int number;

    cout << "Enter The Number Here: ";
    cin >> number;

    evenOrOdd(number);
}