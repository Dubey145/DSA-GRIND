#include<iostream>
using namespace std;

class stackArray 
    {
        int size;
        int *data;
        int next_index;

        public:

        stackArray()
            {
                cout<<"enter size of stack : ";
                cin>>size;
                data = new int[size];
                next_index = 0;
            }
        //user functions
        int get_size()
            {
                return next_index; // just return the next index
            }
        bool is_empty()
            {
                return next_index == 0;
            }
        void push(int element)
            {
                if(next_index == size)
                        cout<<"\nStack is full";

                else 
                    data[next_index++] = element;
            }
        void pop()
            {
                if(next_index == 0)
                    {
                        cout<<"Stack is empty";
                        return;
                    }
                else 
                    next_index--;
            }
    };

int main()
    {
        stackArray s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.pop();
        cout<<s.get_size();
        return 0;
    }