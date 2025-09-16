#include <iostream>
#include <string>
using namespace std;

void reversed(string word)
{
    string updatedWords;
    for (int i = word.size() - 1; i < word.size(); i--)
    {
        updatedWords += word[i];
    }
    cout << "The Reversed Sentence Is: " << updatedWords;
}

int main()
{
    // 17April25
    // Program:
    // Reverse The Input String.

    string words;

    cout << "Put The Sentence Here: ";
    cin >> words;

    reversed(words);
}