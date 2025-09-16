// Input:
// 5
// 3 7 2 9 5

// Output:
// 2 9

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count_number;
    cout << "Enter the number of numbers you will input: ";
    cin >> count_number;

    vector<int> list_of_numbers; // 3 , 8

    int number;
    for(int i = 0; i < count_number; ++i)
    {
        cout << "Enter the " << i + 1 << " number: ";
        cin >> number; // 3 , 8

        list_of_numbers.push_back(number); // 3 , 8
    }

    int max_number = list_of_numbers[0];
    int min_number = list_of_numbers[0];

    for(int i = 1; i < count_number; i++)
    {
        if(max_number < list_of_numbers[i]) // 3 < 8 => false, 8 < 5
        {
            max_number = list_of_numbers[i];
        }
        if(min_number > list_of_numbers[i])
        {
            min_number = list_of_numbers[i];
        }
    }

    cout << "Max: " << max_number << endl;
    cout << "Min: " << min_number;

    return 0;
}