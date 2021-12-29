#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> twoSum(vector<int>& nums, int target, int n)
{
	// Write your code here. 
    int left=0, right=n-1;
    vector<pair<int,int>>pairs;
    int i=0;
    while(left<right){
        if(nums[left]+nums[right] > target){
            right--;
        }else if(nums[left]+nums[right] < target){
            left++;
        }else{
            pairs.resize(i + 1);
            pairs[i] = {nums[left], nums[right]};
            i++;
            left++;
            right--;
        }
    }
    // for(auto it: pairs){
    //     cout<<it.first<<","<<it.second<<endl;
    // }
return pairs;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<pair<int,int>> ans = twoSum(arr, target, n);
    for(auto it: ans){
        cout<<it.first<<","<<it.second<<endl;
    }

return 0;
}