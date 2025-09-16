// -3 0 7 -1 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int counter;
    cout << "Enter the counter number: ";
    cin >> counter;

    vector<int> list_of_numbers;

    int counted_number;
    for(int i = 0; i < counter; ++i)
    {
        cout << "Enter the " << i + 1 << " number: ";
        cin >> counted_number;

        list_of_numbers.push_back(counted_number);
    }

    int neg_numbers = 0, pos_numbers = 0, zeros = 0;
    for(int i = 0; i < counter;++i) // 5 1 2 3 -4 0 2 -3 0 0
    {
        if(list_of_numbers[i] < 0)
            neg_numbers++;

        if(list_of_numbers[i] > 0)
            pos_numbers++;

        if(list_of_numbers[i] == 0)
            zeros++;
    }

    cout << "Negative numbers = " << neg_numbers << ", " << "Positive numbers = " << pos_numbers << ", " << "Number of zeros = " << zeros;


    return 0;
}