#include<iostream>
using namespace std;

struct ListNode{
    int data;
    struct ListNode* next;
    ListNode(int x){
        data = x;
    }
};

ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* curr = head;
    ListNode* rev = NULL;
    ListNode* p = NULL;
    
    while(curr->next != NULL){
        p = curr->next;
        curr->next = rev;
        rev = curr;
        curr = p;
    }
    curr->next = rev;
return curr;
}