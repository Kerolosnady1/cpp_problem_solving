#include <iostream>
#include <vector>

using namespace std;

bool Consecutive(vector<int> &nums)
{
    if (nums.empty())
        return false;

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] == nums[j])
                return false;
        }
    }

    int min_num = nums[0];
    int max_num = nums[0];
    for (int num : nums)
    {
        if (num < min_num)
            min_num = num;
        if (num > max_num)
            max_num = num;
    }

    return (max_num - min_num + 1) == nums.size();
}

int main()
{
    vector<int> test1 = {1, 2, 5, 7, 4, 3, 6};
    if (Consecutive(test1))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    vector<int> test2 = {1, 2, 5, 0, 3, 6, 7};
    if (Consecutive(test2))
        cout << "True";
    else
        cout << "False";

    return 0;
}