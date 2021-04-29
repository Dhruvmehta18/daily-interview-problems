// Hi, here's your problem today. This problem was recently asked by Amazon:

// Given a binary tree and a given node value, return all of the node's cousins. Two nodes are considered cousins if they are on the same level of the tree with different parents. You can assume that all nodes will have their own unique value.

/*   1
    / \
   2   3
  / \   \
 4   6   5
[4, 6]
*/

#include <iostream>
#include <vector>
#include <queue>

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
        this->left = NULL;
        this->right = NULL;
    }

    Node(int value, Node *left, Node *right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

void printVector(const vector<Node*> v){
    for(auto node : v){
        cout<<node->value<<" ";
    }
    cout<<endl;
}

vector<Node *> listCousin(Node *root, Node *node)
{
    vector<Node *> ans;
    queue<Node *> q;
    bool found = false;
    q.push(root);
    while (!q.empty() && !found)
    {
        int size = q.size();
        while (size)
        {
            Node *p = q.front();
            q.pop();
            // cout << p->value << " ";
            if (p->left == node || p->right == node)
            {
                found = true;
            }
            else
            {
                if (p->left != NULL)
                {
                    q.push(p->left);
                }

                if (p->right != NULL)
                {
                    q.push(p->right);
                }
            }

            size--;
        }
    }

    if (found)
    {
        int size = q.size();

        if (size == 0)
        {
            return ans;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                ans.push_back(q.front());
                q.pop();
            }
            return ans;
        }
    }
    else
    {
        return ans;
    }
}
void deallocate (Node * p)
{
    if(p==NULL)
        return;

    deallocate(p->right);
    deallocate(p->left);

    delete p;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(15);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    
    printVector(listCousin(root, root->left->right));

    deallocate(root);

    return 0;
}