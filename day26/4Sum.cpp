#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// This is brute force approach
vector<vector<int>> 4Sum(vector<int> nums, int target){
    vector<vector<int>> pairs;
    if(nums.empty()){
        return pairs;
    }
    set<vector<int>> st;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size(); k++){
                int req = target - nums[i]-nums[j]-nums[k];
                int l = k+1;
                int r=nums.size()-1;
                while(l<=r){
                    int mid = l+(r-l)/2;
                    if(nums[mid]==req){
                        cout<<i<<j<<k<<mid<<endl;
                        st.insert({nums[i],nums[j],nums[k],nums[mid]});
                        l++;
                        r--;
                    }else if(nums[mid]>req){
                        r = mid-1;
                    }else{
                        l = mid+1;
                    }
                }
            }
        }
    }

    for(auto it:st){
        pairs.push_back(it);
    }
return pairs;
}


// Optimised Approach
// You can further optimise this approach to 
// skip duplicate values
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> pairs;
    set<vector<int>> st;
    sort(nums.begin(), nums.end());
    int ip=-1, jp=-1, lp=-1, rp=-1;
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            // if(jp!=-1/)
            int req = target - nums[i]-nums[j];
            int l = j+1;
            int r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r] == req){
                    st.insert({nums[i],nums[j],nums[l],nums[r]});
                    l++;
                    r--;
                }else if(nums[l]+nums[r] > req){
                    r--;
                }else{
                    l++;
                }
            }
        }
    }

    for(auto it:st){
        pairs.push_back(it);
    }
return pairs;
}


// If i optimised the duplicates,
// I am getting TLE on LeetCode
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> pairs;
    set<vector<int>> st;
    sort(nums.begin(), nums.end());
    int ip=-1, jp=-1, lp=-1, rp=-1;
    for(int i=0; i<nums.size(); i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        for(int j=i+1; j<nums.size(); j++){
            // if(jp!=-1/)
            if(j>i+1 && nums[j]==nums[j-1])continue;
            int req = target - nums[i]-nums[j];
            int l = j+1;
            int r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r] == req){
                    st.insert({nums[i],nums[j],nums[l],nums[r]});
                    // pairs.push_back({nums[i],nums[j],nums[l],nums[r]});
                    // lp = nums[l];
                    // rp = nums[r];
                    l++;
                    r--;
                }else if(nums[l]+nums[r] > req){
                    // lp = nums[l];
                    // rp = nums[r];
                    r--;
                }else{
                    // lp = nums[l];
                    // rp = nums[r];
                    l++;
                }
            }
            // Processing Duplicates of j
            // while(j+1<nums.size() && nums[j+1]==nums[j]){
            //     j++;
            // }
        }
        // Processing Duplicates of i
        // while(i+1<nums.size() && nums[i+1]==nums[i]){
        //         i++;
        // }
    }

    for(auto it:st){
        pairs.push_back(it);
    }
return pairs;

}
};

