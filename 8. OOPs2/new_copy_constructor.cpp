#include<iostream>
#include<cstring>
using namespace std;

class student
    {   
        private:
            int age;
            int grade;
        public:
            char *name;
            student(int age, char *name, int grade)
                {
                    this->age  = age;
                    this ->name = new char[strlen(name) + 1];
                    strcpy(this->name, name);
                    this->grade = grade;
                }
            //creating a deep copy - copy constructor
            student(student  &s)
                {
                    this->age = s.age;
                    this->grade = s.grade;
                    // this ->name = s.name - this will perform shallow copy
                    this->name = new char[strlen(name) + 1];
                    strcpy(this->name, s.name);
                }
        void display()
            {
                cout<<name<<" "<<age<<" "<<grade<<endl;
            }
    };

int main()
    {
        char name[] = "dubey";
        int age = 20;
        int grade = 12;
        student s1(age,name,grade);
        s1.display();
        student s2(s1);
        s2.name[0] = 'x'; // changes were reflected in bothr s1 and s2 
        s1.display();
        s2.display();
        //same because inbuilt copy constructor performs shallow copy
        return 0;
    }