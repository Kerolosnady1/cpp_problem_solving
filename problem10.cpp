#include <iostream>
using namespace std;

int main()
{
    // 17April25
    // Program:
    // Transfer Any Negative Number To Positive.

    int number, invented;

    cout << "Enter The NUmber Here: ";
    cin >> number;

    if (number < 0)
    {
        invented = number * -1;
        cout << "The Number In Positive: " << invented;
    }
    else
    {
        cout << "The Number Already Positive!";
    }
}