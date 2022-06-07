#include<iostream>
using namespace std;

class student
    {   private:
            char name[20];
            int age;
            int roll;
        public:
            student(char n[20],int a, int r)
                {   
                    strcpy(name,n);
                    age = a;
                    roll = r;
                }       
            void display()
                {
                    cout<<name<<" "<<age<<" "<<roll<<endl;
                }
            ~student()
                { 
                    cout<<"object destroyed"<<endl;
                }
    };

int main()
    {
        char name[20];
         cin>> name;
        int age ;
        cin>>age;
        int rollno;
        cin>>rollno;
        student s1(name,age,rollno);
    }
/*----------------------------------------------------------------
notes
DESTRUCTOR:  called to deallocate the memory allocated for an object
once the object is done with its use, or when the scope of it is finished 

it has the same name as that of the class

it has no return type
 
takes no input Arguments
 '~' symbol is used before the destructor to indicate that 
 it is a destructor

there can only be one destructor per class
if it is not defined it is predefined when the class is made

** for dynamic objects the delete keyword has to be used 
because the name of the obejct is actually a pointer 
eg delete s3;
*/