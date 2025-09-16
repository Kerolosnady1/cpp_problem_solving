#include <iostream>
using namespace std;

void calc(float num1, float num2, char op)
{
    if (op == '+')
    {
        cout << num1 << " + " << num2 << " = " << num1 + num2;
    }
    else if (op == '-')
    {
        cout << num1 << " - " << num2 << " = " << num1 - num2;
    }
    else if (op == '/')
    {
        cout << num1 << " / " << num2 << " = " << num1 / num2;
    }
    else if (op == '*')
    {
        cout << num1 << " * " << num2 << " = " << num1 * num2;
    }
    else
    {
        cout << "Invalid Operator.";
    }
}
int main()
{
    // 24April25
    // Program:
    /*Input from user, number one, two, and the operator then calculate them.*/
    float num1, num2;
    char op;

    cout << "Enter Number One: ";
    cin >> num1;

    cout << "Enter Number Two: ";
    cin >> num2;

    cout << "Enter The Operator ''+ , - , / , *'': ";
    cin >> op;

    calc(num1, num2, op);
}