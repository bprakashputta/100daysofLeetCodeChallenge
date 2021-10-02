#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x){
        val = x;
    }
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // check if any of l1,l2 is null
    if(l1==NULL){
        return l2;
    }else if(l2==NULL){
        return l1;
    }

    ListNode* l3 = NULL;
    ListNode* res = l3;
    while(l1!=NULL && l2!=NULL){
        if(l1->val<=l2->val){
            // if l3 is null
            if(l3==NULL){
                l3 = new ListNode(l1->val);
                res = l3;
            }else{
                l3->next = new ListNode(l1->val);
                l3 = l3->next;
            }
            l1 = l1->next;
        }else{
            // if l3 is null
            if(l3==NULL){
                l3 = new ListNode(l2->val);
                res = l3;
            }else{
                l3->next = new ListNode(l2->val);
                l3 = l3->next;
            }
            l2 = l2->next;                
        }
    }

    // while l1 is not equal to null
    while(l1!=NULL){
        l3->next = new ListNode(l1->val);
        l3 = l3->next;
        l1 = l1->next;
    }
    // while l2 is not equal to null
    while(l2!=NULL){
        l3->next = new ListNode(l2->val);
        l3 = l3->next;
        l2 = l2->next;
    }
return res;
}

