#include<iostream>
using namespace std;


int main()
    {
        cout<<"Binary Search"<<endl;
        /* the input array has to be sorted
        figure out the middle element of the array
        middle = (n+1)/2 for odd n
        middle = n/2 and (n+1)/2 for even n
        in algorithm mid = (start+mid)/2

        if the element is greater than the middle element
        search in the right part else left part 
        calculate middle again 

        when start>end then the element is not present in the array 
        */
        //code
        int array[5];
        cout<<"enter sorted array"<<endl;
        for(int i = 0; i < 5; i++)
            {
                cin>>array[i];
            }
        cout<<"enter element to search : ";
        int element;
        cin>>element;
        int start = 0;
        int end  = 4;
        
        while(start<=end)
            {
                int mid = (start + end)/2;

                if(array[mid] == element)
                    {
                        cout<<"\n element found at "<<mid<<endl;
                        return 0;
                    }
                else if(array[mid] > element)
                    {
                        start = start;
                        end = mid-1;
                    }
                else 
                    {
                        start = mid+1;
                        end = end;
                    }
            }
        cout<<"\n element not found ";

        return 0;
    }
