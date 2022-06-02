#include<iostream>
using namespace std;

int main()  
    {
        //an example of dereferencing 
        int i = 106;
        char c = i;
        int * p = &i;
        //char * pc = &i; // an error you can't store the address of
        //an int in a char ptr, we will have to explicitly typecast

        char * pc = (char*)p;

        cout<<*p;
        cout<<c;
        cout<<*pc<<endl;
        cout<<*(pc+1)<<endl; // null chars 
        cout<<*(pc+2)<<endl;
        cout<<*(pc+3)<<endl;
        //in memory i is stored as |106,0,0,0|
        //based on little endian and big endian thats why *pc gives 106 (j)
        return 0;
    }