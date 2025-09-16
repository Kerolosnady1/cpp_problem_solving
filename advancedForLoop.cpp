#include <iostream>
using namespace std;

void calc(int numOne, int numeTwo, string opt)
{
    int sum, div, minu, mult;
    if (opt == "+")
    {
        sum = numOne + numTwo;
        cout << numOne << " + " << numTwo << " = " << sum;
    }
    else if (opt == "-")
    {
        minu = numOne - numeTwo;
        cout << numOne << " - " << numTwo << " = " << minu;
    }
    else if (opt == "*")
    {
        mult = numeOne * numeTwo;
        cout << numOne << " * " << numTwo << " = " << mult;
    }
    else if (opt == "/")
    {
        div = numOne / numTwo;
        cout << numOne << " / " << numTwo << " = " << div;
    }
    else
    {
        cout << "Invalid Operation!";
    }
}

int main()
{
    int numOne, numeTwo;
    string opt;
    cout << "Please, Enter The Operator From " + " " - " " * " " / ": " << endl;

    cin >> opt;

    cout << "Enter The First Number: ";

    cin >> numOne;

    cout << "Enter The Second Number: ";

    cin >> numTwo;

    calc(numOne, numTwo, opt);
}
