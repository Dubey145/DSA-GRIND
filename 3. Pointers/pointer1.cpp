#include<iostream>
using namespace std;

/*
1. when we write i = 10, in the memory space is allocated for an integer

2. then a pointer is allocated that sotres the address of where 
storage is allocated for i

3. then the values is assigned in the assigned storage

a symbol table during compile time is made for variables which
stores the address of each variable in memory

to fetch the stoage of i which stores 10 use the address of operator "&"

POINTERS ARE VARIABLES WHICH STORE ADDRESS OF OTHER VARIABLES


*/

int main()
    {
        int i =10;
        cout<<endl;
        cout<<&i; //storages are in hexadecimal format

        //declaring a pointer 
        int *int_ptr = &i;
        cout<<endl<<int_ptr<<endl; //prints what ptr is storing ie the address of i

        float f = 0.02;
        float *float_ptr = &f;
        cout<<endl<<&f<<endl<<float_ptr;

        //directly accessing the value stored an address saved in a pointer
        cout<<endl<<*int_ptr<<endl;
        cout<<sizeof(int_ptr); //8 bytes allocated for a pointer variable
        cout<<sizeof(float_ptr); //8 bytes even for float pointers

        //changes made in *int_ptr will affect i and vice versa

        return 0;
    }