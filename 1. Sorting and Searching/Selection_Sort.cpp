#include <iostream>
using namespace std;

int main() 
    {
        /*
        search the minimum element in the array
        swap it with the start index 
        increment start index and find the next minimum element
        and repeat the process   
        
        for n elements n-1 rounds will be required
        */
        int array[5];
        for (int i = 0; i < 5; i++)
            {
                cin>>array[i];
            }
        cout<<"sorted array : ";
        for(int i = 0; i < 5; i++)
            {
                int minimum = array[0];
                for(int j = i; j < 5; j++)
                    {
                        if(array[j]<array[i])
                            {
                                int temp = array[j];
                                array[j] = array[i];
                                array[i] = temp;
                            }
                    }
                cout<<array[i]<<" ";    
            }
        return 0; 
    }