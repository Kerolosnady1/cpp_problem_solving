#include <iostream>
using namespace std;

float gasStation(int gallons, float miles, float gallonForEveryMiles)
{
    if ((gallons * gallonForEveryMiles) >= miles)
    {
        cout << "You Will Achieve It, Go Get It";
    }
    else
    {
        cout << "You Will Not Achieve It, Sorry:(";
    }
    return 0;
}

int main()
{
    // 24April25
    // Program:
    /*Input from user, number of miles the user want to achieve the gas station, the number of
    gallons of gas the user have, and the number of miles for every gallon.*/

    int gallons;
    float miles, gallonForEveryMiles;

    cout << "Enter The Number Of Gallons You Have: ";
    cin >> gallons;

    cout << "Enter The Number Of Miles You Want To Achieve The Gas Station: ";
    cin >> miles;

    cout << "Enter The Number Of Miles For Every Gallon: ";
    cin >> gallonForEveryMiles;

    gasStation(gallons, miles, gallonForEveryMiles);

    return 0;
}