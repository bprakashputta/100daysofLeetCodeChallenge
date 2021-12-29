class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> numSet;
        for(auto num: nums){
            numSet.insert(num);
        }
        int i=1;
        while(true){
            if(numSet.count(i)){
                i++;
            }else{
                return i;
            }
        }
    return i;
    }

    
    int firstMissing(int arr[], int n)
    {
        // Write your code here.
        for(int i=0; i<n; i++){
            if(nums[i]<=0){
                nums[i] = n+1;
            }
        }
        
        for(int i=0; i<n; i++){
            if(abs(nums[i])<=n && nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1] *= -1;
            }
        }
        
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                return i+1;
            }
        }
            
        return n+1;
    }
};