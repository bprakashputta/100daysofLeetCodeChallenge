#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    sort(nums.begin(), nums.end());
    int num = 1;
    int n = nums.size();
    int i=1;
    while(i<nums[0]){
        ans.push_back(i);
        i++;
    }
    
    for(int i=0; i<nums.size(); i++){
        cout<<"nums[i]: "<<nums[i]<<endl;
    }
    for(int i=0; i<nums[nums.size()-1]-1; i++){
        cout<<"i:"<<i<<endl;
        if(nums[i]+1 < nums[i+1]){
            cout<<"for loop i:"<<i<<endl;
            for(int j=nums[i]+1; j<nums[i+1]; j++){
                cout<<"j:"<<j<<endl;
                ans.push_back(j);
            }
        }
    }
    
    i=nums[nums.size()-1]+1;
    while(i<=n){
        ans.push_back(i);
        i++;
    }
return ans;
}

// Optimal Code
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    
    for(int i=0; i<nums.size(); i++){
        // Get the index of the currth element
        int curr = abs(nums[i]);
        // Mark the currth index negative
        nums[curr-1] = -(abs(nums[curr-1]));
    }
    

    // now after iterating through the
    // array and marking elements negative,
    // if there is any index, whose value is positive,
    // then that index element is not there in the array.
    for(int i=0; i<nums.size(); i++){
        if(nums[i] > 0){
            res.push_back(i+1);
        }
    }
    
return res;
}