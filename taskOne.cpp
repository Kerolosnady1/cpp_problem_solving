#include <iostream>
using namespace std;

void swapints(int &j, int &k)
{
    int swapped = j;
    j = k;
    k = swapped;
}

void sort3(int &a, int &b, int &c)
{
    if (a > b)
        swapints(a, b);
    if (b > c)
        swapints(b, c);
    if (a > b)
        swapints(a, b);
}

int main()
{
    cout << "=======================================\n";

    int j = 23, k = 15;
    cout << "Before Swap: " << "J: " << j << " ," << "K: " << k << endl;

    cout << "=======================================\n";

    swapints(j, k);
    cout << "After Swap: " << "J: " << j << " ," << "K: " << k << endl;

    cout << "=======================================\n";

    int a = 4, b = 2, c = 3;
    cout << "Before Sorting: " << "A: " << a << " ," << "B: " << b << " ," << "C: " << c << endl;

    cout << "=======================================\n";

    sort3(a, b, c);
    cout << "After Sorting: " << "A: " << a << " ," << "B: " << b << " ," << "C: " << c;

    cout << "\n=======================================\n";

    return 0;
}