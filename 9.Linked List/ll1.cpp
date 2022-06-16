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
        void print(node *head) // will lose data after printing operate on a copy of head
            {
                //head here is a local variable
                //changes made to iw will  not affect the head in main 
                //but if we use head here for operations we might lose data so make a temp
                node * temp = head;
                while(temp != NULL) //use -> for pointers it means (*ptr).attr
                    {
                        cout<<temp->data<<endl;
                        temp = temp->next;
                    }
            }
    };
    
     
int main()
    {
        // node n1(1);
        // node n2(2);
        // node *head = &n1;
        // n1.next = &n2; // connected n1 with n2
        // cout<<head->data<<endl;
        // cout<<head->next->data;
        // //dynamic 
        // node *n3 = new node(3);
        // n2.next = n3;  
        // n3->next = NULL;

        //node n1(100),n2(200),n3(300),n4(400),n5(500);
        //node * head = &n1;
        
        //connecting manually
        /*
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4; 
        n4.next = &n5;
        n5.next = NULL;
        //LETS PRINT 
        head->print(head);
        n1.print(head); 
        */
        

        //printing dynamically generated nodes 
        node * head;
        node * n1 = new node(1);
        node * n2 = new node(2);
        node * n3 = new node(3);
        node * n4 = new node(4);
        node * n5 = new node(5);
        n1->next = n2;
        n2->next = n3;
        n3->next = n4; 
        n4->next = n5;
        n5->next = NULL;
        head = n1;
        head->print(head);

        return 0;
    }