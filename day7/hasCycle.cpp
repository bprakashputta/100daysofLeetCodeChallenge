#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int data;
    struct ListNode* next;
    ListNode(int x){
        data = x;
    }
};

bool hasCycle(ListNode *head) {
    // If head is null return false
    if(head==NULL){
        return false;
    }
    // if head has only one element return false
    if(head->next==NULL){
        return false;
    }
    // intialise two lists curr and nxt
    ListNode* curr = head;
    ListNode* nxt = head->next->next;
    // if nxt is null return false
    if(nxt==NULL){
        return false;
    }
    // iterating on the lists using while loop
    // with the following conditions and order is also important
    while(curr->next!=NULL || nxt->next != NULL || nxt->next->next !=NULL){
        // if curr and nxt are equal then return true, list has cycle
        if(curr==nxt){
            return true;
        }
        // move to next link
        curr = curr->next;
        // check if the list will be valid for the conditions
        // and break if it fails
        if(nxt == NULL || nxt->next == NULL || nxt->next->next==NULL){
            break;
        }else{
            nxt = nxt->next->next;
        }
    }
return false;
}

int main(){
    cout<<"Hi"<<endl;
return 0;
}