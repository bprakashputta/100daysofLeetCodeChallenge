#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int l1=0,l2=0, m=nums1.size(), n=nums2.size();
    vector<int> res;
    while(l1<m && l2<n){
        if(nums1[l1]==nums2[l2]){
            res.push_back(nums1[l1]);
            l1++;
            l2++;
        }else if(nums1[l1] > nums2[l2]){
            l2++;
        }else{
            l1++;
        }
    }
return res;
}

int main(){

}