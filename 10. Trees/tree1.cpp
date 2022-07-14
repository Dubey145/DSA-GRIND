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
        ~tree_node() 
            {
                //call delete on children, just like in the function 
                for(int i = 0; i < root->child.size();i++)
                    {
                        delete root->child[i];
                    }
            }
        
    };

void printTree(tree_node<int> *root)
    {
        //there is no requirement of explicitly declaring a base case because the code works as a base case, if we have just one child we do not print the values of its children as the first for loop condition fails

        //the second for loop condition also fails as there is no child

        //an edge case if root = NULL

        //this is pre order traversal
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
int height(tree_node<int> * root)
    {
        // getting the maximum height of this tree 
        int max_height = 0;
        int * sub_height = new int [root->child.size()];
        for(int i = 0; i < root->child.size(); i++)
            {
                sub_height[i] = 1 + height(root->child[i]);
            } 
        for(int i = 0; i < root->child.size(); i++)
            {
                if(max_height < sub_height[i])
                    {
                        max_height = sub_height[i];
                    }
            }
        return max_height;
    }
void nodes_at_depth(int depth,tree_node<int>* root)
    {
        //how far a node is from the root node
        //print all nodes at depth d or at level k 

        for(int i = 0; i < root->child.size(); i++)
            {
                if(depth == 1)
                    {
                        for(int i = 0; i < root->child.size();i++)
                            {
                                cout<<root->child[i]->data<<" ";
                            }
                        return;
                    }
                nodes_at_depth(depth-1,root->child[i]);
            }
 
    }
//better approach 
void level_print(tree_node<int>* root,int depth)
    {
        if(depth == 0)
            {
                cout<<root->data<<" ";
                return;
            }
        for(int i = 0; i < root->child.size();i++)
            {
               level_print(root->child[i],depth-1); 
            }
    }
int print_leaves(tree_node<int>* root)
    {
        int result = 0;
        if(root->child.size() == 0)
            {
                cout<<root->data<<" ";
                return 1;
            }
        for(int i = 0; i < root->child.size();i++)
            {
                result += print_leaves(root->child[i]); 
            }
        return result;
    }
//different printing 
void preorder(tree_node<int>* root)
    {
        cout<<root->data<<" ";
        for(int i = 0; i < root->child.size();i++)
            {
            preorder(root->child[i]);
            }
    }
void postorder(tree_node<int>* root)
    {
        if(root->child.size() == 0)
            {
                cout<<root->data<<" ";
                return;
            }
        for(int i = 0; i < root->child.size();i++)
            {
                postorder(root->child[i]); 
                cout<<root->data;
                return;
            }
    }
    
void delete_(tree_node<int>* root)
    {
        //we have to delete all the dynamically allocated nodes 
        //delete from he leaves
        cout<<root->data<<" Deleted\n";
        for(int i = 0; i < root->child.size();i++)
            {
                delete_(root->child[i]);   
            }
        delete root;
        //we would usually perform postorder deletion 
        //another way is to use the class destructor and just typind delete root
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
        int choice;
        cout<<"---------------MENU-----------------\n";
        cout<<"1.Number of nodes: \n";
        cout<<"2.Height of the tree: \n";
        cout<<"3.Nodes at a level \n";
        cout<<"4.Count leaf nodes: \n";
        cout<<"5.Pre order traversal\n";
        cout<<"6.Post order traversal\n";
        cout<<"7.Delete tree and exit\n";

        cin>>choice;
        switch(choice)
            {
                case 1: 
                    {
                        cout<<"\nNumber of nodes are : "<<count_nodes(root);
                        break;
                    }
                case 2: 
                    {
                        cout<<"\nHeight of the tree is : "<<height(root)+1;
                        break;
                    }
                case 3: 
                    {
                        int depth = 0;
                        cout<<"enter the depth : ";
                        cin>>depth;
                        cout<<"the nodes at this depth are : ";
                        level_print(root,depth);
                        break;
                    }
                case 4: 
                    {
                        cout<<"leaves are :";
                        int result = print_leaves(root); 
                        cout<<"\nnumber of leaves : "<<result<<endl;
                        break;
                    }
                case 5 : 
                    {
                        preorder(root);
                        break;
                    }
                case 6 :    
                    {
                        //to implement
                    }
                case 7 : 
                    {   
                        delete_(root);
                    }
            }
        
        
        return 0;
    }