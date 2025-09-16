#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fullname;

    cout << "Enter the full name: ";

    getline(cin, fullname); // Kerolos Nady

    cout << "The name is: " << fullname; // Kerolos Nady

    /*
    string fullname;
    cout << "Enter the full name: ";

    cin >> fullname; // Kerolos Nady

    cout << "The name is: " << fullname; //output => Kerolos
    */

    return 0;
}