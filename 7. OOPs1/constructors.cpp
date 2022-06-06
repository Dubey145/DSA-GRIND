#include<iostream>
#include<string>
using namespace std;
//constructor : same name as the class, no return type,
// a default constructor has no arguments
// a constructor is already made when the class is made it initializes the values with garbage
class staff
    {   
        private:
            int salary = 50000;
        public:
            char name[20];
            int age;
            char grade;
            staff() 
                {
                    cout<<"constructor called "<<endl;
                    strcpy(name, "xxxx");
                    age = 0;
                    grade = 'A';
                }
            //parameterized constructor
            staff(char name[], int age,char grade) // if using same name use this keyword
                {
                    strcpy(this->name, name);
                    this->age = age;
                    this->grade = grade;
                }
            void display() 
                {
                    cout<<name<<" "<<age<<" "<<grade<<endl;
                }
    };

//when an object is created a constructor is automatically called

int main()
    {
        staff t1; // will display constructor called once 
        t1.display(); // will display the default values 
        staff t2("aayush",20,'A');
        t2.display(); 
        return 0;
    //if any type of constructor is formed then the constructor that comes inbuilt with the class becomes
    //inactive and while creating objects we have to take care of the arguments otherwise an 
    //error comes
    
    //"this" keyword holds the address of the current object
    }