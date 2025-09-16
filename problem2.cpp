#include <iostream>
using namespace std;

int main()
{
    // 17April25
    // Program:
    // If the number is even, then multiply it with 8.
    // If the number is odd multiply it with 9.
    int takenNumber;

    cout << "Put Number Here: ";

    cin >> takenNumber;

    if (takenNumber == takenNumber % 2 == 0)
    {
        cout << "The Number Is Even: " << takenNumber * 8 << endl;
    }
    else
    {
        cout << "The Number Is Odd: " << takenNumber * 9;
    }
}