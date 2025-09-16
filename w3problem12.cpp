#include <iostream>
using namespace std;

void funct(string name = "Kerolos")
{
    cout << "Name: " << name;
}

int main()
{
    funct();
}