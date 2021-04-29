// Hi, here's your problem today. This problem was recently asked by Amazon:

// Given a number n, generate all binary search trees that can be constructed with nodes 1 to n.

// Here's some code to start with:

/* Pre-order traversals of binary trees from 1 to n.
 123
 132
 213
 312
 321
   1      1      2      3      3
    \      \    / \    /      /
     2      3  1   3  1      2
      \    /           \    /
       3  2             2  1
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
    }

    Node(int data, Node *left, Node *right)
    {
        this->value = data;
        this->left = left;
        this->right = right;
    }

    ~Node();

    void printInorder()
    {
        stack<Node *> nodes;
        Node *curr = this;
        while (curr!=NULL || !nodes.empty())
        {
            while (curr != NULL)
            {
                nodes.push(curr);
                curr = curr->left;
            }
            curr = nodes.top();
            nodes.pop();
            cout << curr->value << " ";
            curr = curr->right;
        }
        cout << endl;
    }

    void printPreOrder(){
        stack<Node *> nodes;
        Node *curr = this;
        while (curr!=NULL || !nodes.empty())
        {
            while (curr != NULL)
            {
                cout << curr->value << " ";
                nodes.push(curr);
                curr = curr->left;
            }
            curr = nodes.top();
            nodes.pop();
            curr = curr->right;
        }
        cout << endl;
    }
};

void printBstList(vector<Node *> bsts)
{
    for (auto bst : bsts)
    {
        bst->printPreOrder();
    }
}

vector<Node *> _generateBst(int start, int end)
{
    vector<Node *> list;

    if (start > end)
    {
        list.push_back(NULL);
        return list;
    }

    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubTree = _generateBst(start, i - 1);
        vector<Node *> rightSubTree = _generateBst(i + 1, end);

        for (int j = 0; j < leftSubTree.size(); j++)
        {
            Node *left = leftSubTree[j];
            for (int k = 0; k < rightSubTree.size(); k++)
            {
                Node *right = rightSubTree[k];
                Node *root = new Node(i, left, right);
                list.push_back(root);
            }
        }
    }

    return list;
}

vector<Node *> generateBst(int n)
{
    return _generateBst(1, n);
}

int main()
{
    int n = 3;
    printBstList(generateBst(n));
    return 0;
}