#include <iostream>
using namespace std;

int main()
{
    int nums[2][3][4] = {{{1, 1}, {2, 2, 2}}, {{3, 3}, {4, 4, 4, 4}}};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                cout << "Numbers: " << nums[i][j][k] << endl;
            }
        }
    }
}