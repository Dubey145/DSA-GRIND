#include<iostream>
#include<string>
using namespace std;
 
class student
    {   public: // access modifers define from where till where are the function of a class can be used  
        //they are public private and are protected
        //private ; can only be used within the class 
        // by default all the data is private   
        //public : can be used in with the outside world 
        
            char name[20];
            int age;
            int roll;
            int grade ;
            char section;
    };
//creating objects
student s1; // static allocation 
student s[10]; // static 

//dynamic creation of objects
// for an integer we write int *a = new int ;
 student *s2 = new student;

 int main() 
    {
        student s3;
        //setting details of s3
        strcpy(s3.name,"aayush");
        s3.age = 20;
        cout<<s3.name;
        cout<<s3.age; 
  
        //for the dynamic objects 
        (*s2).age = 24;//alternative -- s2->age = 24
        strcpy((*s2).name,"dubey");//we can use an arrow also 
        cout<<(*s2).name;

        return 0;

    }