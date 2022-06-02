#include <iostream>
using namespace std;

void print(int *p)
    {
        cout<<*p<<endl;
    }

void increment(int *p) 
    {
        *p = (*p)+1;
        //the address of i is received so the changes will reflect
        //this is call by reference
    }

void increment_copy(int i)
    {
        i++;
        //changes will not reflect as changes are made on the copy of i
        // call by value
    }

int main()
    {
        int i =10;
        print(&i);
        increment(&i);
        print(&i);
        increment_copy(i); 
        print(&i);
        return 0;
    }
