#include <iostream>
using namespace std;


int main()
{
    int counter;
    cout << "Enter the counter number: ";
    cin >> counter;

    int numbers, sum = 0, mx = 0;

    for(int i = 0; i < counter; ++i)
    {
        cout << "Enter the " << i + 1 << " number: ";
        cin >> numbers;

        sum += numbers;

        if(mx == 0){mx = numbers;}

        if(mx < numbers){mx = numbers;}
    }

    cout << "Total number = " << sum << ", " << "Maximum number = " << mx;



    return 0;
}