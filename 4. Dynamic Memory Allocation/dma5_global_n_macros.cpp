#include<iostream> //called a pre-processor director
using namespace std;
#define pi 3.14
int age = 10;

/*

1. #define var value - used to define a variable and its value 
so that if the value changes edits are required only at one place 

at complie time wherever pi is written 3.14 will replace it

2. Global variables - available everywhere till the program ends
if in a function a local variable has the same name as the global variable 
then edits are made in the local variable

problem with global variables is that any function can change it 

*/

int main()
    {  
        int radius ;
        cout<<"enter radius"<<endl;
        cin>>radius;
        cout<<"area of the circle: "<<pi*radius*radius;
        
        return 0;
    }