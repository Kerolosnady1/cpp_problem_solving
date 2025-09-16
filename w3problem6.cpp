#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    vector<string> names = {"Kerolos", "Yousef", "Philopateer"};

    for (int i = 0; i < names.size(); ++i)
    {
        cout << "Name: " << names[i] << endl;
    }
    return 0;
}