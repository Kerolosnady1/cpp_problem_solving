#include <iostream>
using namespace std;

int main()
{
    int counter, num_1, numbers, count_pos = 0, count_neg = 0, count_zero = 0;
    cout << "Enter the counter number: ";
    cin >> counter;

    cout << "Enter the 1 number: ";
    cin >> num_1;

    int total = num_1, mn = num_1, mx = num_1, pos_nums = num_1, neg_nums = num_1, zeros = num_1;

    if(pos_nums > 0) {count_pos++;}

    if(neg_nums < 0) {count_neg++;}

    if(zeros == 0) {count_zero++;}

    for(int i = 1;i < counter; ++i)
    {
        cout << "Enter the " << i + 1 << " number: ";
        cin >> numbers;

        pos_nums = numbers, neg_nums = numbers, zeros = numbers;

        if(mx < numbers) {mx = numbers;}

        if(mn > numbers) {mn = numbers;}

        if(pos_nums > 0) {count_pos++;}

        if(neg_nums < 0) {count_neg++;}

        if(zeros == 0) {count_zero++;}

        total += numbers;
    }
    // float avg = (float) total / counter;
    cout << "Max: " << mx << ", " << "Min: " << mn << ", " << "Positive numbers: " 
    << count_pos << ", " << "Negative numbers: " << count_neg << ", " << "Number of Zeros: " 
    << count_zero << ", " << "Average: " << total / counter << ", " << "Total: " << total;

    return 0;
}