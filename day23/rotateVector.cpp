#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force approach
// This results in TLE 
void rotate(vector<int>& nums, int k) {
    cout<<nums.size()<<endl;
    cout<<k<<endl;
    if(k >= nums.size()-1){
        k = nums.size()%k;
    }
    cout<<k<<endl;
    while(k>0){
        int temp = nums[nums.size()-1];
        for(int i=nums.size()-1; i>0; i--){
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
        k--;
    }
}

void rotate(vector<int>& nums, int k){
    if(k == nums.size()){
        return ;
    }
    if(k>nums.size()){
        int temp = k;
        k = k%nums.size();
    }

    // original [1,2,3,4,5,6,7]
    // k = 3
    // rotated [5,6,7,1,2,3,4]
    cout<<"K:"<<k<<endl;
    vector<int> temp; 
    for(int i=nums.size()-k; i<nums.size(); i++){
        temp.push_back(nums[i]);
    }
    for(int i=nums.size()-k-1; i>=0;i--){
        nums[i+k] = nums[i];
    }
    for(int i=0; i<k; i++){
        nums[i] = temp[i];
    }
}