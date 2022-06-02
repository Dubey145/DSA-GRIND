#include <iostream>
using namespace std;

int main()
    {
        //different behaviour of char arrays 
        
        int a[ ] = { 0, 1, 2, 3 };
        char str[] = "hello";

        cout<<a<<endl; //prints the address of 0th element
        cout<<str<<endl; //prints the whole string

        char *c = &str[0];
        cout<<*c; //behaves like an array and just prints the first character
         
        char ch = 'a';
        char *chp = &ch;

        cout<<endl<<ch<<endl;
        cout<<chp; //will print till it finds a null char

        char str[] = 'abcde'; //first abcde is stored in a temporary memory and then it is copied to str
        char *pstr = 'abcde'; //we made a pointer that points to that temporary memory

    
        return 0;
    }