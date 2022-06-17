#include<iostream>
#include<vector>
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

int main()
    {  
        tree_node * root;
        tree_node * node1 = new tree_node(1);
        tree_node * node2 = new tree_node(2);
        tree_node * node3 = new tree_node(3);

        node1->child.push_back(node1);
        node2->child.push_back(node2);

        // made      1 
        //          / \
        //         2   3
        return 0;
    }