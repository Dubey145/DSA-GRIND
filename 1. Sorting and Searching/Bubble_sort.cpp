#include<iostream>
using namespace std;
/*

we compare first 2 adjacent elements and perform required swapping
in one complete round one element will reach its right place 
repeat the process till the last sorted array element

*/
int main()
    {
        int array[5];
        for(int i=0; i<5; i++)
            {
                cin>>array[i];
            }
        for(int i=0; i<4 ; i++) //  4 = n-1
            {
                for(int j=0; j<5-i-1;j++) // j<n-i-1
                    {
                        if(array[j]>array[j+1])
                            {
                                int temp = array[j+1];
                                array[j+1] = array[j];
                                array[j] = temp;
                            }
                    }
            }
        for(int i=0; i<5;i++)
            {
                cout<<array[i]<<" ";
            }
        return 0;
    }