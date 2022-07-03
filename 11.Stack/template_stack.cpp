#include<iostream>
using namespace std;

//dynamic stack, no constraint in size
template< typename T >

class stackDynamic 
    {
        int size;
        T *data;
        int next_index;

        public:

        stackDynamic()
            {
                size = 4;
                data = new T[size];
                next_index = 0;
            }
        //user functions
        void display()
            {
                cout<<endl;
                for(int i = 0; i < next_index; i++)
                    {
                        cout<<data[i]<<" ";
                    }
            }
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
                    {
                        cout<<"\nStack is full, increasing size";
                        size *=2;
                        T * new_data = new T[size];
                        for(int i = 0;i< size; i++)
                            {
                               new_data[i] = data[i];
                            } 
                        delete [] data;
                        data = new_data;
                    }
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

int main ()
    {
        stackDynamic <int> s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.push(6);
        s.pop();
        s.display();
        
        stackDynamic <char> c;
        c.push('a');
        c.push('b');
        c.push('c');
        c.push('d');
        c.push('e');
        c.push('f');
        c.pop();
        c.display();
        
        return 0;
    }