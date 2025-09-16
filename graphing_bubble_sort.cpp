#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers = {10, 2, 5, 8, 1}; // 5 => indexing = [0:4]
    // 10 > 2 = 2, 10
    // 10 > 5 = 2, 5, 10
    // 10 > 8 = 2, 5, 8, 10
    // 10 > 1 = 2, 5, 8, 1, 10

    // 2 > 5 = 2, 5
    // 5 > 8 = 2, 5, 8
    // 8 > 1 = 2, 5, 1, 8
    // 8 > 10 = 2, 5, 1, 8, 10

    // 2 > 5 = 2, 5
    // 5 > 1 = 2, 1, 5
    // 5 > 8 = 2, 1, 5, 8
    // 8 > 10 = 2, 1, 5, 8, 10

    // 2 > 1 = 1, 2
    // 2 > 5 = 1, 2, 5
    // 5 > 8 = 1, 2, 5, 8
    // 8 > 10 = 1, 2, 5, 8, 10

    int len = numbers.size();
    // int len = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < len - 1; i++) // 5 - 1 = 4, 0 < 4, 1 < 4, 2 < 4, 3 < 4;
    {
        for(int j = 0; j < len - i - 1; j++) // 5 - 0 - 1 = 4, 5 - 1 - 1 = 3, 
        {
            if(numbers[j] > numbers[j + 1])
            {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }

    return 0;
}