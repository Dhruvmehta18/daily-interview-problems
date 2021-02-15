/*Hi, here's your problem today. This problem was recently asked by Twitter:

You are given the root of a binary tree. Find the level for the binary tree with the minimum sum, and return that value.

For instance, in the example below, the sums of the trees are 10, 2 + 8 = 10, and 4 + 1 + 2 = 7. So, the answer here should be 7.

     10
    /  \
   2    8
  / \    \
 4   1    2
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
};

pair<int, vector<Node*>> getSumStack(vector<Node *> v)
{
    vector<Node *> ans;
    int sum = 0;
    for (Node *node : v)
    {
        Node *leftNode = node->left;
        Node *rightNode = node->right;
        if (leftNode != NULL)
        {
            sum += leftNode->data;
            ans.push_back(leftNode);
        }
        if (rightNode != NULL)
        {
            sum += rightNode->data;
            ans.push_back(rightNode);
        }
    }
    return make_pair(sum, ans);
}

pair<int, vector<Node*>> getMinSumStack(pair<int, vector<Node*>> p){
    pair<int, vector<Node*>> ans = getSumStack(p.second);
    if(ans.second.size()==0){
        ans.first = p.first;
        return ans;
    }
    ans.first = min(p.first, ans.first);
    return getMinSumStack(ans);
}

int getMinSum(pair<int, vector<Node*>> p){
    return getMinSumStack(p).first;
}

int minimumLevelSum(Node *root)
{
    vector<Node *> st;
    int minSum = root->data;
    st.push_back(root);
    return getMinSum(make_pair(minSum, st));
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(1);
    root->right->right = new Node(2);
    cout << minimumLevelSum(root) << endl;
    return 0;
}