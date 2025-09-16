#include <iostream>
#include <string>
using namespace std;

int main()
{
    string food = "Pizza";
    string *ptr = &food;

    cout << "Food: " << food << endl;
    cout << "Memory: " << &food << endl;
    cout << "Food with ptr: " << *ptr << endl;
    cout << "Memory with ptr: " << ptr << endl;

    cout << "====================\n";

    *ptr = "Tomato";

    cout << "Food: " << food << endl;
    cout << "Memory: " << &food << endl;
    cout << "Food: " << *ptr << endl;
    cout << "Memory: " << ptr;
}