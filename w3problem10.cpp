#include <iostream>
#include <string>
using namespace std;

int main()
{
    string food = "Pizza";
    string meal = food;

    cout << "Food: " << &food << endl;
    cout << "Meal: " << &meal;
}