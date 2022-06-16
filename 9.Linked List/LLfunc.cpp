#include<iostream>
using namespace std;

class node
    {
        public:
            int data;
            node * next;
        node(int data)
            {
                this->data = data;
            }
        void printLL(node * head)
            {
                node * temp = head;
                while(temp != NULL)
                    {
                        cout<<temp->data<<endl;
                        temp = temp->next;
                    }
            }
    };

node * userip() // time complexity of this function is O(n)
    {
        char choice = 'y';
        int data;
        node * head = NULL;
        node * tail = NULL;
        while(choice == 'y')
        {
            cout<<"\nenter data: ";
            cin>>data;
            node * temp = new node(data);
            if(head == NULL && tail == NULL) //first element 
                {
                    head = temp;
                    tail = temp;
                }
            else 
                {
                    //we will have to travel to the last element and for that we will have to use a while loop, this would make the complexity O(n^2), to avoid that lets maintain a node type tail pointer that keeps track of the last element 
                    tail->next = temp;
                    tail = temp;
                }
            cout<<"\ndo you want to enter more nodes? (y/n)";
            cin>>choice;
        }
        cout<<"\nStatus of LL :\n ";
        head->printLL(head);
        return head;
    }

node* insert_at_index(int index,node *head)
    {
        node *temp = head;
        cout<<"enter data to insert";
        int data;
        cin>>data;
        node *newdata = new node(data);
        if(index == 0) 
            {
                newdata->next = head->next;
                head = newdata;
                head->printLL(head);
                return head;
            }
        for(int i=0;i<index-1;i++)
            {
                temp = temp->next;
            }
        newdata->next = temp->next;
        temp->next = newdata;
        head->printLL(head);
        return head;
    }

int main()
    {
        node * head = userip();
        //insert at a specific index 
        int index;
        cout<<"enter index for insertion";
        cin>>index;
        head = insert_at_index(index,head); // if an element is inserted at index 0 then the head has to be updated
        head->printLL(head);

        return 0;
    }