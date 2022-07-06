#include <iostream>
using namespace std;

/*

queue is a first in first out type of data structure
entry happens from rear and exit from the front 




insert is enqueue 
delete is dequeue 

*/
template <typename T>
class queue 
    {
        T *data;
        int size;
        int next_index;
        int front_index;
        int queue_size;  

        public: 

        queue()
            {
                cout<<"enter size of q : ";
                cin>>size;
                data = new T[size];
                front_index = -1; // front index stores the index of the elemet that has to be dequeued 
                next_index = 0;
                queue_size = 0;
            } 
        int get_size()
            {
                return queue_size;
            }
        bool isEmpty()
            {
                return queue_size == 0;
            }
        void enqueue(T element)
            {
                if(front_index == -1)
                    {
                        front_index = 0;
                    }
                if(queue_size != size)
                    {
                        data[next_index] = element;
                        next_index = (next_index + 1)%size; // we are circularly counting so this will implement a circular queue to avoid space wastage
                        queue_size++;
                    }
                else 
                    {
                        cout<<"queue is full";
                    }
            }
        T front()
            {
                if(!isEmpty())
                    return data[front_index];
        
                cout<<"\nqueue is empty";
                return 0;
            }
        void dequeue()
            {
                if(front_index == -1)
                    {
                        cout<<"queue is empty";
                    }
                else
                    {
                        cout<<"element  deleted:"<<data[front_index];
                        queue_size--;
                        front_index = ( front_index+1)%size;
                        if(size == 0)
                            {
                                front_index = -1;
                                next_index = 0;
                            }
                    }
            }
    };

int main()
    {
        queue<int> q;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.dequeue();
        q.dequeue();
        q.enqueue(5);
        cout<<q.front();
        return 0;
    }