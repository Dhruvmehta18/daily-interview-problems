// Hi, here's your problem today. This problem was recently asked by Uber:

// Given a linked list, determine if the linked list has a cycle in it. For notation purposes, we use an integer pos which represents the zero-indexed position where the tail connects to.

// Example:
// Input: head = [4,3,2,1,0], pos = 1.  
// Output: true

#include <iostream>

using namespace std;

struct Node{
    int val;
    struct Node* next;
};

bool hasCycle(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL&&fast->next!=NULL&&slow!=fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast==NULL||fast->next==NULL){
        return false;
    } else{
        return true;
    }
}

int main(){
    Node* head = new Node();
    head->val = 4;
    Node* node1 = new Node();
    node1->val = 5;
    Node* node2 = new Node();
    node2->val = 3;
    Node* node3 = new Node();
    node3->val = 1;
    Node* node4 = new Node();
    node4->val = 10;
    node3->next = node4;
    node2->next = node3;
    node1->next = node2;
    head->next = node1;
    node4->next = head;
    cout<<hasCycle(head)<<endl;
    return 0;
}