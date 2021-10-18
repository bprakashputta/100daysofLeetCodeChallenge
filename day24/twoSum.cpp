#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int l=0, r=nums.size()-1;
    vector<int> ans;
    while(l<r){
        if(nums[l]+nums[r] == target){
            ans.push_back(l+1);
            ans.push_back(r+1);
            break;
        }else if(nums[l]+nums[r] < target){
            l++;
        }else{
            r--;
        }
    }
return ans;
}