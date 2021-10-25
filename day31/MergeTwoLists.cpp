struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL){
            return NULL;
        }else if(l1!=NULL && l2==NULL){
            return l1;
        }else if(l1==NULL && l2!=NULL){
            return l2;
        }
        
        ListNode* merg = NULL;
        ListNode* ans = NULL;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                if(merg == NULL){
                    merg = new ListNode(l1->val);
                    ans = merg;
                }else{
                    merg->next = new ListNode(l1->val);
                    merg = merg->next;
                }
                l1 = l1->next;
            }else{
                if(merg == NULL){
                    merg = new ListNode(l2->val);
                    ans = merg;
                }else{
                    merg->next = new ListNode(l2->val);
                    merg = merg->next;
                }
                l2 = l2->next;
            }
        }
        
        while(l1!=NULL){
            merg->next = new ListNode(l1->val);
            merg = merg->next;
            l1 = l1->next;
        }
        
        while(l2!=NULL){
            merg->next = new ListNode(l2->val);
            merg = merg->next;
            l2 = l2->next;
        }
    return ans;
    }
};