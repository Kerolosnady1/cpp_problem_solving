#include <iostream>
using namespace std;

int powerTwo(int arr[], int sizes)
{
    int result = 0;

    for (int i = 0; i < sizes; ++i)
    {
        result += arr[i] * arr[i];
    }
    cout << "The Summation Of The Array Power Two = " << result;
    return 0;
}

int main()
{
    // 25April25
    // Program:
    /*You have an array of int, calculate every number power 2, then sum all of it and return
    the result*/

    int arr[] = {1, 2, 3, 4, 5}, sizes = sizeof(arr) / sizeof(arr[0]);

    powerTwo(arr, sizes);
}