#include<iostream>
using namespace std;

struct ListNode{
    int data;
    struct ListNode* next;
    ListNode(int x){
        data = x;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL){
        return head;
    }
    ListNode* curr = head;
    while(curr->next!=NULL){
        if(curr->data == curr->next->data){
            curr->next = curr->next->next;
        }else{
            curr = curr->next;
        }
    }
return head;
}

