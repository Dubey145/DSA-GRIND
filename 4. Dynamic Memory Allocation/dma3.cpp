#include<iostream>
using namespace std;

/*
    while declaring an array it had to be of a fixed size
    int n ;
    cin>>n; // n decided on runtime
    int arr[n];
    this is not guaranteed to work in every system
    we could not have a variable length array

    program starts in the stack and if n is huge then the program will not run on the stack
    
    the dynamic memory allocation is done in the heap
    heap is much larger in size than the stack 

    how to DMA?
    "new" keyword is used for DMA
    new keyword will get the address that it has allocated in 
    the heap
    and the address is stored in a pointer
*/

int main() 
    {
        int *p = new int; //DMA, 4 bytes in the heap and 8 bytes in the stack for p
        *p = 10;
        cout<<*p;

        //arrays in heap 
        int *array = new int[10]; 
        //total memory allocated for array is 48 bytes

        //now we can use the run time method to declare arrays safely
        int n ;
        cin>>n;
        int *a = new int[n]; 
        // now array can be used like a normal array

        for(int i = 0; i < n; i++)
            {
                cin>>a[i];
            }
        cout<<endl;
        for(int i = 0; i < n; i++)
            {
                cout<<a[i]<<" ";
            }

        // dynamic memory is not deallocated when the scope ends 
        // it has to be deallocated by the user with "delete" keyword

        delete [] a;
        delete [] array;
        delete p;
        // memory is deallocated in the heap not in the stack
        return 0;
    }