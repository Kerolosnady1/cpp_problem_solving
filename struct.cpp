#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    char grade;
};

int main()
{
    Student student1;

    student1.name = "Liam";
    student1.age = 35;
    student1.grade = 'A';


    cout << "Name: " << student1.name << "\n" << "Age: " << student1.age << "\n" << "Grade: " << student1.grade;



    return 0;
}