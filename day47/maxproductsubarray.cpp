#include<iostream>
#include<vector>
#include<algorithm>
#include<initializer_list>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int xprod = 1, nprod = 1;
        int ans = *max_element(nums.begin(), nums.end());
        int mxprod = 1;
        int mnprod = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                mxprod = 1;
                mnprod = 1;
                continue;
            }
            int temp = mxprod * nums[i];
            mxprod = max({mxprod*nums[i], mnprod*nums[i], nums[i]});
            mnprod = min({temp, mnprod*nums[i], nums[i]});
            ans = max({mxprod, ans});
        }
    return ans;
    }
};