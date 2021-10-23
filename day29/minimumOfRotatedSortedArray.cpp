#include<iostream>
#include<vector>
#include<algorithm>

int findMin(vector<int>& nums) {
    return *min_element(nums.begin(), nums.end());
}

// 
int findMin(vector<int>& nums) {
    // return *min_element(nums.begin(), nums.end());
    if(nums.size()==1){
        return nums[0];
    }
    
    int low = 0, high = nums.size()-1;
    while(low<high){
        int mid = low + (high-low)/2;
        cout<<low<<","<<mid<<","<<high<<endl;
        // The array is already sorted
        // but it is rotated
        // but elements will be ordered only
        if(nums[mid] > nums[high]){
            // min element is to the right
            low = mid+1;
        }else if(nums[mid] < nums[high]){
            // min element is to the left
            high = mid;
        }else{
            high--;
        }
    }
return nums[high];
}

