#include<iostream>
using namespace std;

class student
    {
        public:
            char name[20];
            int age;
            int grade;
            char sec;
            int roll_no;

    };
student s1;
student s[10];

//dynamic allocation just like declaring an int 
student * s2 = new student;


int main()
    {
        student s3;
        strcpy(s3.name, "Student");
        return 0;
    }