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
    int countNodes(ListNode* head){
        int count=0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
    return count;
    }
    
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int count = countNodes(head);
        int pos=count/2;
        while(pos>0){
            pos--;
            head = head->next;
        }
    return head;
    }
};