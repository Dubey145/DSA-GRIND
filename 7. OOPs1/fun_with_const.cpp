#include<iostream>
using namespace std;
// a constructor or a destructor cannot be declared in private;
class student
    {   
        private:
            char name[20];
            int age;
            int roll;
        public:
            student()
                {
                    name = "x";
                    age = 0;
                    roll = 0;
                }
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
        student s1("aayush", 20,9092);
        student s2; 
        s2 = s1; // here a constructor is not called this is the copy assignment operator
        student s3 = s1; // internally interpreted as student s3(s1) and the copy constructor is called 
        return 0;
    }