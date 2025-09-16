#include <iostream>
#include <string>
using namespace std;

// 16April25
int main()
{
    string word = "Hello, World";
    string wordUpdated;

    for (int i = word.size() - 1; i < word.size(); i--)
    {
        wordUpdated += word[i];
    }
    cout << wordUpdated;
}