#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool compareStrings(const string &str1, const string &str2)
{
    return str1 == str2;
}

bool compareCStrings(const char *str1, const char *str2)
{
    return strcmp(str1, str2) == 0;
}

int main()
{
    string s1 = "Hello";
    string s2 = "World";
    string s3 = "Hello";

    cout << "================\n";
    cout << "C++ Strings:" << endl;
    cout << "===============================\n";

    if (compareStrings(s1, s2))
        cout << "s1 And s2 Are Equal." << endl;
    else
        cout << "s1 And s2 Are Not Equal." << endl;

    cout << "===============================\n";

    if (compareStrings(s1, s3))
        cout << "s1 And s3 Are Equal." << endl;
    else
        cout << "s1 And s3 Are Not Equal." << endl;

    cout << "===============================\n";

    const char *cs1 = "Hello";
    const char *cs2 = "World";
    const char *cs3 = "Hello";

    cout << "\n================\n";
    cout << "C-Strings:" << endl;
    cout << "===============================\n";

    if (compareCStrings(cs1, cs2))
        cout << "cs1 And cs2 Are Equal." << endl;
    else
        cout << "cs1 And cs2 Are Not Equal." << endl;

    cout << "===============================\n";

    if (compareCStrings(cs1, cs3))
        cout << "cs1 And cs3 Are Equal.";
    else
        cout << "cs1 And cs3 Are Not Equal.";

    cout << "\n===============================";

    return 0;
}
