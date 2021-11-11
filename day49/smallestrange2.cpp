class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        // int mx = *max_element(nums.begin(), nums.end());
        // int mn = *min_element(nums.begin(), nums.end());
        if(nums.size()==1){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int res = nums[nums.size()-1]-nums[0];
        // Step 1: Keep aside the initial maxima and minima values
        int left = nums[0]+k;
        int right = nums[nums.size()-1]-k;
        // Iterate the array to check for other array elements too
        for(int i=0; i<nums.size()-1; i++){
            int mx = max({right, nums[i]+k});
            int mn = min({left, nums[i+1]-k});
            res = min({res, mx-mn});
        }
    return res;
    }
};