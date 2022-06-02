#include<iostream>
using namespace std;
/*
to delcare an int we write int var
to declate an float we write float var

then to declare a pointer why not pointer p ?

it is because the type of pointer tells us the amt of memory we
can dereference with it 
for int it is 4 bytes, char 1 byte, float 8 bytes
*/

int main()
    {
        //what are double pointers?
        //double pointers store the address of pointers

        int i = 10;
        int *p = &i;
        int **dp = &p;

        cout<<i<<endl;
        cout<<&i<<endl;
        cout<<*p<<endl;
        cout<<&p<<endl;
        cout<<**dp<<endl;
        cout<<dp<<endl;
        cout<<*dp<<endl;
        cout<<&dp<<endl; 
        return 0;
    }