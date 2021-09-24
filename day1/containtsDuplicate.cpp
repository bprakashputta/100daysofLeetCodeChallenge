#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i] == nums[i+1]){
            return true;
        }
    }
return false;
}

bool containsDuplicate(vector<int>& nums) {
    map<int,int> m;
    for(int i=0; i<nums.size(); i++){
        m[nums[i]]++;
    }
    
    for(int i=0; i<nums.size(); i++){
        if(m[nums[i]] > 1){
            return true;
        }
    }
return false;
}

int main(){

return 0;   
}