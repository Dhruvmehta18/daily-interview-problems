// Hi, here's your problem today. This problem was recently asked by Microsoft:

// Given the root of a binary tree, print its level-order traversal. For example:

// The following tree should output 1, 2, 3, 4, 5.

/* 1
 / \
2   3
   / \
  4   5
  */

#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    Node(int data, Node *left, Node *right){
        this->data = data;
        this->left = left;
        this->right = right;
    }

    ~Node(){

    }
};

void _printLevelOrder(queue<Node *> q)
{
    while (!q.empty())
    {
        Node *p = q.front();
        cout << p->data << " ";

        if (p->left != NULL)
        {
            q.push(p->left);
        }

        if (p->left != NULL)
        {
            q.push(p->right);
        }
        q.pop();
    }
}

void printLevelOrder(Node *root)
{
    queue<Node*> q;
    q.push(root);
    _printLevelOrder(q);
}

int main()
{
    Node* root = new Node(1, new Node(2), new Node(3, new Node(4), new Node(5)));
    printLevelOrder(root);
    delete(root);
    return 0;
}