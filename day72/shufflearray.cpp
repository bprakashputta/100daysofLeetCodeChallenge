#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> a1(n);
        vector<int> a2(n);
        for(int i=0; i<n; i++){
            a1[i] = nums[i];
        }
        for(int i=n; i<2*n; i++){
            a2[i-n] = nums[i]; 
        }
        int p=0,q=0;
        for(int i=0; i<2*n; i++){
            if(i%2==0){
                nums[i] = a1[p];
                p++;
            }else{
                nums[i] = a2[q];
                q++;
            }
        }
    return nums;
    }
};