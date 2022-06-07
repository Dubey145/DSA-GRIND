#include<iostream>
using namespace std;
// for an object a constructor is only called once that is at the
//time of creation
//if 2 objects are declared and details of one have to be copied
//then we can use = operator this is the copy assignment operator

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
        student s2 = s1; // or student s2(s1); // this is the copy assignment operator
        s2.display();

        student *s3 = new student("dubey",21,2001);
        cout<<"\n s3 data : ";
        s3 ->display();
        student s4(*s3); // derefer and pass
        s4.display();
        student s5 = new student(*s3);//s3 copied in s5
        return 0;
    }
/* notes 
copy constructor: to copy the attributes of an object to another
use line 27 to use copy constructor 
copy constructor if not defined is made internally

for a dynamic object derefer and pass check  line 39
*/