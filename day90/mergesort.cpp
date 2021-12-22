class Solution {
public:
    vector<int> merge(vector<int> left, vector<int> right){
        vector<int> sorted;
        int i=0,j=0;
        while(i<left.size()&&j<right.size()){
            if(left[i]<=right[j]){
                sorted.push_back(left[i]);
                i++;
            }else {
                sorted.push_back(right[j]);
                j++;
            }
        }
        
        while(i<left.size()){
            sorted.push_back(left[i]);
            i++;
        }
        while(j<right.size()){
            sorted.push_back(right[j]);
            j++;
        }
    return sorted;
    }
    
    vector<int> sortA(vector<int> nums){
        if(nums.size()==1){
            return nums;
        }
        int mid = nums.size()/2;
        vector<int> lef(nums.begin(), nums.begin()+mid);
        vector<int> rig(nums.begin()+mid, nums.end());
        
        vector<int> left = sortA(lef);
        vector<int> right = sortA(rig);
        
        vector<int> sortedList = merge(left, right);
        return sortedList;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(), nums.end());   
        vector<int> arr=sortA(nums);
        for(int i=0; i<arr.size(); i++){
            nums[i] = arr[i];
        }
    return nums;
    }
};