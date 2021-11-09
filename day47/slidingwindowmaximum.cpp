#include<iostream>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int>dq;
        for(int i=0; i<nums.size(); i++){
            // Step 1
            // Remove all the indices that are not in the range i-k to i
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            // Remove all the elements that are smaller than the maximum from deque
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            // push the index of current element to deque
            dq.push_back(i);
            if(i>=k-1){
                
                ans.push_back(nums[dq.front()]);
            }
        }
    return ans;
    }
};