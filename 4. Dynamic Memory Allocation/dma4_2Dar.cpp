#include<iostream>
using namespace std;

int main() 
    {
        //creating a 2d array of size 3x3 with DMA 
        int **p = new int*[3];
        for(int i=0; i<3; i++)
            {
                p[i] = new int[3];
            }
        for(int i = 0;i<3;i++) 
            {
                // p[i] = new int[3]; this statement can be here also
                for(int j = 0; j <3;j++)
                    cin>>p[i][j];
            }
        cout<<sizeof(*p)<<endl;
        //accessing element 1,2
        cout<<p[1][2];
        //it is not necessary to have the same no. of  element in every row
        //0th row can have 1 element, 1st row can have 5 elements, 
        //3rd can have 2 elements etc etc 

        //deleting space

        for(int i=0; i<3; i++)
            {
                p[i] = new int[3];
            }
        return 0;
    }