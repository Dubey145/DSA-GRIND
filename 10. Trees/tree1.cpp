#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// trees are a non linear data structure 
// file system is an example of tree data structure
 
//like the head node in LL  we will have the root node here 
template <typename T>
class tree_node
    {
        //implementing a regular tree
        public:
            T data;
            vector<tree_node<T>*> child; // tree node of type T
        tree_node(T data) : data(data) {}
        
    };
void printTree(tree_node<int> *root)
    {
        //there is no requirement of explicitly declaring a base case because the code works as a base case, if we have just one child we do not print the values of its children as the first for loop condition fails

        //the second for loop condition also fails as there is no child

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
//level order printing 
void level_print(tree_node<int>* root)
    {
        queue<tree_node<int>*> pending_nodes;
        pending_nodes.push(root);

        while(pending_nodes.size() != 0)    
            {
                tree_node<int>* front = pending_nodes.front();
                cout<<front->data<<" : ";
                pending_nodes.pop(); 

                for(int i = 0; i < front->child.size(); i++) 
                    {
                        cout<<front->child[i]->data<<" ";
                        pending_nodes.push(front->child[i]);
                    }
                cout<<endl;
            }

    }
tree_node<int>* user_input()
    {
        int rootdata;
        cout<<"\nenter root data : ";
        cin>>rootdata;
        tree_node<int>* root = new tree_node<int>(rootdata);
        int children;
        cout<<"\nenter no. of children : ";
        cin>>children;
        for(int i = 0; i<children;i++)
            {
                tree_node<int> * subroot;
                subroot = user_input();
                root->child.push_back(subroot);
            }
        return root;
        //in this input function, giving the input is more complex than taking it 
    }
tree_node<int>* level_input()
    {
        //process elements the way they are coming
        // we will have to use a queue
        // the queue will store the element that have been entered bu are waiting for their children input
        int rootdata;
        cout<<"\nenter root data : ";
        cin>>rootdata;
        tree_node<int>* root = new tree_node<int>(rootdata);
        
        
        //declaring a queue 
        queue<tree_node<int>*> pending_nodes; // this queue stores those elements whose children are yet to come

        pending_nodes.push(root);
        while(pending_nodes.size() != 0) 
            {
                tree_node<int>* front = pending_nodes.front();
                pending_nodes.pop(); 
                int children;
                cout<<"\nenter no. of children of "<<front->data<<": ";
                cin>>children;
                for(int i =0;i<children;i++)
                    {
                        int child_data;
                        cout<<"enter "<<i<<"th child of "<<front->data<<": ";
                        cin>>child_data;
                        tree_node<int> *Child = new tree_node<int>(child_data);
                        front->child.push_back(Child);
                        pending_nodes.push(Child);
                    }
            }
        return root;
    }
int count_nodes(tree_node<int> *root)
    {
        int ans = 1;
        for(int i = 0; i < root->child.size(); i++)
            {
                ans+=count_nodes(root->child[i]);
            }
        return ans;
    }
int main()
    {  
        /*
        tree_node<int> * root;
        tree_node<int> * node1 = new tree_node<int>(1);
        tree_node<int> * node2 = new tree_node<int>(2);
        tree_node<int> * node3 = new tree_node<int>(3);

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
       //tree_node<int>* root = user_input();
        
        tree_node<int>* root = level_input();
        level_print(root);
        cout<<"\n number of nodes are : "<<count_nodes(root);
        return 0;
    }