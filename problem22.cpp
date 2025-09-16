#include <iostream>
#include <string>
using namespace std;

void checkUppOrLow(string str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            cout << "You Have A Lower Case Character Inside The Sentence.";
            break;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            continue;
        }
        else
        {
            cout << "Invalid Input.";
            break;
        }
    }
}

int main()
{
    // 24April25
    // Program:
    /*Input from user, check if there any lower case character inside the sentence or not.*/

    string str;

    cout << "Enter The Sentence Here: ";
    cin >> str;

    checkUppOrLow(str);
}