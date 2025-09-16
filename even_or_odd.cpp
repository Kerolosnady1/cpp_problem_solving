// Input:
// 7
// Output:
// Odd

// Input:
// 10
// Output:
// Even

#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number % 2 == 0)
        cout << "Even" << endl;

    else if (number % 2 != 0)
        cout << "Odd" << endl;

    else
        cout << "Unkown error";

    return 0;
}