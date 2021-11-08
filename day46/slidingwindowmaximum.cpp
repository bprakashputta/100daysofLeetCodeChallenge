#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        int l=0;
        int r=k-1;
        int mx=INT_MIN;
        for(int i=l; i<=r; i++){
            if(mx<=nums[i]){
                mx = nums[i];
            }
        }
        if(k==nums.size()){
            return {mx};
        }
        
        vector<int> res;
        while(r<nums.size()-1){
            res.push_back(mx);
            if(nums[r+1]>mx){
                r++;
                l++;
                mx = nums[r];
            }else{
                mx = INT_MIN;
                for(int i=l+1; i<=r+1; i++){
                   if(mx<=nums[i]){
                        mx = nums[i];
                    } 
                }
                l++;
                r++;
            }
        }
    res.push_back(mx);
    return res;
    }
};