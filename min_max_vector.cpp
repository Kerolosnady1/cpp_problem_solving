#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int number;
    cout << "Enter the number will you input numbers: ";
    cin >> number;

    int in_number;
    vector<int> list_of_numbers;
    for(int i = 0; i < number; ++i)
    {
        cout << "Enter the " << i + 1 << " number: ";
        cin >> in_number;
        list_of_numbers.push_back(in_number);
    }
    int max_number, min_number = list_of_numbers[0];
    for(int i = 0; i < size(list_of_numbers); ++i)
    {
        if(max_number < list_of_numbers[i])
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