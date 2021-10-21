#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getCount(ListNode* head){
        int count=0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
    return count;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        int count = getCount(head);
        if(count < n){
            return head;
        }else if(count==n){
            return head->next;
        }
        
        int pos = count-n;
        ListNode* curr = head;
        while(pos > 1){
            curr = curr->next;
            pos--;
        }
        curr->next = curr->next->next;
    return head;
    }
};
