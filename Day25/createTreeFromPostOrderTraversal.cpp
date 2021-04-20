// Hi, here's your problem today. This problem was recently asked by Uber:

// Given a postorder traversal for a binary search tree, reconstruct the tree. A postorder traversal is a traversal order where the left child always comes before the right child, and the right child always comes before the parent for all nodes.

#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;


class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

        Node(int data, Node* left, Node* right){
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

void createTreeFromPostOrderTraversal(vector<int> node_datas){
    for(int node_data: node_datas){
        
    }
}

int main(){
    
    return 0;
}