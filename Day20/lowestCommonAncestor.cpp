// Hi, here's your problem today. This problem was recently asked by Apple:

// You are given the root of a binary tree, along with two nodes, A and B. Find and return the lowest common ancestor of A and B. For this problem, you can assume that each node also has a pointer to its parent, along with its left and right child.

#include<iostream>
#include<string>

using namespace std;

class TreeNode{
    private:
        int _getLevel(TreeNode* node){
            if(node->parent==NULL){
                return 1;
            }
            return 1 + _getLevel(node->parent);
        }
    public:
        string data;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        TreeNode(string val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
        }

        ~TreeNode(){
        }

        int getLevel(){
            return _getLevel(this);
        }
};

void printNode(TreeNode* node){
    if(node==NULL){
        cout<<"Node is Null"<<endl;
    }else{
        cout<<node->data<<endl;
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
    int aLevel = a->getLevel();
    int bLevel = b->getLevel();

    int diffLevel = abs(aLevel - bLevel);

    TreeNode* maxLevelNode = aLevel > bLevel ? a : b;
    TreeNode* minLevelNode = aLevel < bLevel ? a : b;
    while(diffLevel>0){
        maxLevelNode = maxLevelNode->parent;
        diffLevel--;
    }

    while(maxLevelNode!=NULL&&minLevelNode!=NULL&&maxLevelNode!=minLevelNode){
        maxLevelNode = maxLevelNode->parent;
        minLevelNode = minLevelNode->parent;
    }

    return maxLevelNode;
}

int main(){
    TreeNode *root = new TreeNode("a");
    root->left = new TreeNode("b");
    root->left->parent = root;
    root->right = new TreeNode("c");
    root->right->parent = root;
    root->right->left = new TreeNode("d");
    root->right->left->parent = root->right;
    root->right->right = new TreeNode("e");
    root->right->right->parent = root->right;
    root->right->left->right = new TreeNode("f");
    root->right->left->right->parent = root->right->left;
    TreeNode* a = root->right->left->right;
    TreeNode* b = root->left;
    printNode(lowestCommonAncestor(root, a, b));

    return 0;
}