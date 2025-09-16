#include <iostream>
using namespace std;

int main()
{
    int counter;
    cout << "Enter the counter number: ";
    cin >> counter;

    int num_1;
    cout << "Enter the 1 number: ";
    cin >> num_1;

    int total = num_1, mx = num_1, mn = num_1;

    for(int i = 1; i < counter; ++i)
    {
        int numbers;
        cout << "Enter the " << i + 1 << " number: ";
        cin >> numbers;

        if(mx < numbers){mx = numbers;}

        if(mn > numbers){mn = numbers;}

        total += numbers; 
    }
    float avg = (float)total / counter; 

    cout << "Max: " << mx << ", " << "Min: " << mn << ", " << "Total: " << total << ", " << "Average: " << avg;



    return 0;
}