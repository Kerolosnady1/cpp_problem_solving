#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int counter;
    // std::cout << "Enter the counter number: ";
    cout << "Enter the counter number: ";
    cin >> counter;

    vector<int> numbers; // 5, 3, 5, 2, 1, 5, 8

    for(int i = 0; i < counter; i++)
    {
        int num; // 5, 3
        cout << "Enter the " << i + 1 << " number: ";
        cin >> num;

        numbers.push_back(num); // 5, 3
    }

    int f_num, index = 0;
    cout << "Enter the number you want to search for: ";
    cin >> f_num;

    for(int i = 0; i < counter; i++)
    {
        if(f_num == numbers[i])
        {
            index++; // index = index + 1;
        }
    }
    cout << "The number " << f_num << " found " << index << " times.";


    return 0;
}