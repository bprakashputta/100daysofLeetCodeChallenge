struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        
        ListNode* rev = NULL;
        ListNode* temp = head;
        ListNode* curr = head;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = rev;
            rev = curr;
            curr = temp;
        }
        // if(rev!=NULL){
        //     head = rev;
        // }
    return rev;
    }
};