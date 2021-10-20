#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> pairs;
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    for(int i=0; i<nums.size(); i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        int req = (-1)*nums[i];
        int l = i+1;
        int r = nums.size()-1;
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum==req){
                st.insert({nums[i],nums[l],nums[r]});
                l++;
                r--;
            }else if(sum>req){
                r--;
            }else{
                l++;
            }
        }
    }
    
    for(auto it:st){
        pairs.push_back(it);
    }
return pairs;
}
