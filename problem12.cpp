#include <iostream>
using namespace std;

int main()
{
    // 19April25
    // Program:
    /*You Have Sequence Of Numbers You Have To Return The Minium Number and The Maximum,*/

    int number[]{10, 15, 80, 2, 60, 700};
    int max, min, size;
    size = sizeof(number) / sizeof(number[0]);

    for (int i = 0; i < size; ++i)
    {
        if (number[i] > max)
        {
            max = number[i];
        }
        else if (number[i] < min)
        {
            min = number[i];
        }
    }
    cout << "Maximum Number In The Array Is: " << max << endl;
    cout << "The Minimum Number Is: " << min;
}