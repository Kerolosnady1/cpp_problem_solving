#include <iostream>
using namespace std;

int main()
{
    // 17April25
    // Program:
    // If I have number, then calculate the century numbers.

    int takenNumber = 0;

    cout << "Put The Number Here: ";
    cin >> takenNumber;

    if (takenNumber % 100 == 0)
    {
        cout << "You Are In The Century: " << takenNumber / 100;
    }
    else
    {
        cout << "You Are In The Century: " << takenNumber / 100 + 1;
    }
}