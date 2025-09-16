#include <iostream>
using namespace std;

int division(int x, int y, int n)
{
    if (n % x == 0 && n % y == 0)
    {
        cout << "N Can Divided By X AND Y";
    }
    else
    {
        cout << "N Cann't Be Divided By X AND Y";
    }
    return 0;
}

int main()
{
    // 17April25
    // Program:
    // If a number n is divided by x AND y, remainder = 0.
    // Return N Can Divided By X AND Y.
    // else Return Anything Else

    int n, x, y;

    cout << "Enter N, X, and Y For Calculating Process: ";
    cin >> x >> y >> n;

    division(x, y, n);
}