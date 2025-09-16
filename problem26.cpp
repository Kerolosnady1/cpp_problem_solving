#include <iostream>
using namespace std;

int oddCalc(int arr[], int size, int number)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (number % 2 == 0)
        {
            cout << "The Number Is Even not odd!" << endl;
            break;
        }
        else if (number % 2 != 0)
        {
            if (number > arr[i])
            {
                count++;
            }
        }
    }
    cout << "Counter: " << count;
    return 0;
}

int main()
{
    // 25April25
    // Program:
    /*You have an array of ints, you will recieve number from user odd, count how many
    numbers inside the array before the number.*/

    int number, arr[] = {1, 3, 5, 7, 9, 11, 13, 17, 19, 21}, size = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter Odd Number: ";
    cin >> number;

    oddCalc(arr, size, number);
}