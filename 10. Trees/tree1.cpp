#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// trees are a non linear data structure 
// file system is an example of tree data structure

//like the head node in LL  we will have the root node here 

class tree_node
    {
        //implementing a regular tree
        public:
            int data;
            vector<tree_node*> child;
        tree_node(int data) : data(data) {}
        
    };
void printTree(tree_node *root)
    {
        //there is no requirement of explicitly declaring a base case 

        //an edge case if root = NULL 
        if(root == NULL) return;
        cout<<endl<<root->data<<": "; 
        for(int i=0; i<root->child.size(); i++) 
            cout<<root->child[i]->data<<", "; // printing the children of the root node

        for(int i=0; i<root->child.size(); i++) 
            {
                //to get the no. of children 
                printTree(root->child[i]);//sending the next child as root 
            }
        
    }
tree_node* user_input()
    {
        int rootdata;
        cout<<"\nenter root data : ";
        cin>>rootdata;
        tree_node* root = new tree_node(rootdata);
        int children;
        cout<<"\nenter no. of children : ";
        cin>>children;
        for(int i = 0; i<children;i++)
            {
                tree_node * subroot;
                subroot = user_input();
                root->child.push_back(subroot);
            }
        return root;
        //in this input function giving the input is more complex than taking it 
    }
tree_node* level_input()
    {
        // we will have to use a queue
        // the queue will store the element that have been entered bu are waiting for their children input
        int rootdata;
        cout<<"\nenter root data : ";
        cin>>rootdata;
        tree_node* root = new tree_node(rootdata);
        
        
        //declaring a queue 
        queue<tree_node*> pending_nodes;
        pending_nodes.push(root);
        while(pending_nodes.size() != 0) 
            {
                tree_node* front = pending_nodes.front();
                pending_nodes.pop();
                int children;
                cout<<"\nenter no. of children : ";
                cin>>children;
                for(int i =0;i<children;i++)
                    {
                        int child_data;
                        cout<<"enter "<<i<<"th child : "<<;
                    }
            }
    }
int main()
    {  
        /*
        tree_node * root;
        tree_node * node1 = new tree_node(1);
        tree_node * node2 = new tree_node(2);
        tree_node * node3 = new tree_node(3);

        root = node1;

        root->child.push_back(node2);
        root->child.push_back(node3);  
        */

        // made      1 
        //          / \
        //         2   3
        //printTree(root);
        // prints 1 2 3 but we cannot be sure if it is right because even if the tree was declared like this 
        /*        1
                   \
                    2
                     \
                      3
        it would give the same result 
        lets print something like this 
        1 : 2, 3 --> 1 has two children 2 and 3 
        2 :      --> no children  
        3 :      --> no children
        */


       // Taking user input
        tree_node* root = user_input();
        printTree(root);

        return 0;
    }