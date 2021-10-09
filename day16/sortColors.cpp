#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        int i=0;
        while(i<=r){
            if(arr[i]==0){
                int temp = arr[i];
                arr[i] = arr[l];
                arr[l] = temp;
                i++;
                l++;
            }else if(arr[i]==2){
                int temp = arr[r];
                arr[r] = arr[i];
                arr[i] = temp;
                r--;
            }else{
                i++;
            }
        }
    }
};