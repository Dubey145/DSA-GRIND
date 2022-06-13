#include<iostream>
using namespace std;

/* 
in array the biggest disdvantage was that we have to decide the size before declaring it 

to address this problem we create a linked list, elements are randomly placed in memory 

to access them we have to store the address of the first element and the first element will store the address of the 2nd element
so they are "linked"
the elements must store their data also 

the first node is called head 
the last node is called tail 

*/
class node 
    {
        private:
           
            int non = 0;
        public:

            int data;// to store the data of a node 
            node *next;//to store the address of next node
            node(int data) 
                {
                    if(non == 0)
                        {   
                            this->data = data;
                            next = NULL;
                        }
                }
    };
int main()
    {
        node n1(1);
        node n2(2);
        node *head = &n1;
        n1.next = &n2; // connected n1 with n2
        cout<<head->data<<endl;
        cout<<head->next->data;
        return 0;
    }