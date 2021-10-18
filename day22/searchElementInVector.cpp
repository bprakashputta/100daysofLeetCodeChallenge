#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    if(nums[0] > target){
        return 0;
    }
    if(nums[nums.size()-1] < target){
        return nums.size();
    }
    
    int l=0,r=nums.size()-1;
    int mid=0;
    int ans;
    while(l<=r){
        mid = l + (r-l)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            ans = mid;
            r = mid-1;
        }else{
            // ans = mid;
            l = mid + 1;
        }
    }
return ans;
}