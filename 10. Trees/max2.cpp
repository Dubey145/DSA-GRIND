#include<iostream>
using namespace std;

void max2(int array[],int size)
    {
        int m1 = array[0];
        int m2 = array[1];
        for(int i = 0; i < size; i++)
            {
                if(m1 <= array[i])
                    {
                        m2 = m1;
                        m1 = array[i];
                    }
            }
        cout<<m2;
    }

int main() 
    {
            int size;
            cin>>size;
            int *array = new int[size];
            for( int i = 0;i < size; i++ )
                {
                    cin>>array[i];
                }
            max2(array,size);     
        return 0;
    }