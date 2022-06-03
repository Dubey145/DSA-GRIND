#include<iostream>
using namespace std;

void increment(int &j);

int main()
    {
        int i = 10;
        //int j = i;
        //if I make any changes in i and print j, j will still be 10
        //to make the changes reflect in j we will have to declare j 
        //as a reference variable with &    
        int &j = i;
        // no new space is declared for j 
        //when we declare a reference we have to initialize it
        i++; 
        cout<<j<<endl;

        //reference variables are useful for 
        //call by reference of a function 
        increment(i);
        cout<<i;
        return 0;
    }
void increment(int &j)
    {
        j++;
        // changes will reflect on i 
    }
//do not return the reference of a local variable as the 
//memory allocated for it will be destroyed once the function 
//has finished executing