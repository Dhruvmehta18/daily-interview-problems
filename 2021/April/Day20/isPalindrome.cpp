// Hi, here's your problem today. This problem was recently asked by Microsoft:

// You are given a doubly linked list. Determine if it is a palindrome.

// Can you do this for a singly linked list?

#include<iostream>

using namespace std;

class DoublyNode{
    public:
        char letter;
        DoublyNode* next;
        DoublyNode* prev;
        DoublyNode(char data){
            this->letter = data;
            this->next = NULL;
            this->prev = NULL;
        }
        DoublyNode(char data, DoublyNode* prev, DoublyNode* next){
            this->letter = data;
            this->prev = prev;
            this->next = next;
        }

        ~DoublyNode();
};

pair<bool, DoublyNode*> getMidNode(DoublyNode* node){
    if(!node){
        return make_pair(false, node);
    }

    DoublyNode* slow = node;
    DoublyNode* fast = node;

    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return make_pair(fast!=NULL, slow);
}

bool isPalindrome(DoublyNode* node){
    if(node==NULL||node->next==NULL){
        return true;
    }
    pair<bool, DoublyNode*> midNode = getMidNode(node);

    if(midNode.second==NULL){
        return false;
    }

    DoublyNode* left = NULL;
    DoublyNode* right = NULL;

    if(midNode.first){
        left = midNode.second->prev;
        right = midNode.second->next;
    } else{
        left = midNode.second->prev;
        right = midNode.second;
    }

    while(left!=NULL&&left->letter==right->letter){
        left = left->prev;
        right = right->next;
    }

    return left==NULL;
}

int main(){
    DoublyNode* node = new DoublyNode('a');
    node->next = new DoublyNode('b');
    node->next->prev = node;
    node->next->next = new DoublyNode('b');
    node->next->next->prev = node->next;
    node->next->next->next = new DoublyNode('a');
    node->next->next->next->prev = node->next->next;
    cout<<isPalindrome(node);
    delete node;
    return 0;
}