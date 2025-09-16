#include <iostream>
#include <string>
using namespace std;

struct
{
    int num;
    string user;
} myStruct, myStruct2, myStruct3;

/*
    struct{
    int nums;
    string user;
    }myStruct, myStruct2, myStruct3;
*/

int main()
{
    myStruct.num = 5;
    myStruct.user = "Kerolos";

    cout << " " << myStruct.num << " " << myStruct.user << endl;

    myStruct2.num = 10;
    myStruct2.user = "Nady";
    cout << " " << myStruct2.num << " " << myStruct2.user << endl;

    return 0;
}