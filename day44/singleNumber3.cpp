#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]==1){
                res.push_back(nums[i]);
            }
        }
    return res;
    }
};