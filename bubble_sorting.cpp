#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int counter;
    cout << "Enter the counter number: ";
    cin >> counter; // 5, 8

    vector<int> numbers; // 5, 7, ... // int => 4 bytes

    for (int i = 0; i < counter; ++i)
    {
        int number;
        cout << "Enter the " << i + 1 << " number: ";
        cin >> number; // 5, 7, ...

        numbers.push_back(number);
    }
    if (sizeof(numbers) / sizeof(numbers[0]) == 0)
        cout << "The list is empty";
    else
    {
        // int len = counter; // 5 * 4 = 20 / 4 , 1 * 4
        // int len = sizeof(numbers) / sizeof(numbers[0]);

        // size of array => 8 => index[0:7]
        // 1 > 2, 2 > 3, 3 > 4, ...
        // 5, 7, 2, 8, 3, 4, 9, 1

        for (int i = 0; i < counter - 1; ++i) // i = 0, i = 1, ...

        // 8 - 0 - 1 = 7, 8 - 1 - 1 = 6, 8 - 2 - 1 = 5 , ...
        {
            for (int j = 0; j < counter - i - 1; ++j) // 7, 6, 5, 4, ..., 0
            {
                if (numbers[j] > numbers[j + 1]) // 5 > 7 , 7 > 2, 7 > 8, 8 > 3
                {
                    swap(numbers[j], numbers[j + 1]); // 5, 2, 7, 3, 8, ...
                }
            }
        }
        for (int i = 0; i < counter; ++i)
        {
            cout << numbers[i] << " ";
        }
    }

    return 0;
}