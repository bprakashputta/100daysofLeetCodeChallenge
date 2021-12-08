/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int size = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            curr = curr->next;
            size++;
        }
        curr = head;
        int res = 0;
        cout<<size<<endl;
        while(curr!=NULL){
            size--;
            res += curr->val * pow(2, size);
            cout<<"res:"<<res<<endl;
            curr = curr->next;
        }
    return res;
    }
};