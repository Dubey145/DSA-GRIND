#include<iostream>
using namespace std;
template<typename T>

class node 
    {
        public:
            T data;
            node<T> * next;
    };
template<typename T>
class stack
    {
        node<T> *head;
        node<T> *tail;
        int size; 
        public : 

        stack() 
            {
                head = NULL;
                tail = NULL;
            }
        void push(int element)    
            {
                node<T> *new_data = new node<T>;
                new_data->data = element;
                new_data->next = NULL;
                if(head == NULL)
                    {
                        head = new_data;
                        tail = new_data;
                        size++;
                    }
                else 
                    {
                        tail->next = new_data;
                        size++;
                    }
            }
        void top() 
            {
                cout<< tail->data;
            }
        void pop()
            {
                size--;
                node<T> * temp = head;
                for(int i =0;i< size; i++) //O(n), to get it to O(1) imagine the LL differently
                    {
                        temp = temp->next;
                    }
                tail = temp;
            }
    };

/*

instead of inserting after head we will insert before head

instead of inserting like this 
10->20->30->40->NULL

we insert in this way
40->30->20->10->NULL
*/
template<typename T>
class newStack
    {
        node<T> * head;
        int size;

        public:
        newStack() 
            {
                head = NULL;
                size = 0;
            }
        void push(T element)    
            {
                node<T> *new_data = new node<T>;
                new_data->data = element;
                if(head == NULL)
                    {
                        head = new_data;
                        size++;
                    }
                else
                    {
                        new_data->next = head;
                        head = new_data;
                        size++;
                    }
            }
        void pop()
            {
                if(head == NULL)
                    cout<<"\nstack is empty"<<endl;
                else
                    {
                        head = head->next; //now pop happens in O(n)
                        size--;
                    }
            }
        void top()
            {
                cout<<head->data;
            }
        void display()
            {
                node<T> * temp = head;
                while(temp != NULL)
                    {
                        cout<<temp->data<<endl;
                        temp = temp->next;
                    }
                    
            }
    };
int main( )
    {
        newStack<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.display();
        s.pop();
        s.display();
        return 0;
    }