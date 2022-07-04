#include<iostream>
#include<stack>
using namespace std;

int main() 
    {
        //declaring a stack 
        stack<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);

        s.pop();
        cout<<s.top()<<endl;

        cout<<s.size()<<endl;
        cout<<s.empty();
        return 0;
    }