#include<iostream>
using namespace std;

//implementation of LL : linked list 

class node
    {
        public:
        int data;
        node *next;
        node(int data)
            {
                this->data = data;
                this->next = NULL;      
            }
        void printLL(node *head)
            {   
                node *temp = head;
                while(temp!= NULL)
                    {
                        cout<<temp->data<<" ";
                        temp=temp->next;
                    }
                //cout<<temp->data<<" ";
                
            }
        
    };
void input()
    {
        char choice = 'y';
        node* head = NULL;
        while(choice=='y')
            {
                int data ;
                cin>>data;
                node *n = new node(data); // we will have to allocate memory dynamically otherwise it will be deallocated after every iteration 
                if(head == NULL)    
                    {
                        head = n;
                    } 
                else
                    {
                        node *temp;
                        temp = head;
                        while(temp->next!=NULL)
                            temp = temp->next;
                        temp->next = n;
                    }
                cout<<"do you want to enter more nodes?(y/n) :";
                cin>>choice;
    
            }
        head->printLL(head);
    }

//improving time complexity of input function 

node* ui()
    {
        char choice = 'y';
        node *head = NULL;
        node *tail = NULL;
        while (choice != 'n')
            {
                cout<<endl<<"enter node data ";
                int data;
                cin>>data;
                node *n = new node(data);
                if(head == NULL && tail == NULL)
                    {
                        head = n;
                        tail = n;
                    }
                
                //finding the address of the last node without a loop 
            
                else
                    {
                        tail->next = n;
                        tail = n;
                    }
                cout<<endl<<"do you want to enter more nodes?(y/n) :";
                cin>>choice;
            }
        head->printLL(head);
        return head;
    }

int length(node* head)
    {
        int counter =0;
        node *temp = head;
        while(temp!= NULL)
            {
                counter++;
                temp=temp->next;
            }
        return counter;
    }                
            
//printing ith node 
void print_i(node * head , int index)
    {
        if(index < length(head))
            {
                node *temp = head;
                for(int i =0;i<index;i++)
                    {
                        temp = temp->next;
                    }
                cout<<endl<<"element at index "<<index<<" is "<<temp->data;
            }
        else 
            {
                cout<<endl<<"incorrect index"<<endl;
            }

    }

void insert_at_i(node * head , int data, int index)
    {
        node *element = new node(data);
        node *temp = head;
        for(int i = 0;i<index-1;i++)
            {
                temp = temp ->next;
            }
        element->next = temp ->next;
        temp ->next = element;
        head->printLL(head);
    }
void delete_at_i(node * head ,int index)
    {
        int len = length(head);
        node *temp = head;
        if(index == 0)
            {
                head = head ->next;
            }    
        else if (index == len-1)
            {
                for (int i = 0;i<index-1;i++)
                    temp = temp ->next;
                temp ->next = NULL;
            }
        else //used 2 pointers
            {
                for (int i = 0;i<index-1;i++)
                    temp = temp ->next;
                node * temp2 = temp ->next;
                temp ->next = temp2->next;
                free(temp2); 
            }
        head->printLL(head);
    }

int recursive_length(node * head )
    {
        node * temp = head ;
        if(temp == NULL)   
            {
                return 0;
            } 
        else 
            {
                return 1 + recursive_length(temp->next);
            }
    }
void recursive_insert(node* head,int data,int index,int counter = 0)
    {
        node * temp = head ;
        if(index == counter-1)
            {
                node *element = new node(data);
                element->next = temp->next;
                temp->next = element;
                return;
            }
        else   
            {
                recursive_insert(temp->next,data,index,counter+=1);
            }
    }

void recursive_delete(node* head, int index, int counter = 0)
    {
        node * temp = head ;

        if(index == counter-1)
            {
                node * temp2 = head->next;
                temp->next = temp2->next;
                free(temp2);
            }
        else 
            {
                recursive_delete(temp->next,index,counter+=1);
            }
    }
/*int main()
    {
        node* head = ui();
        //cout<<endl<<"length of the LL is : "<<length(head);
        // int index;
        // cout<<"\n enter index";
        // cin>>index;
        // print_i(head,index);
        // int data;
        // cout<<"\n enter data to be inserted at the given index :";
        // cin>>data;
        // insert_at_i(head,data,index);

        // cout<<"\n element at index "<<index<<"will be deleted";
        // delete_at_i(head,index);
        
        //cout<<endl<<"length of the LL is : "<<recursive_length(head);

        int index;
        cout<<endl<<"enter index at which data is to be deleted";
        cin>>index;
        recursive_delete(head,index);
        head->printLL(head);
        return 0;
    }*/