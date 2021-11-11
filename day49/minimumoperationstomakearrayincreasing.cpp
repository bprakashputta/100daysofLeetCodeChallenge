class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                continue;
            }else{
                int temp = nums[i];
                nums[i] = nums[i-1]+1;
                ops += nums[i]-temp;
            }
        }
    return ops;
    }
};