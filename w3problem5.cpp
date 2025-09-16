#include <iostream>
using namespace std;

int main()
{
    int num[] = {10, 20, 30, 40};

    for (int i : num)
    {
        cout << "The Number: " << i << endl;
    }
}