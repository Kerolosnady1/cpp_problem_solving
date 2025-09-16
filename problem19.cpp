#include <iostream>
using namespace std;

int main()
{
    // 24April25
    // Program:
    /*Create a program that calculate the hours, minutes, and seconds from input you get from
    the user*/

    long long oneSecond = 1000, oneMinute = 60 * oneSecond, oneHour = 60 * oneMinute, number;

    cout << "Put The Number Here: ";
    cin >> number;

    cout << "Number In Hours: " << number * oneHour << " ,"
         << " Minutes: " << number * oneMinute << " ," << " Seconds: " << number * oneSecond;
}