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

void delete_at_i(node * head,int index)
    {
        //traverse to that node 
        node * temp = head;
        for(int i=0;i<index;i++)
            {
                temp = temp->next;
            }
        temp->next = temp->next->next;
        
    }
node*  Rinsert(node *head,node *new_data,int index)
    {
        if(index == 0)
            {
                new_data->next = head;
                head = new_data;
                return (head);
            }
        else 
            {
                node *temp_head;
                temp_head = Rinsert(head->next,new_data,index-1);
                head->next = temp_head;
                return(head);
            }
    }
int recursive_length(node * head)
    {
        if (head == NULL)
            {
                return 0;
            }
        else 
            {
                return 1 + recursive_length(head->next);
            }
    }
node* recursive_insert(node * head)
    {
        cout<<"enter index and data to insert";
        int data;
        int index;
        cin>>data>>index;
        node *new_node = new node(data);
        node *temp = head;
        head = Rinsert(temp,new_node,index);
        return head;
    }

node* recursive_delete(node *head, int index)
    {
        if(index == 0)
            {
                return head;
            }
        else 
            {
                node *temp_head;
                temp_head = recursive_delete(head,index-1);
                temp_head->
            }
    }

int main()
    {
        node * head = userip();
        //insert at a specific index 
        // int index;
        // //cout<<"enter index for insertion";
        // cout<<"length of the LL is : "<<recursive_length(head);
        // cout<<"enter index for deletion";
        // cin>>index;
        // //head = insert_at_index(index,head); // if an element is inserted at index 0 then the head has to be updated
        // //head->printLL(head);
        // delete_at_i(head,index);
        // head->printLL(head);

        head = recursive_insert(head);
        head->printLL(head);
        
        return 0;
    }