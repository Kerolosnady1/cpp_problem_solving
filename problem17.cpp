#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 19April25
    // Program:
    /*Input integer and repeat the sentence the number user enter.*/
    string s;
    int number;

    cout << "Put The Sentence Here: ";
    cin >> s;

    cout << "Enter The NUmber Of Repeatition You Need: ";
    cin >> number;

    cout << "The Number Of Repeatition Is: " << number << endl;

    for (int i = 0; i < number; i++)
    {
        cout << s;
    }
}