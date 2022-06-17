#include<iostream>
#include<vector>
using namespace std;

//vectors
//vectors are simply inbuilt dynamic array, we dont have to specify the size, if we run out of space the vector will double its size 

int main()
    {
        vector<int> v; // static 
        vector<int> *vp = new vector<int>; //dynamic

        // to add elements to vector use .push_back
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        //vector will be 10 20 30

        //printing 0th element
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" ";
        //we can treat it like an array

        //changing an element 
        v[1] = 100; 
        cout<<v[1]<<endl;

        v[4] = 200; // we can't add elements like this, this will add the elements but the pushback function also checks for the size availability and decices when to double the array, if we keep adding elements like this we will not know when the size is not available 
        
        //use [] only for accessing the elements or for updating values at some index but NOT for inserting

        //printing the size of the vector 
        cout<<"size: "<<v.size()<<endl;
        //alternate [] - at function 
        cout<<v.at(2);

        //accessing an out of index element 
        cout<<v[6]<<endl; //will print garbage 
        cout<<v.at(6);     //will print an error, this is much safer to use 

        for(int i = 0; i < v.size(); i++)
            { 
                cout<<v[i]<<" ";
            }

        //to delete the last element use pop_back()
        v.pop_back();
        return 0;
    }