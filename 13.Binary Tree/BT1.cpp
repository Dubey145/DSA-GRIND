/* 
every node can have at most 2 children 

*/
#include<iostream>
using namespace std;

template<typename T>
class bt_node
    {
        public : 
        T data;

        bt_node<T> * left;
        bt_node<T> * right;
        // a constructor is also required because when we declare a node, data will be assigned but left and right pointers will store garbage
        bt_node(T data)
            {
                this->data = data;
                left = NULL;
                right = NULL;
            }

        ~bt_node();
            {
                delete left;
                delete right;
            }
    };

int main( )
    {
        bt_node<int> * root = new bt_node<int>(1);
        bt_node<int> * node1 = new bt_node<int>(2);
        bt_node<int> * node2 = new bt_node<int>(3);

        root->left = node1;
        root->right = node2;
    }

