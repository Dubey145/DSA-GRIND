#include<iostream>
using namespace std;

/*
strings are 1d characters arrays
we can directly take input and output for a string and a loop will not be required 
strings end with a null char \0 ascii value is 0

the last space is reserved for the null character
so name can only store 19 chars

cin cannot read space tab or newline 
use cin.getlin(string_name,length) for sentance input it will read till \n

getline can take 3 arguments, 2 are mandatory

the 3rd argument is a delimiter 
its default value is \n
*/

int length(char input[]) 
    {
        int i = 0;
        while(input[i] != '\0')
            {
                i++;
            }  
        return i;
    }

int main()
    {
        char name[5];
        cout << "name :";
        cin.getline(name,3);
        cout<<name;
        cout<<"length of your name is :"<<length(name)<<endl;

        char paragraph[100];
        cout<<"enter paragraph end with /\t";
        cin.getline(paragraph,100, "0");
        cout<<paragraph;
        return 0;
    }