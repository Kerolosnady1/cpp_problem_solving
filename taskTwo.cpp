#include <iostream>
using namespace std;

int *sortArray(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int swapped = arr[i];
                arr[i] = arr[j];
                arr[j] = swapped;
            }
        }
    }
    return arr;
}

int main()
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int sizes = sizeof(arr) / sizeof(arr[0]);

    cout << "\n=======================================================\n";

    cout << "Array Before Sorting: ";
    for (int i = 0; i < sizes; ++i)
    {
        cout << " ," << arr[i];
    }

    cout << "\n=======================================================";

    sortArray(arr, sizes);

    cout << "\nArray After Sorting: ";
    for (int i = 0; i < sizes; ++i)
    {
        cout << " ," << arr[i];
    }
    cout << "\n=======================================================\n";

    return 0;
}
