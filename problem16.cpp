#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 19April25
    // Program:
    /*You have a sentence and you need to remove the first and last character.*/

    string s = "Kerolos";

    string sUpdated;

    cout << "The Original Sentence Is: " << s << endl;

    s[0] = ' ';

    cout << "The First Character Already Removed: " << s << endl;

    s[6] = ' ';

    cout << "The Last Character Already Removed: " << s;

    // Another Solution:

    /*
    for( int i = 1; i < s.size() - 1;i++)
    {
        sUpdated += s[i];
    }
    */

    return 0;
}