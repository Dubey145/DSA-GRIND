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
class hnt
    {
        public:
        node * head;
        node * tail;
        //to return multiple values from a function just return a class object that will have the required return values as attributes
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

void insert_at_index(int index,node *head)
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
            }
        for(int i=0;i<index-1;i++)
            {
                temp = temp->next;
            }
        newdata->next = temp->next;
        temp->next = newdata;
        head->printLL(head);
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
                return head->next;
            }
        else 
            {
                node *temp_head;
                temp_head = recursive_delete(head->next,index-1);
                head->next = temp_head;
                return (head);
            }
    }
int find(node * head,int data)
    {
        node* temp = head;
        int index = 0;
        while (temp != NULL)
            {
                if(head->data == data)
                    {
                        return index;
                    }
                else
                    {
                        index ++;
                        temp = temp->next;
                    }
            }
        return -1;
    }

node* append(node * head, int index)
    {
        node* temp = head;
        node * tail = head;
        int i =0;
        while (temp->next != NULL)
            {
                if(i < index-1) 
                    {
                        tail = tail->next; 
                    }
                temp = temp->next;
                i++;
            }
        temp->next = head;
        head = tail->next;
        tail->next = NULL;
        return (head);
        
    }

void getmid(node * head, int index)
    {
        node * temp = head;
        for(int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        cout<<"mid element is: "<<temp->data<<endl;
    }

node* reverseLL_recursive(node* head)
    {
        //n^2 complexity
        if(head->next == NULL) 
            return head; 
        node * temp = reverseLL_recursive(head->next);
        node * last = temp;
        while (last->next != NULL) 
            {
                last = last->next;
            }
        last->next = head;
        head->next = NULL;
        return temp;
    }

hnt recursive_reverseLL_n(node* head) // not reversing for now dry-run and check
    {
        //lets maintain a tail pointer
        if (head->next != NULL) 
            {
                hnt ans;
                ans.head = head;
                ans.tail = head;//for length 1 head and tail are the same
                return ans;
            }
        hnt temp = recursive_reverseLL_n(head->next);
        temp.tail->next = head;
        head->next = NULL;

        hnt answer;
        answer.head = temp.head; 
        answer.tail = head;

        return answer;
    }
node * revll(node* head) //this function will return only the head 
    {
        return recursive_reverseLL_n(head).head;
    }
node* iterative_reverse(node* head) 
    {
        node * current = head;
        node * prev = NULL; 
        node * nxt = NULL;
        while(nxt != NULL)
            {
                nxt = current->next;
                current->next = prev;
                prev = current;
                current = nxt;
                nxt = nxt->next;
            }
        return current;
    }
int main()
    {
        // creating a menu is pending 
        node * head;
        node * tail;
        hnt p;
        int flag = 0;
        char ch = 'y';
        while(ch == 'y')
            {   
                cout<<"------Menu------\n1.Input LL\n2.Length\n3.Find Element\n4.Insert at index\n5.Delete at index\n6.Recursive Insert\n7.Recursive Delete\n8.Append N nodes\n9.Find midpoint\n10. Reverse LL (recursion n^2)\n11.Reverse LL (recursion n)\n12.Iterative reverse LL";
                int choice;
                int index;
                cin>>choice;
                
                if(choice>2)
                    {
                        if(flag ==  0)
                            {
                                head = userip();
                                flag = 1;
                            }
                        cout<<"enter index for operation: (-1 if not required)";
                        cin>>index;
                    }
                switch(choice)
                    {
                        case 1 :  
                                head = userip();
                                flag = 1;
                                break;
                        case 2 : 
                                cout<<recursive_length(head);
                                break;
                        case 3 : 
                                { 
                                    int data;
                                    cout<<"enter data to find";
                                    cin>>data;
                                    int index = find(head,data);
                                    if(index==-1)
                                        {
                                            cout<<"\nelement not found\n";
                                        }
                                    else 
                                        {
                                            cout<<"\nelement found at index : \n"<<index;
                                        }
                                }
                                break;
                        case 4 :
                                insert_at_index(index,head); 
                                break; 
                        case 5:  
                                delete_at_i(head,index);
                                break; 
                        case 6 : 
                                recursive_insert(head); 
                                break;
                        case 7 : 
                                recursive_delete(head,index);
                                break;
                        case 8 : 
                                {
                                    head = append(head,index);
                                    head->printLL(head);
                                    break;
                                }
                        case 9 : 
                            {
                                int mid = (recursive_length(head))/2;
                                getmid(head,mid);
                                break;
                            }
                        case 10:
                            {
                                head = reverseLL_recursive(head);
                                cout<<"\n current status of LL :";
                                head->printLL(head);
                                break;
                            }
                        case 11:
                            {
                                head = revll(head);
                                //head = p.head;
                                //tail = p.tail;
                                cout<<"\n current status of LL :";
                                head->printLL(head);
                                break;
                            }
                        case 12: 
                            {
                                head = iterative_reverse(head);
                                head->printLL(head);
                            }
                                 
                    }
                cout<<"\n do you want to perform more operations? (y/n)";
                cin>>ch;
            }
        //insert at a specific index 
        //int index;
        // //
        // cout<<"length of the LL is : "<<recursive_length(head);
        // // // if an element is inserted at index 0 then the head has to be updated
        // //head->printLL(head);
        // delete_at_i(head,index);
        // head->printLL(head);

        //head = recursive_insert(head);
        
        return 0;
    }