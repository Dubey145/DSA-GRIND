#include <iostream>
using namespace std;

class student
    {   
        public:
            int roll;
            int age;
            //int total_students; // this should be a constant for a group of students , the property value must be same
        //total_student belongs to a class and not a student, so we declare it as static 
            static int total_students ; // memory will be allocated only once and not for all students 
        student()
            {
                total_students++;
                
            }
        static int get_total_students() 
            {
                return total_students;
            }
    };
//even functions can be made static

// initialization of static class members are done outside the class always 
int student :: total_students = 0;

//lets say we want to keep updating the value of total_student, on the go, as we keep creating students
int main() 
    {
        
        // to access static properties
        cout<<student::total_students<<endl; // :: is the scope resolution operator
        student s1,s2,s3,s4;
        cout<<student::total_students<<endl;
        
        //accessing static function 
        cout<<student::get_total_students()<<endl;
        return 0;
    }