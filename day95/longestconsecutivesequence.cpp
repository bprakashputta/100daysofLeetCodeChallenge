#include<iostream>
#include<vector>
#include<set>
#include<initializer_list>
using namespace std;

int longestConsecutiveSequence(vector<int> nums){
    set<int> numSet;
    for(auto num: nums){
        numSet.insert(num);
    }

    int mx_len=0, len=0;
    for(auto num: nums){
        if(!numSet.count(num-1)){
            int currNum = num-1;
            len = 1;
            while(numSet.count(currNum-1)){
                len += 1;
                currNum -= 1;
            }

            mx_len = max({len, mx_len});
        }
    }
return mx_len;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<longestConsecutiveSequence(nums)<<endl;
return 0;
}