#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 19April25
    // Program:
    /* You Have Sentence and Inside The Sentence There Are Exclamation Mark (!),
    and You Have to Remove It.*/

    string sentence = "Hello !!, World!";
    string sentenceUpdated;

    for (int i = 0; i < sentence.size(); ++i)
    {
        if (sentence[i] != '!')
        {
            sentenceUpdated += sentence[i];
        }
        /*else
        {
            sentence[i] = ' ';
        }*/
    }
    cout << "After Delete: " << sentenceUpdated;
}