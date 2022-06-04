#include<iostream>
using namespace std;

/*
a function can have some default parameters which will only be required
if a user passes an extra argument to the function 

all default parameters have to be on the right side of all 
normal parameters while declaration
*/

void sum(int a, int b, int c = 0) 
    {  
        cout<<a+b+c<<endl;
    }

int main()
    {
        int a = 10;
        int b = 20;
        
        sum(a,b);
        sum(a,b,1);
        return 0;
    }