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

    // Time complexity - O(nlogn)
    // Space Complexity - O(n)
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* curr = head;
        ListNode* ans=NULL;
        while(curr!=NULL){
            arr.push_back(curr->val);
            curr = curr->next;
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            if(curr==NULL){
                curr = new ListNode(arr[i]);
                ans = curr;
            }else{
                curr->next = new ListNode(arr[i]);
                curr = curr->next;
            }
        }
    return ans;
    }
};