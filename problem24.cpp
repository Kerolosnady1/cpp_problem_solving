#include <iostream>
using namespace std;

int numOfSheeps(int sheeps[], int sizes)
{
    int count;
    for (int i = 0; i < sizes; ++i)
    {
        if (sheeps[i] == 1)
        {
            count++;
        }
    }
    cout << "Number Of Sheeps = " << count;
    return 0;
}

int main()
{
    // 25April25
    // Program:
    /*You hav array of ints 1 sheep attend, and 0 for sheep absent. Then calculate how many
    sheep attend.*/

    int sheeps[] = {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1};
    int sizes = sizeof(sheeps) / sizeof(sheeps[0]);

    numOfSheeps(sheeps, sizes);
}