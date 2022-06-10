#include<iostream>
using namespace std;

//to set class variables as constant variables
class student 
    {   
        public:
            int age;
            const int rollno; // this wont work, we have declared first and then we are assigning this is not possible with const as while declaration assignment is required for const, same for references

            //we can try to make a constructor 
            /*student(int roll)
                {
                    rollno = roll; // roll no is const and no changes are allowed it stores garbage
                }
            */
           
           //we have to make an "initialization" list, which would automatically initialize memory at the time of allocation before going into the constructor
            int &reference;

           student(int age, int roll) : rollno(roll),reference(this->age) // this statement will be equivalent const int rollno  = roll also if the parameter name is the same we do not need to use this keyword just type rollno(rollno) 
           //for the reference variable we want to create a reference to class varaible not the argument so we use this keyword 
            {

                this->age = age;
            }
    
    };

int main() 
    {
     
        student s1(20,2);
        

        return 0;
    }