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

void increment_pointer(int *p)
    {
        *p = (*p)+1;
        //changes will reflect
    }

void sum(int arr[] , int size) 
    {
        //here arr acts as a pointer and sizeof(arr) = 8 not 20bytes
        arr[0] = 2;
        int count = 0;
        for(int i=0; i<size; i++)
            {
                count += arr[i];
            }
        cout<<count;
    }

int main()
    {
        int i =10;
        print(&i);
        increment(&i);
        print(&i);
        increment_copy(i); 
        print(&i);
        increment_pointer(&i); 
        print(&i);

        int array[] = {1,1,1,1,1};
        sum(array,5); //the base address of the array is passed
        cout<<endl<<array[0];
        return 0;
    }
