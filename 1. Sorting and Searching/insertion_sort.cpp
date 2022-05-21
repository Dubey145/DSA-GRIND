#include<iostream>
using namespace std;

int main()
    {
        int array [5];
        for (int i = 0; i < 5; i++)
            {
                cin>>array[i];
            }
        for(int i =1; i<5;i++)
            {
                int current = array[i];
                int j;
                for(j=i-1; j>=0; j--)
                    {
                        if(current< array[j])
                            {
                                //shift 
                                array[j+1] = array[j];
                            }
                        else 
                            break;                        
                    }
                array[j+1] = current;
            }
        for(int i =0;i<5;i++)
            {
                cout<<array[i]<<" ";
            }
        return 0;
    }