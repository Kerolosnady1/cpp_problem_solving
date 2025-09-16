#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 24April25
    // Program:
    /*Input from user, you have to reverse the upper character to lower and vise versa.*/

    string str;
    cout << "Enter The Sentence: ";
    cin >> str;

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] > 64 && str[i] < 91)
        {
            str[i] = str[i] + 32;
        }
        else if (str[i] > 95 && str[i] < 123)
        {
            str[i] = str[i] - 32;
        }
        else
        {
            cout << "Invalid Character:(" << endl;
        }
    }
    cout << "The Alternating Case: " << str;
}