#include <iostream>
using namespace std;

int main()
    {
        int i = 0;
        int *p = &i;

        cout<<p<<endl; 
        p = p + 1; //starts pointing to the next integer by adding 4 to address
        cout<<p;

        //pointer arithmetic makes sense ony in arrays as by incrementing a pointer
        //we can access the next element of the array by

        int a[] = {1,2,3,4,5};
        int *ptr = &a[0];

        /*
        in arrays the name of the array acts as a pointer to 
        the first elements 
        the difference between pointers and array name is that 
        sizeof() will work differently
        allocation of bytes is different for ptr is 8 bytes and 
        for a its 20 bytes
        
        if we write &ptr it will print the address of ptr 
        if &a it will print the address of the 1st element 

        an array cannot be reassigned if a[5] has base address of 700
        an entry in the symbol table has been made corresponding 
        to a 

        now performing a = a+3 will not work as changes cannot be 
        made in the symbol table 

        */
        cout<<endl<<a<<", "<<p<<endl;

        cout<<&a<<' '<<&p<<endl;

        //a and &a will have the same value as there is no different 
        //storage for a
        //p and &p will have different value because there is a 
        //spcae created for p
        
        //a = a + 1; not possible
        return 0;
    }