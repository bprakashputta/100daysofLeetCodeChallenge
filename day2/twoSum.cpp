#include<iostream>
#include<vector>
using namespace std;

// given a sorted array
// and a target element
// return a vector containing
// the indices of the 2 elements 
// whose sum is equal to target

vector<int> twoSum(vector<int> nums, int target){
    vector<int> ans(2);
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i] + nums[j] == target){
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
return ans;
}

// this method will only work when
// the given array is sorted already
// else it wont
vector<int> twoSum(vector<int> nums, int target){
    int l=0, r=nums.size()-1;
    vector<int> ans(2);
    while(l<r){
        int sum = nums[l]+nums[r];
        if(sum>target){
            r--;
        }else if(sum<target){
            l++;
        }else{
            ans[0] = l;
            ans[1] = r;
            break;
        }
    }
return ans;
}