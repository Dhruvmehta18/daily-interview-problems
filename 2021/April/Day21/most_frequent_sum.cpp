/* Hi, here's your problem today. This problem was recently asked by LinkedIn:

Given a binary tree, find the most frequent subtree sum.

Example:

   3
  / \
 1   -3

The above tree has 3 subtrees. The root node with 3, and the 2 leaf nodes, which gives us a total of 3 subtree sums. The root node has a sum of 1 (3 + 1 + -3), the left leaf node has a sum of 1, and the right leaf node has a sum of -3. Therefore the most frequent subtree sum is 1.

If there is a tie between the most frequent sum, you can return any one of them.
*/

#include <iostream>
#include <unordered_map>
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

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    ~Node() {}
};

int _most_freq_subtree_sum(Node *root, unordered_map<int, int>& freq, unordered_map<int, int>& m)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = _most_freq_subtree_sum(root->left, freq, m);
    int right = _most_freq_subtree_sum(root->right, freq, m);
    int rootSum = left + right + root->data;
    if (freq.find(rootSum) == freq.end())
    {
        freq[rootSum] = 1;
        m[1] = rootSum;
    }
    else
    {
        freq[rootSum]++;
        m[freq[rootSum]] = rootSum;
    }
    return rootSum;
}

int most_freq_subtree_sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    unordered_map<int, int> freq;
    unordered_map<int, int> m;

    int rootSum = _most_freq_subtree_sum(root, freq, m);
    int maxFreq = 0;
    for (auto mi : m)
    {
        maxFreq = max(maxFreq, mi.second);
    }

    return maxFreq;
}

int main()
{
    Node *root = new Node(3, new Node(1), new Node(-3));
    cout << most_freq_subtree_sum(root) << endl;
    delete root;
    return 0;
}