#include <iostream>
#include <string>
using namespace std;

void counChar(string sentence, char input)
{
    int counter = 0;
    for (int i = 0; i < sentence.size(); ++i)
    {
        if (input == sentence[i])
        {
            counter++;
        }
    }
    cout << "The Number That The " << "'" << input << "'" << " Repeated Is " << counter;
}

int main()
{
    // 23April25
    // Program:
    /*You have a sentence and you will get input character from user and check how many times
    this character repeated.*/

    string sentence;
    char input;
    cout << "Put The Sentence Here: ";
    cin >> sentence;

    cout << "Put The Character Here: ";
    cin >> input;

    counChar(sentence, input);
}