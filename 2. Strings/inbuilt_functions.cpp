#include<iostream>
#include<cstring>
using namespace std;

/*
in cstring
there are some inbuilt functions in c++ for string operations 

1. strlen(string_name) returns the length of a string
2. strcmp(string1,string2) - if returning 0 means both are same
>0 if the first non-matching character in str1 is greater (in ASCII) than that of str2.
<0 if the first non-matching character in str1 is lower (in ASCII) than that of str2.

3. strcpy(destination,source) - copies a string to another s-d



*/

int main()
    {
        char input[100];
        cin.getline(input, 100);

        cout<<"length :"<<strlen(input);
        
        char input2[100];
        cin.getline(input2, 100);
        cout<<strcmp(input, input2);


        return 0;
    }