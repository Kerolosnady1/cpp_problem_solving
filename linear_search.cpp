#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int counter;
    cout << "Enter the counter number: ";
    cin >> counter; // 5, n
    // O(n) => O(1), O(2), O(3), ...
    vector<int> numbers; // 5, 2, 9, 7, 1

    for(int i = 0; i < counter; i++) // [0:4], [0:n]
    {
        int num;
        cout << "Enter the " << i + 1 << " number: ";
        cin >> num;

        numbers.push_back(num);
    }
    int linear_search;
    cout << "Enter the number you want to search for: ";
    cin >> linear_search; // 9

    for(int i = 0; i < counter; i++) // i = 0, i = 1, i = 2
    {
        if(numbers[i] == linear_search) // 5 == 9 , 2 == 9 , 9 == 9 => True
        {
            int index = i; // 2
            cout << "Your number index is " << index; // 2
            break;
        }
    }



    return 0;
}