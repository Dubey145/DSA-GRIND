#include<iostream>
using namespace std;
//check if an array is sroted recursively
bool check(int array[], int size) 
    {
            if(size == 0 || size == 1) 
                return true;
            if(array[0]>array[1])
                return false;
            else 
                {
                    bool sorted = check(array+1, size-1);
                    return sorted;
                }
    }


int main() 
    {
        int array[5];
        for(int i = 0; i < 5; i++) 
            {
                cin>>array[i];
            }
        cout<<"sorted: "<<check(array, 5)<<endl;

        return 0;
    }