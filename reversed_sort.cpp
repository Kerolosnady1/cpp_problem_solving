#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int counter;
    cout << "Enter the counter number: ";
    cin >> counter;

    vector<int> nums;

    for(int i = 0; i < counter; ++i)
    {
        int num;
        cout << "Enter the " << i + 1 << " number: ";
        cin >> num;

        nums.push_back(num);
    }

    for(int i = 0; i < counter - 1; ++i)
    {
        for(int j = 0; j < counter - i - 1; ++j)
        {
            if(nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    vector<int> nums_updated;

    for(int i = counter - 1; i >= 0; --i)
    {
        nums_updated.push_back(nums[i]);
    }

    for(int i = 0; i < counter; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < counter; ++i)
    {
        cout << nums_updated[i] << " ";
    }


    return 0;
}