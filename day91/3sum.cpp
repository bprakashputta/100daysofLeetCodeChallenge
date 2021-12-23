class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>trips;
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]<0){
                    left++;
                }else if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                }else{
                    s.insert({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }
            }
        }
        for(auto it:s){
            trips.push_back(it);
        }
    return trips;
    }
};