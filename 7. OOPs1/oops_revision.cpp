#include<iostream>
#include<cstring>
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

//getters and setters 
class box
    {
        private:
            int cost = 5;
            int volume;

        public:
            int l,b,h;
            
            void set_volume() // setter
                {
                    volume = l*b*h;
                    cout<<volume<<endl;
                }
            int filling_cost()
                {
                    return volume*cost;
                }
    }b1;

//constructors
//default constructor has no parameters
class staff 
    {
        private:
            int salary = 50000;
        public:
            char name[20];
            int age;
            int dept;
        staff()
            {
                cout<<"constructor called "<<endl;
                strcpy(name,"staff_name");
                age = 18;
                dept = 0;
            }
        //parameterized constructor
        staff(char name[],int age, int dept)
            {
                //as the same names are used 
                //i will have to use "this" keyword
                //"this" keyword holds the address of the current object
                cout<<"parameterized"<<endl;
                strcpy(this->name,name);
                this->age = age;
                this->dept = dept;
            }
        void display()
            {
                cout<<name<<endl;
                cout<<age<<endl;
                cout<<dept<<endl<<endl;
            }
        //destructors - they are already predefined with class but we can define them separately.
        //the destructor is called when the scope of the opject ends (for static objects only)
        //for dynamic object use delete keyword as - delete s5
        ~staff()
            {
                cout<<"staff object destroyed"<<endl;
            }
    };

//access class elements with "." operator
int main()
    {
        //student class 
        student s3;
        strcpy(s3.name, "Student three");
        s3.age = 20;

        //for dynamic objects 
        (*s2).age = 21;
        //or
        s2->roll_no = 1;
        strcpy(s2->name, "Student two");

        cout<<s2->name<<endl; // for dynamic object use ->
        cout<<s3.name;
        

        //box class 
        cout<<"enter dimensions for the box l b h : ";
        cin>>b1.l>>b1.b>>b1.h;
        b1.set_volume();
        cout<<"Filling cost: "<<b1.filling_cost();
        
       

        //staff class 
        staff s1,s2("ABC",22,5);
        s1.display();
        s2.display();
        //using the copy constructor - 2 methods 
        staff staff3(s2);
        staff s4 = s2;
        staff3.display();
        s4.display();
        //for dynamic objects 
        staff *s5 = new staff(s2);
        s5->display();
        staff *s6 = new staff("def",23,2);
        s6->display();
        
        return 0;
    }