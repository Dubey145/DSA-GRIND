#include<iostream>
#include<cstring>
using namespace std;

class student
    {   
        private:
            char *name;
            int age;
            int grade;
        public:
        student(int age, char *name, int grade)
            {
                this->age  = age;
                //this->name = name; // stores the address where a is stored - this is called shallow copy and it causes the name problem mentioned below

                //ideally we should create an array here and copy the contents of name to the local array and then assign it to class attribute name - this method is deep copy

                //shallow copy - only the reference to the array is copied 

                //deep copy - complete array is copied 
                this ->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
                this->grade = grade;
            }
        void display()
            {
                cout<<name<<" "<<age<<" "<<grade<<endl;
            }
    };

int main ()
    {
        char name[] = "dubey";
        int age = 20;
        int grade = 12;
        student s1(age,name,grade);
        s1.display();

        name[2] = 'x';
        age = 22;
        grade = 11;
        student s2(age,name,grade); 
        s2.display();
        s1.display();
        //both give the same result why?
        /* 
        this happens because in the constructor name stores the address of the variable name in main 
        so when changes are made in the variable name they are reflected at the address space and it is then stored in name of object s2 
        as the object s1 still points to the same name at the same location changes are reflected in s1 also
        */

        return 0;
    }