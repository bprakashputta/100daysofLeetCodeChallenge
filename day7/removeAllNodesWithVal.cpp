#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x){
        val = x;
    }
};

ListNode* removeElements(ListNode* head, int val) {
    // If head is null return null
    if(head == NULL){
        return NULL;
    }
    
    ListNode* curr = head;
    ListNode* res = NULL;
    ListNode* ans = res;
    while(curr!=NULL){
        if(curr->val != val){
            if(ans == NULL){
                ans = new ListNode(curr->val);
                res = ans;
            }else{
                ans->next = new ListNode(curr->val);
                ans = ans->next;
            }
        }
        curr = curr->next;
    }
return res;
}
