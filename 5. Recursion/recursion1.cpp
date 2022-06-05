#include<iostream>
using namespace std;

/*
a function calling itself is called recursion 

recursion is used when the solution to a problem 
lies in the solution of the same proble with a smaller input size 
*/

int fact(int n)
    {
        if(n == 0)
            {
                return 1;
            }
        int factorial = fact(n-1);
        return n*factorial;
    }

int main()
    {
        int n ;
        cout<<"enter a number"<<endl;
        cin>>n;
        cout<<"factorial = "<<fact(n);
        return 0;
    }