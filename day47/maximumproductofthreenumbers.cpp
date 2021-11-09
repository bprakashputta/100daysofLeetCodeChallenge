#include<iostream>
#include<vector>
#include<initializer_list>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int mx = max({nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]});
        return mx;
    }
};