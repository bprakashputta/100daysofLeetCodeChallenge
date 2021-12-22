#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Approach using a new List 
ListNode* reorderList(ListNode* head) {
    // Step 1 : Find middle of List
    if(head==NULL||head->next==NULL){
        return head;
    }
    cout<<"HI"<<endl;
    ListNode* slow = head;
    ListNode* fast = head->next;
    ListNode* left = slow;
    
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow;
    slow->next = NULL;

    // Step 2 : Reverse the second half list
    ListNode* rev = NULL;
    ListNode* temp = NULL;
    while(mid!=NULL){
        temp = mid;
        mid = mid->next;
        temp->next = rev;
        rev = temp;
    }
    // printList(rev);
    // Step 3 : Merge both halves in turns
    ListNode* curr = NULL;
    ListNode* middle = rev;
    cout<<"Left: ";
    printList(left);
    cout<<"Middle: ";
    printList(middle); 
    ListNode* newList = curr;
    while(middle!=NULL && left!=NULL){
        if(curr==NULL){
            curr = new ListNode(left->val);
            newList = curr;
            curr->next = new ListNode(middle->val);
            curr = curr->next;
            middle = middle->next;
            left = left->next;
        }else{
            curr->next = new ListNode(left->val);
            curr = curr->next;
            curr->next = new ListNode(middle->val);
            curr = curr->next;
            middle = middle->next;
            left = left->next;
        }
    }

    while(left!=NULL){
        curr->next = new ListNode(left->val);
        curr = curr->next;
        left = left->next;
    }
    while(middle!=NULL){
        curr->next = new ListNode(middle->val);
        curr = curr->next;
        middle = middle->next;
    }
// head = newList;
return newList;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* list = head;
    head->next = new ListNode(2);
    head = head->next;
    head->next = new ListNode(3);
    head = head->next;
    head->next = new ListNode(4);
    head = head->next;
    // head->next = new ListNode(0);
    // head = head->next;
    // head->next = new ListNode(6);
    // head = head->next;
    // head->next = new ListNode(3);
    // head = head->next;
    // head->next = new ListNode(5);
    // head = head->next;
    // head->next = new ListNode(19);
    // head = head->next;
    cout<<"Original : ";
    printList(list);
    ListNode* curr = reorderList(list);
    cout<<"Reordered : "<<endl;
    printList(curr);
return 0;
}