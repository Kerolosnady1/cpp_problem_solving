#include <iostream>
using namespace std;

int main()
{
    // 19April25
    // Program:
    /*Multiply all sequence inside the array to each other.*/
    int arr[] = {10, 3, 7, 4, 1, 2};

    int mult = 1, size;

    size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i)
    {
        mult *= arr[i];
    }

    cout << "The Equal Of Multiple Calculation Is: " << mult;
}