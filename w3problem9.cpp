#include <iostream>
using namespace std;

enum level
{
    low = 1,
    high,
    hard
};

int main()
{
    level lev = high;
    cout << lev;
    return 0;
}