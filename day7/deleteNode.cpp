#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x){
        val = x;
    }
};

// Delete a particular node when, 
// the node is given directly.
void deleteNode(ListNode* node) {
    // copy value of next node to current node
    node->val=node->next->val;
    // delete next node now
    ListNode* temp = node->next;
    node->next = temp->next;
    delete temp;
}

// Same logic in a direct way
void deleteNode(ListNode* node) {
    node->val=node->next->val;
    node->next = node->next->next;
}