#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    map<int,int>mp;
    vector<int> res;
    map<int,int> ans;
    int p=1;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        mp[nums[i]]++;
        if(mp[nums[i]] > (nums.size()/3)){
            ans[nums[i]] = p; 
        }
    }
    
    for(auto it:ans){
        res.push_back(it.first);
    }
return res;
}

vector<int> majorityElement(vector<int>& nums){
    vector<int> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=n/3; i<n; i+(n/3)){
        if(nums[i] == nums[i-1] ){
            res.push_back(nums[i]);
        }
    }
return res;
}


vector<int> majorityElement(vector<int>& nums){
    // Bayer Moore's Voting Algorithm
    int count1=0, count2=0,num1=INT_MIN,num2=INT_MIN;
    for(int i=0; i<nums.size(); i++){
        int ele = nums[i];
        if(ele==num1){
            count1++;
        }else if(ele==num2){
            count2++;
        }else if(count1==0){
            num1 = ele;
            count1=1;
        }else if(count2==0){
            num2=ele;
            count2=1;
        }else{
            count1--;
            count2--;
        }
    }
    cout<<"num1:"<<num1<<endl;
    cout<<"num2:"<<num2<<endl;
    count1=0,count2=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==num1){
            count1++;
        } 
        if(nums[i]==num2){
            count2++;
        }
    }
    vector<int> ans;
    if(count1>nums.size()/3){
        ans.push_back(num1);
    }
    if(count2>nums.size()/3){
        if(num1 != num2){
            ans.push_back(num2);
        }
    }
return ans;
}